<?php
/**
 * @file
 * pw_display.features.conditional_fields.inc
 */

/**
 * Implements hook_conditional_fields_default_fields().
 */
function pw_display_conditional_fields_default_fields() {
  $items = array();

  $items[] = array(
    'entity' => 'node',
    'bundle' => 'display_ads',
    'dependent' => 'field_tags',
    'dependee' => 'field_section_all_select',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => '1',
        2 => '2',
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        4 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        8 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        6 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        5 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        7 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        3 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => '1',
        3 => 0,
        2 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => '1',
          3 => 0,
          2 => 0,
        ),
        4 => array(
          1 => '1',
          3 => 0,
          2 => 0,
        ),
        2 => array(
          1 => '1',
          3 => 0,
          2 => 0,
        ),
        8 => array(
          1 => '1',
          3 => 0,
          2 => 0,
        ),
        6 => array(
          1 => '1',
          3 => 0,
          2 => 0,
        ),
        5 => array(
          1 => '1',
          3 => 0,
          2 => 0,
        ),
        7 => array(
          1 => '1',
          3 => 0,
          2 => 0,
        ),
        3 => array(
          1 => '1',
          3 => 0,
          2 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => '1',
      'value_form' => '0',
      'value' => array(
        0 => array(
          'value' => '0',
        ),
      ),
      'grouping' => 'AND',
      'values' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'node',
    'bundle' => 'display_ads',
    'dependent' => 'field_section_all_select',
    'dependee' => 'field_tags',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'values_set' => 1,
      'value' => array(),
      'values' => array(),
      'value_form' => array(),
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(),
      'element_edit' => array(
        1 => 1,
        2 => 0,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(),
      'selector' => '',
      'grouping' => 'AND',
    ),
  );

  return $items;
}
