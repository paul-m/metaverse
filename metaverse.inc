<?php
// $Id$
/**
 * @file
 * Infrequently-used functions and text literals
 *
 * We keep the .module file slim by moving the bloat here.
 */

function _metaverse_settings_form() {
  $options = array(
    0 => t('User page'),
    1 => t('Referrals page'),
  );

/*  $form['metaverse_allowed_ips'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Allowed Ips'),
    '#default_value' => variable_get('metaverse_allowed_ips', ''),
    '#description'   => t('Enter the allowed Ips separated by a comma.'),
  );
*/
  $form['metaverse_use_proxy'] = array(
    '#type'          => 'radios',
    '#title'         => t('Use proxy'),
    '#default_value' => variable_get('metaverse_use_proxy', 0),
    '#options'       => array( 0 => t('No'), 1 => t('Yes') ),
    '#description'   => t('Select "yes" if your website is behind a proxy.'),
  );

  $form['metaverse_debug'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Debugging enabled ?'),
    '#default_value' => variable_get('metaverse_debug', ''),
    '#description'   => t('Enable debugging output of server/client interactions. Enter the full path name of the file to write the debugging output to, such as /tmp/secondlife.debug. It must be writable to the user who runs your web server. Leave blank for no debugging'),
  );

  $form['metaverse_timer'] = array(
    '#type'          => 'radios',
    '#title'         => t('Enable timing of requests ?'),
    '#default_value' => variable_get('metaverse_timer', 0),
    '#options'       => array( 0 => t('Disabled'), 1 => t('Enabled') ),
    '#description'   => t('Select whether you want to record timing information for how much it takes to process requests from the clients. A "timer=" is send with the response to the client, and if also writting to the debugging output (if enabled).'),
  );

  $form['metaverse_separators'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Separators'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
  );
  $form['metaverse_separators']['metaverse_args_separator'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Arguments separator'),
    '#size'          => 5,
    '#default_value' => variable_get('metaverse_args_separator', ':'),
    '#description'   => t('Enter the separator string for arguments.'),
  );

  $form['metaverse_fields_names'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Fields Names'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
  );
  $form['metaverse_fields_names']['metaverse_app'] = array(
    '#type'          => 'textfield',
    '#title'         => t('App'),
    '#default_value' => variable_get('metaverse_app', 'app'),
  );
  $form['metaverse_fields_names']['metaverse_cmd'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Cmd'),
    '#default_value' => variable_get('metaverse_cmd', 'cmd'),
  );
  $form['metaverse_fields_names']['metaverse_arg'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Arg'),
    '#default_value' => variable_get('metaverse_arg', 'arg'),
  );
/*  $form['metaverse_grids'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Grids'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
  );
  $form['metaverse_grids']['grid_name'] = array(
                '#type' => 'textfield',
                '#title' => t('Name'),
                '#prefix' => '<table><tr><td>',
                '#suffix' => '</td>',
        );
  $form['metaverse_grids']['grid_grid'] = array(
                '#type' => 'textfield',
                '#title' => t('Grid'),
                '#prefix' => '<td>',
                '#suffix' => '</td>',
        );
  $form['metaverse_grids']['grid_restrict'] = array(
                '#type' => 'checkbox',
                '#title' => t('Restricted'),
                '#prefix' => '<td>',
                '#suffix' => '</td></tr></table>',
        );*/
  return system_settings_form($form);
}


/* we call this when we want to init a couple of grids into the
   database when the module is enabled.
   this could be a separate module per grid.
   */
function _metaverse_enable() {
  drupal_get_schema(NULL, TRUE);
  $sl = array(
    'shard_name' => 'Production',
    'grid_name' => 'Second Life®',
    'grid_nick' => 'SL',
    'grid_allowed_ips' => '8.2.32.0/22,63.210.156.0/22,64.129.40.0/22,64.129.44.0/22,64.154.220.0/22,8.4.128.0/22,8.10.144.0/21,216.82.0.0/18'
  );
  $slp = array(
    'shard_name' => 'Testing',
    'grid_name' => 'Second Life® Preview',
    'grid_nick' => 'SLP'
  );
  $rg = array(
    'shard_name' => 'ReactionGrid',
    'grid_name' => 'ReactionGrid',
    'grid_nick' => 'RG'
  );
  $osg = array(
    'shard_name' => 'OpenSim',
    'grid_name' => 'OSGrid',
    'grid_nick' => 'OSG'
  );
  // eventually delete this entry; it's here for testing.
  $farstone = array(
    'grid_id' => 1, // we hope this is correct. :-)
    'region_name' => 'Farstone',
  );
  drupal_write_record('metaverse_grids', $sl);
  drupal_write_record('metaverse_grids', $slp);
  drupal_write_record('metaverse_grids', $rg);
  drupal_write_record('metaverse_grids', $osg);
  drupal_write_record('metaverse_regions', $farstone);
}
