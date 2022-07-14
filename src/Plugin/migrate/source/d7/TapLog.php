<?php

namespace Drupal\farm_maple\Plugin\migrate\source\d7;

use Drupal\log\Plugin\migrate\source\d7\Log;
use Drupal\migrate\Row;
use Drupal\taxonomy\Entity\Term;

/**
 * Maple tap log source.
 *
 * Extends the Log source plugin to include source properties needed for the
 * farm_maple D7 migration.
 *
 * @MigrateSource(
 *   id = "d7_farm_maple_tap_log",
 *   source_module = "log"
 * )
 */
class TapLog extends Log {

  /**
   * {@inheritdoc}
   */
  public function prepareRow(Row $row) {
    $result = parent::prepareRow($row);
    if (!$result) {
      return FALSE;
    }

    // Prepare maple tap log information.
    $this->prepareTapData($row);

    // Return success.
    return TRUE;
  }

  /**
   * Prepare a maple tap log's information.
   *
   * @param \Drupal\migrate\Row $row
   *   The row object.
   */
  protected function prepareTapData(Row $row) {
    $id = $row->getSourceProperty('id');

    // Get the tap count field value.
    $tap_count = $this->getFieldvalues('log', 'field_farm_tap_count', $id);

    // Create or load a "taps" unit taxonomy term.
    $name = 'taps';
    $vocabulary = 'unit';
    $search = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadByProperties(['name' => $name, 'vid' => $vocabulary]);
    if (!empty($search)) {
      $term = reset($search);
    }
    else {
      $term = Term::create([
        'name' => $name,
        'vid' => $vocabulary,
      ]);
      $term->save();
    }

    // Assemble a quantity for the tap count.
    $quantities = [
      [
        'value' => $tap_count[0]['value'],
        'units' => $term->id(),
      ],
    ];
    $row->setSourceProperty('tap_count_quantities', $quantities);

    // Add the tap count to the row for future processing.
    $row->setSourceProperty('tap_count', $tap_count);

    // Get the tap size field value.
    $tap_size = $this->getFieldvalues('log', 'field_farm_tap_size', $id);

    // If there is no value, bail.
    if (empty($tap_size[0]['value'])) {
      return;
    }

    // Create a string that summarizes the tap size.
    $summary = $this->t('Tap size: @size', ['@size' => $tap_size[0]['value']]);

    // The tap size summary is going to be prepended to the log's Notes field,
    // but we want to make sure that whitespace is added if there is already
    // data in the Notes field.
    $notes = $this->getFieldvalues('log', 'field_farm_notes', $id);
    if (!empty($notes)) {
      $summary = $summary . "\n\n";
    }

    // Add the tap size summary to the row for future processing.
    $row->setSourceProperty('tap_size', $summary);
  }

}
