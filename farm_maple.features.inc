<?php
/**
 * @file
 * farm_maple.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function farm_maple_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
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
