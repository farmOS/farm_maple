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
 * Maple tap quick form.
 */
#[QuickForm(
  id: 'maple_tap',
  label: new TranslatableMarkup('Maple tap'),
  description: new TranslatableMarkup('Record maple tree tapping.'),
  helpText: new TranslatableMarkup('This form will create an activity log to represent the tapping of maple trees.'),
  permissions: [
    'create activity log',
  ],
)]
class MapleTap extends QuickFormBase {

  use QuickLogTrait;
  use QuickStringTrait;

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {

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
      '#description' => $this->t('Which maple asset is being tapped?'),
      '#target_type' => 'asset',
      '#selection_settings' => [
        'target_bundles' => ['maple'],
      ],
      '#required' => TRUE,
    ];

    // Tap count.
    $form['tap_count'] = [
      '#type' => 'number',
      '#title' => $this->t('Tap count'),
      '#description' => $this->t('How many taps were added (or removed - see inventory options below)?'),
      '#min' => 0,
      '#step' => 1,
    ];

    // Inventory adjustment.
    $form['inventory'] = [
      '#type' => 'select',
      '#title' => $this->t('Tap inventory tracking'),
      '#description' => $this->t('Optionally track the inventory of taps in this maple asset. "Add taps" will add taps to the tap count of the maple asset, "Remove taps" will subtract them, and "Reset" will reset the tap count. If you do not record tap removals, use "Reset" at the beginning of each tapping season to ensure that the tap count is reset. Leave this blank if you do not need to track tap inventory. Tap counts will still be saved, but a running inventory will not be kept.'),
      '#options' => [
        '' => '',
        'increment' => $this->t('Add taps'),
        'decrement' => $this->t('Remove taps'),
        'reset' => $this->t('Reset'),
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
    $log_name = $this->t('Tap @asset', ['@asset' => $asset->label()]);
    if ($form_state->getValue('inventory') == 'decrement') {
      $log_name = $this->t('Remove taps from @asset', ['@asset' => $asset->label()]);
    }

    // Create a quantity for tap count. Adjust inventory if desired.
    $quantities = [];
    $tap_count = $form_state->getValue('tap_count');
    if (!empty($tap_count)) {
      $quantity = [
        'measure' => 'count',
        'value' => $tap_count,
        'units' => 'taps',
        'label' => $this->t('Tap count'),
      ];
      if (!empty($form_state->getValue('inventory'))) {
        $quantity['inventory_adjustment'] = $form_state->getValue('inventory');
        $quantity['inventory_asset'] = $asset;
      }
      $quantities[] = $quantity;
    }

    // Set the log status.
    $status = 'pending';
    if (!empty($form_state->getValue('done'))) {
      $status = 'done';
    }

    // Create the log.
    $this->createLog([
      'type' => 'activity',
      'name' => $log_name,
      'timestamp' => $timestamp,
      'asset' => $asset,
      'quantity' => $quantities,
      'notes' => $form_state->getValue('notes'),
      'status' => $status,
    ]);
  }

}
