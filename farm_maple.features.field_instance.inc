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

  // Translatables
  // Included for use with string extractors like potx.
  t('Location');

  return $field_instances;
}
