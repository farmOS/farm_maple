<?php
/**
 * @file
 * farm_maple.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function farm_maple_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'farm_asset-sugar_bush-field_farm_geofield'
  $field_instances['farm_asset-sugar_bush-field_farm_geofield'] = array(
    'bundle' => 'sugar_bush',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'openlayers_geofield',
        'settings' => array(
          'data' => 'full',
          'map_preset' => 'farm_map_geofield_formatter',
        ),
        'type' => 'openlayers_geofield',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'farm_asset',
    'field_name' => 'field_farm_geofield',
    'label' => 'Location',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'geofield',
      'settings' => array(
        'allow_edit' => 1,
        'data_storage' => 'single',
        'delta_handling' => 'default',
        'feature_types' => array(
          'path' => 'path',
          'point' => 'point',
          'polygon' => 'polygon',
        ),
        'geocoder_field' => '',
        'geocoder_handler' => '',
        'handler_settings' => array(
          'google' => array(
            'all_results' => 0,
            'geometry_type' => 'point',
            'reject_results' => array(
              'APPROXIMATE' => 0,
              'GEOMETRIC_CENTER' => 0,
              'RANGE_INTERPOLATED' => 0,
              'ROOFTOP' => 0,
            ),
          ),
        ),
        'openlayers_map' => 'farm_map_geofield',
        'use_geocoder' => 0,
      ),
      'type' => 'geofield_wkt',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'log-farm_sap-field_farm_notes'
  $field_instances['log-farm_sap-field_farm_notes'] = array(
    'bundle' => 'farm_sap',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_farm_notes',
    'label' => 'Notes',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'log-farm_sap-field_farm_quantity'
  $field_instances['log-farm_sap-field_farm_quantity'] = array(
    'bundle' => 'farm_sap',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Describe the quantity of this harvest, using a value and a unit of measurement. For example, if you harvested 10 gallons of sap, enter "10" in the Value field, and "gallons" in the Units field. As you type the unit, you will have the option of selecting from units that you\'ve entered in the past.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_farm_quantity',
    'label' => 'Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'log-farm_sap-field_farm_sugar_bush'
  $field_instances['log-farm_sap-field_farm_sugar_bush'] = array(
    'bundle' => 'farm_sap',
    'default_value' => array(),
    'deleted' => 0,
    'description' => 'The sugar bush that the sap is coming from.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_farm_sugar_bush',
    'label' => 'Sugar Bush',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'log-farm_tap-field_farm_notes'
  $field_instances['log-farm_tap-field_farm_notes'] = array(
    'bundle' => 'farm_tap',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_farm_notes',
    'label' => 'Notes',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'log-farm_tap-field_farm_sugar_bush'
  $field_instances['log-farm_tap-field_farm_sugar_bush'] = array(
    'bundle' => 'farm_tap',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The sugar bush that is being tapped.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_farm_sugar_bush',
    'label' => 'Sugar Bush',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'log-farm_tap-field_farm_tap_count'
  $field_instances['log-farm_tap-field_farm_tap_count'] = array(
    'bundle' => 'farm_tap',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'How many taps were set in this sugar bush?',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_farm_tap_count',
    'label' => 'Tap Count',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'log-farm_tap-field_farm_tap_size'
  $field_instances['log-farm_tap-field_farm_tap_size'] = array(
    'bundle' => 'farm_tap',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_farm_tap_size',
    'label' => 'Tap Size',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'available_options' => '5/16"
7/16"',
        'available_options_php' => '',
        'markup_available_options_php' => '&lt;none&gt;',
        'other' => 'Other',
        'other_size' => 60,
        'other_title' => '',
        'other_unknown_defaults' => 'other',
        'size' => 60,
        'sort_options' => 0,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Describe the quantity of this harvest, using a value and a unit of measurement. For example, if you harvested 10 gallons of sap, enter "10" in the Value field, and "gallons" in the Units field. As you type the unit, you will have the option of selecting from units that you\'ve entered in the past.');
  t('How many taps were set in this sugar bush?');
  t('Location');
  t('Notes');
  t('Quantity');
  t('Sugar Bush');
  t('Tap Count');
  t('Tap Size');
  t('The sugar bush that is being tapped.');
  t('The sugar bush that the sap is coming from.');

  return $field_instances;
}
