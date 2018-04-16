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

  // Exported field_instance: 'farm_asset-sugar_bush-field_farm_description'.
  $field_instances['farm_asset-sugar_bush-field_farm_description'] = array(
    'bundle' => 'sugar_bush',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'farm_asset',
    'field_name' => 'field_farm_description',
    'label' => 'Description',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'farm_asset-sugar_bush-field_farm_files'.
  $field_instances['farm_asset-sugar_bush-field_farm_files'] = array(
    'bundle' => 'sugar_bush',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_table',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'farm_asset',
    'field_name' => 'field_farm_files',
    'label' => 'Files',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'file_directory' => 'farm/asset/maple',
      'file_extensions' => 'csv doc docx odt odp ods pdf ppt pptx txt xls xlsx kml kmz zip tar gz',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'multiupload_filefield_widget',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_mfw',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'farm_asset-sugar_bush-field_farm_flags'.
  $field_instances['farm_asset-sugar_bush-field_farm_flags'] = array(
    'bundle' => 'sugar_bush',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add flags to this asset to enable better sorting and filtering of records.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'farm_asset',
    'field_name' => 'field_farm_flags',
    'label' => 'Flags',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'farm_asset-sugar_bush-field_farm_images'.
  $field_instances['farm_asset-sugar_bush-field_farm_images'] = array(
    'bundle' => 'sugar_bush',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'colorbox',
        'settings' => array(
          'colorbox_caption' => 'auto',
          'colorbox_caption_custom' => '',
          'colorbox_gallery' => 'post',
          'colorbox_gallery_custom' => '',
          'colorbox_image_style' => '',
          'colorbox_multivalue_index' => NULL,
          'colorbox_node_style' => 'thumbnail',
          'colorbox_node_style_first' => 'large',
        ),
        'type' => 'colorbox',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'farm_asset',
    'field_name' => 'field_farm_images',
    'label' => 'Photos',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'farm/asset/maple',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
      ),
      'type' => 'image_image',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'log-farm_tap-field_farm_files'.
  $field_instances['log-farm_tap-field_farm_files'] = array(
    'bundle' => 'farm_tap',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_table',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_farm_files',
    'label' => 'Files',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'file_directory' => 'farm/log/tap',
      'file_extensions' => 'csv doc docx odt odp ods pdf ppt pptx txt xls xlsx kml kmz zip tar gz',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'multiupload_filefield_widget',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_mfw',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'log-farm_tap-field_farm_flags'.
  $field_instances['log-farm_tap-field_farm_flags'] = array(
    'bundle' => 'farm_tap',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add flags to this log to enable better sorting and filtering of records.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_farm_flags',
    'label' => 'Flags',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'log-farm_tap-field_farm_images'.
  $field_instances['log-farm_tap-field_farm_images'] = array(
    'bundle' => 'farm_tap',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'colorbox',
        'settings' => array(
          'colorbox_caption' => 'auto',
          'colorbox_caption_custom' => '',
          'colorbox_gallery' => 'post',
          'colorbox_gallery_custom' => '',
          'colorbox_image_style' => '',
          'colorbox_multivalue_index' => NULL,
          'colorbox_node_style' => 'thumbnail',
          'colorbox_node_style_first' => 'large',
        ),
        'type' => 'colorbox',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_farm_images',
    'label' => 'Photos',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'farm/log/tap',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'multiupload_imagefield_widget',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
      ),
      'type' => 'image_miw',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'log-farm_tap-field_farm_log_category'.
  $field_instances['log-farm_tap-field_farm_log_category'] = array(
    'bundle' => 'farm_tap',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Use this to organize your logs into categories for easier searching and filtering later.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_farm_log_category',
    'label' => 'Log category',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'log-farm_tap-field_farm_log_owner'.
  $field_instances['log-farm_tap-field_farm_log_owner'] = array(
    'bundle' => 'farm_tap',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Optionally assign this task to one or more people.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_farm_log_owner',
    'label' => 'Assigned to',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'log-farm_tap-field_farm_notes'.
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'log-farm_tap-field_farm_sugar_bush'.
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
          'bypass_access' => FALSE,
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
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

  // Exported field_instance: 'log-farm_tap-field_farm_tap_count'.
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
        'weight' => 1,
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

  // Exported field_instance: 'log-farm_tap-field_farm_tap_size'.
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
        'weight' => 2,
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
  t('Add flags to this asset to enable better sorting and filtering of records.');
  t('Add flags to this log to enable better sorting and filtering of records.');
  t('Assigned to');
  t('Description');
  t('Files');
  t('Flags');
  t('How many taps were set in this sugar bush?');
  t('Log category');
  t('Notes');
  t('Optionally assign this task to one or more people.');
  t('Photos');
  t('Sugar Bush');
  t('Tap Count');
  t('Tap Size');
  t('The sugar bush that is being tapped.');
  t('Use this to organize your logs into categories for easier searching and filtering later.');

  return $field_instances;
}
