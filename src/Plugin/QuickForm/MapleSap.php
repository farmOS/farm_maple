<?php

namespace Drupal\farm_maple\Plugin\QuickForm;

use Drupal\Core\Datetime\DrupalDateTime;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\StringTranslation\TranslatableMarkup;
use Drupal\farm_quick\Attribute\QuickForm;
use Drupal\farm_quick\Plugin\QuickForm\QuickFormBase;
use Drupal\farm_quick\Traits\QuickLogTrait;
use Drupal\farm_quick\Traits\QuickStringTrait;

/**
 * Maple sap harvest quick form.
 */
#[QuickForm(
  id: 'maple_sap',
  label: new TranslatableMarkup('Maple sap harvest'),
  description: new TranslatableMarkup('Record maple sap harvest.'),
  helpText: new TranslatableMarkup('This form will create a harvest log to represent the collection of maple sap.'),
  permissions: [
    'create harvest log',
  ],
)]
class MapleSap extends QuickFormBase {

  use QuickLogTrait;
  use QuickStringTrait;

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $form['#tree'] = TRUE;

    // Date.
    $form['date'] = [
      '#type' => 'datetime',
      '#title' => $this->t('Date'),
      '#default_value' => new DrupalDateTime('now', $this->currentUser->getTimeZone()),
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

    // Get the date.
    $timestamp = $form_state->getValue('date')->getTimestamp();

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
      'timestamp' => $timestamp,
      'asset' => $asset,
      'quantity' => $quantities,
      'notes' => $form_state->getValue('notes'),
      'status' => $status,
    ]);
  }

}
