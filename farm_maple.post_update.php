<?php

/**
 * @file
 * Post update hooks for the farm_maple module.
 */

use Drupal\migrate_plus\Entity\Migration;

/**
 * Uninstall v1 migration configs.
 */
function farm_maple_post_update_uninstall_v1_migrations(&$sandbox) {
  $config = Migration::load('farm_migrate_asset_maple');
  if (!empty($config)) {
    $config->delete();
  }
  $config = Migration::load('farm_migrate_log_tap');
  if (!empty($config)) {
    $config->delete();
  }
}
