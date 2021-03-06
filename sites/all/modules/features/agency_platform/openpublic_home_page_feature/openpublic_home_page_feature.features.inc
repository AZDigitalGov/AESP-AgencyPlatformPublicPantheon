<?php
/**
 * @file
 * openpublic_home_page_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openpublic_home_page_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "delta" && $api == "delta") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function openpublic_home_page_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function openpublic_home_page_feature_image_default_styles() {
  $styles = array();

  // Exported image style: home_page_feature.
  $styles['home_page_feature'] = array(
    'label' => 'home_page_feature',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 620,
          'height' => 280,
          '#imageinfo_cache_effect_callback' => 'image_scale_and_crop_effect',
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function openpublic_home_page_feature_node_info() {
  $items = array(
    'home_page_feature' => array(
      'name' => t('Home Page Feature'),
      'base' => 'node_content',
      'description' => t('Featured content to display in the main carousel atop the home page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
