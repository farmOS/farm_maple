<?php
/**
 * @file
 * farm_maple.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function farm_maple_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function farm_maple_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_farm_asset_type().
 */
function farm_maple_default_farm_asset_type() {
  $items = array();
  $items['sugar_bush'] = entity_import('farm_asset_type', '{
    "type" : "sugar_bush",
    "label" : "Sugar Bush",
    "weight" : 0,
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_log_type().
 */
function farm_maple_default_log_type() {
  $items = array();
  $items['farm_tap'] = entity_import('log_type', '{
    "type" : "farm_tap",
    "label" : "Tap",
    "weight" : 0,
    "name_pattern" : "Tap [log:field-farm-sugar-bush]",
    "name_edit" : "0",
    "done" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
