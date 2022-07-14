<?php

namespace Drupal\farm_maple\Plugin\QuickForm;

use Drupal\Component\Datetime\TimeInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Messenger\MessengerInterface;
use Drupal\farm_quick\Plugin\QuickForm\QuickFormBase;
use Drupal\farm_quick\Traits\QuickLogTrait;
use Drupal\farm_quick\Traits\QuickStringTrait;
use Psr\Container\ContainerInterface;

/**
 * Maple sap harvest quick form.
 *
 * @QuickForm(
 *   id = "maple_sap",
 *   label = @Translation("Maple sap harvest"),
 *   description = @Translation("Record maple sap harvest."),
 *   helpText = @Translation("This form will create a harvest log to represent the collection of maple sap."),
 *   permissions = {
 *     "create harvest log",
 *   }
 * )
 */
class MapleSap extends QuickFormBase {

  use QuickLogTrait;
  use QuickStringTrait;

  /**
   * The entity type manager service.
   *
   * @var \Drupal\Core\Entity\EntityTypeManagerInterface
   */
  protected $entityTypeManager;

  /**
   * The time service.
   *
   * @var \Drupal\Component\Datetime\TimeInterface
   */
  protected $time;

  /**
   * Constructs a QuickFormBase object.
   *
   * @param array $configuration
   *   A configuration array containing information about the plugin instance.
   * @param string $plugin_id
   *   The plugin_id for the plugin instance.
   * @param mixed $plugin_definition
   *   The plugin implementation definition.
   * @param \Drupal\Core\Messenger\MessengerInterface $messenger
   *   The messenger service.
   * @param \Drupal\Core\Entity\EntityTypeManagerInterface $entity_type_manager
   *   The entity type manager service.
   * @param \Drupal\Component\Datetime\TimeInterface $time
   *   The time service.
   */
  public function __construct(array $configuration, $plugin_id, $plugin_definition, MessengerInterface $messenger, EntityTypeManagerInterface $entity_type_manager, TimeInterface $time) {
    parent::__construct($configuration, $plugin_id, $plugin_definition, $messenger);
    $this->messenger = $messenger;
    $this->entityTypeManager = $entity_type_manager;
    $this->time = $time;
  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    return new static(
      $configuration,
      $plugin_id,
      $plugin_definition,
      $container->get('messenger'),
      $container->get('entity_type.manager'),
      $container->get('datetime.time'),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $form['#tree'] = TRUE;

    // Date.
    $form['date'] = [
      '#type' => 'date',
      '#title' => $this->t('Date'),
      '#date_year_range' => '-10:+3',
      '#default_value' => date('Y-m-d', $this->time->getRequestTime()),
      '#required' => TRUE,
    ];

    // Maple asset reference (autocomplete).
    $form['asset'] = [
      '#type' => 'entity_autocomplete',
      '#title' => $this->t('Maple asset'),
      '#description' => $this->t('Which maple asset is sap being collected from?'),
      '#target_type' => 'asset',
      '#selection_settings' => [
        'target_bundles' => ['maple'],
      ],
      '#required' => TRUE,
    ];

    // Quantity.
    $form['quantity'] = [
      '#type' => 'details',
      '#title' => $this->t('Quantity'),
      '#open' => TRUE,
    ];
    $form['quantity']['value'] = [
      '#type' => 'number',
      '#title' => $this->t('Value'),
      '#min' => 0,
    ];
    $form['quantity']['units'] = [
      '#type' => 'entity_autocomplete',
      '#title' => $this->t('Units'),
      '#target_type' => 'taxonomy_term',
      '#selection_settings' => [
        'target_bundles' => ['unit'],
      ],
      '#autocreate' => [
        'bundle' => 'unit',
      ],
    ];

    // Notes.
    $form['notes'] = [
      '#type' => 'text_format',
      '#title' => $this->t('Notes'),
      '#format' => 'default',
    ];

    // Done.
    $form['done'] = [
      '#type' => 'checkbox',
      '#title' => $this->t('Completed'),
      '#default_value' => TRUE,
    ];

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {

    // Load the maple asset.
    /** @var \Drupal\asset\Entity\AssetInterface $asset */
    $asset = $this->entityTypeManager->getStorage('asset')->load($form_state->getValue('asset'));

    // Generate a name for the log.
    $log_name = $this->t('Collect sap from @asset', ['@asset' => $asset->label()]);

    // Create a quantity for tap count. Adjust inventory if desired.
    $quantities = [];
    if (!empty($form_state->getValue(['quantity', 'value']))) {
      $quantities[] = [
        'measure' => 'volume',
        'value' => $form_state->getValue(['quantity', 'value']),
        'units' => $form_state->getValue(['quantity', 'units']),
      ];
    }

    // Set the log status.
    $status = 'pending';
    if (!empty($form_state->getValue('done'))) {
      $status = 'done';
    }

    // Create the log.
    $this->createLog([
      'type' => 'harvest',
      'name' => $log_name,
      'timestamp' => strtotime($form_state->getValue('date')),
      'asset' => $asset,
      'quantity' => $quantities,
      'notes' => $form_state->getValue('notes'),
      'status' => $status,
    ]);
  }

}
