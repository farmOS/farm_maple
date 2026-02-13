<?php

/**
 * @file
 * Post update hooks for the farm_maple module.
 */

/**
 * Implements hook_removed_post_updates().
 */
function farm_maple_removed_post_updates() {
  return [
    'farm_maple_post_update_uninstall_v1_migrations' => '3.x',
  ];
}
