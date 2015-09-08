<?php
/**
 * @file
 * farm_maple.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function farm_maple_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_farm_asset_sugar_bush_pattern';
  $strongarm->value = 'farm/sugarbush/[farm_asset:name]';
  $export['pathauto_farm_asset_sugar_bush_pattern'] = $strongarm;

  return $export;
}
