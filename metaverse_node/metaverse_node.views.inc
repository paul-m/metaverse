<?php
// $Id: $

/**
 * @file
 * Views API stuff for metaverse_node module
 */

/*
 * Implementation of hook_views_data()
 */
function metaverse_node_views_data() {
  // We want our special MV data to show up under 'Node' in
  // the Views UI. We're piggybacking on Node, JUST LIKE REVISIONS. :-)
  $data['metaverse_node']['table']['group'] = t('Node');

  // TABLES
  // Define some joins between our table and others. 
  $data['metaverse_node']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
    'node_revisions' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
    'metaverse_grids' => array(
      'left_table' => 'metaverse_grids',
      'left_field' => 'grid_id',
      'field' => 'mv_grid_id',
    ),
    'metaverse_regions' => array(
      'left_table' => 'metaverse_regions',
      'left_field' => 'region_id',
      'field' => 'mv_region_id',
    ),
  );

  // Define the UI for our fields.
  $data['metaverse_node']['mv_grid_id'] = array(
    'title' => t('Metaverse Grid ID'),
    'help' => t('The ID for the metaverse grid (world) this node references.'),
    'relationship' => array(
      'base' => 'metaverse_grids',
      'field' => 'grid_id',
      'handler' => 'views_handler_relationship',
      'label' => t('Metaverse grid'),
    ),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['metaverse_node']['mv_region_id'] = array(
    'title' => t('Metaverse Region ID'),
    'help' => t('The ID for the metaverse region (sim) this node references.'),
    'relationship' => array(
      'base' => 'metaverse_regions',
      'field' => 'region_id',
      'handler' => 'views_handler_relationship',
      'label' => t('Metaverse region'),
    ),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['metaverse_node']['mv_node_coord_x'] = array(
    'title' => t('Region Coordinates X'),
    'help' => t('X location of this node, in region coords.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['metaverse_node']['mv_node_coord_y'] = array(
    'title' => t('Region Coordinates Y'),
    'help' => t('Y location of this node, in region coords.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['metaverse_node']['mv_node_coord_z'] = array(
    'title' => t('Region Coordinates Z'),
    'help' => t('Z location of this node, in region coords.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );


  // We have two base tables: grids and regions.
  $data['metaverse_grids']['table']['group'] = t('Metaverse');
  $data['metaverse_regions']['table']['group'] = t('Metaverse');

  // BASES
  $data['metaverse_grids']['table']['base'] = array(
    'field' => 'grid_id',
    'title' => t('Grid'),
    'help' => t("A metaverse grid."),
  );
  $data['metaverse_regions']['table']['base'] = array(
    'field' => 'region_id',
    'title' => t('Region'),
    'help' => t("A metaverse region."),
  );


  // Define some joins between our table and others. 
  $data['metaverse_grids']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
    'node_revisions' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );

  $data['metaverse_regions']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
    'node_revisions' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
    'metaverse_grids' => array(
      'left_field' => 'region_id',
      'field' => 'region_id',
    ),
  );


  // Define the UI for our fields.
  $data['metaverse_grids']['grid_id'] = array(
    'title' => t('Metaverse Grid ID'),
    'help' => t('The ID for the metaverse grid.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  
  // Example plain text field.
  $data['metaverse_grids']['grid_name'] = array(
    'title' => t('Grid name'),
    'help' => t('The name of the grid.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['metaverse_grids']['grid_restricted'] = array(
    'title' => t('Restricted'),
    'help' => t('Grid is restricted.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
  );

  // Define the UI for our fields.
  $data['metaverse_regions']['region_id'] = array(
    'title' => t('Metaverse Region ID'),
    'help' => t('The ID for the region within a metaverse grid.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  
  // Example plain text field.
  $data['metaverse_regions']['region_name'] = array(
    'title' => t('Region name'),
    'help' => t('The name of the region.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['metaverse_regions']['region_restricted'] = array(
    'title' => t('Restricted'),
    'help' => t('Region is restricted.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
  );



  return $data;
}
