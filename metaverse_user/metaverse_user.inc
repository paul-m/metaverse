<?php
// $Id: $

/*
 * @file
 * Include file for metaverse_user. Some functions have many string literals
 * and aren't used frequently, so we put them here.
 *
 */

/**
* Admin settings
*/
function _metaverse_user_admin_settings() {
  $form = array();
  // roles
  $roles = user_roles(TRUE);
  $checkbox_authenticated = array(
    '#type' => 'checkbox',
    '#title' => $roles[DRUPAL_AUTHENTICATED_RID],
    '#default_value' => TRUE,
    '#disabled' => TRUE,
  );
  unset($roles[DRUPAL_AUTHENTICATED_RID]);
  if ($roles) {
    $form['metaverse_user_roles'] = array(
      '#type' => 'fieldset',
      '#title' => t('Roles'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['metaverse_user_roles']['metaverse_user_default_roles'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Default roles for new user'),
      '#default_value' => variable_get('metaverse_user_default_roles', array()),
      '#options' => $roles,
      '#description' => t('Defines the default role when a registered user validates his account from inworld.'),
      DRUPAL_AUTHENTICATED_RID => $checkbox_authenticated,
    );
  }

  // profile view
  $form['metaverse_user_profile_view'] = array(
    '#type' => 'fieldset',
    '#title' => t('Profile view'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  // default profile view
  $form['metaverse_user_profile_view']['metaverse_user_default_profile_view'] = array(
    '#type' => 'checkbox',
    '#title' => t('Default profile view'),
    '#default_value' => variable_get('metaverse_user_default_profile_view', 1),
    '#description' => t('If enabled, all the Second Life user profiles can be viewed by default.'),
  );

  // profile category label
  $form['metaverse_user_profile_view']['metaverse_user_profile_category_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Profile category label'),
    '#default_value' => variable_get('metaverse_user_profile_category_label',
      'Second Life User'),
    '#description' => t('Define the category shown for Second Life information in the user profile.'),
  );

  // profile link model
  $form['metaverse_user_profile_view']['metaverse_user_web_profile_link_model'] = array(
    '#type' => 'textfield',
    '#title' => t('Profile link model'),
    '#default_value' => variable_get('metaverse_user_web_profile_link_model',
      'http://world.secondlife.com/resident/%uuid'),
    '#description' => t('Define the profile link model (default is "http://world.secondlife.com/resident/%uuid"). You can add some vars inside :<br/><ul><li>%uuid for user uuid</li><li>%name for user name</li></ul>'),
  );

  $form['settings'] = module_invoke_all('metaverse_user', 'settings');
  return system_settings_form($form);
}

/*
   called by hook_user('form')
*/
function _metaverse_user_avatars_form($account, $registering = FALSE) {
//  global $user; // yes, THAT $user.

  // each sub-fieldset will be known by it's grid_id
  // start by getting all the grids
  $grids = s_metaverse_all_grids(0); // 0 for unrestricted

  foreach ($grids as $mv) {
    $form_grid_id = 'metaverse_user_grid_' . $mv->grid_id;
    // for grids where the user has an acct, we must require some fields
    // but if the user has no account on a grid, we can't require it.
    $can_require = isset($account->metaverse_user[$mv->grid_id]);
    $form[$form_grid_id] = array(
      '#type' => 'fieldset',
      '#title' => $mv->grid_name,
      '#tree' => TRUE,
    );
    $form[$form_grid_id]['delete_avatar'] = array(
      '#type' => 'checkbox',
      '#title' => t('Delete this avatar'),
      '#default_value' => 0,
      '#return_value' => 1,
    );
    $form[$form_grid_id]['avatar_name']=array(
      '#type' => 'textfield',
      '#title' => t('Avatar Name'),
      '#default_value' => $account->metaverse_user[$mv->grid_id]->avatar_name,
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => $can_require,
    );
    $form[$form_grid_id]['uuid']=array(
      '#type' => 'textfield',
      '#title' => t('UUID'),
      '#default_value' => $account->metaverse_user[$mv->grid_id]->uuid,
      '#size' => 36,
      '#maxlength' => 36,
      '#required' => $can_require,
    );
    $form[$form_grid_id]['reg_key']=array(
      '#type' => 'textfield',
      '#title' => t('Registration Key'),
      '#default_value' => $account->metaverse_user[$mv->grid_id]->reg_key,
      '#size' => 36,
      '#maxlength' => 36,
    );
    $form[$form_grid_id]['display'] = array(
      '#type' => 'checkbox',
      '#title' => t('Allow other users to see this avatar'),
      '#default_value' => $account->metaverse_user[$mv->grid_id]->display,
      '#return_value' => 1,
    );
      // figure out a way to restrict this to admins.....
/*    $form['metaverse_user' . $mv->grid_id]['inworld_verified'] = array(
      '#type' => 'checkbox',
      '#title' => t('Verified In-World'),
      '#default_value' => $account->metaverse_user[$mv->grid_id]->inworld_verified,
      );*/
  }
  return $form;
}

/*
 * Validate the data we got back from _metaverse_user_avatars_form...
 */
function _metaverse_user_avatars_validate(&$edit) {
  // $edit will contain the same 'metaverse_user_grid_' . $mv->grid_id;
  // model as _metaverse_user_avatars_form.
  // Basically we need to make sure that supplied UUIDs do not conflict
  // with existing ones.
        // TO DO:
      // Validate form UUIDs against existing UUIDs, make sure they do
      // not duplicate.
      // This needs to be a public function so metaverse_user can
      // use it, too.
 //     if (!_metaverse_user_valid_uuid($edit['metaverse_avatar']['uuid']))
   //     form_set_error('metaverse_user_uuid', 'Not a valid UUID.');

}

/**
 * Is this string a valid UUID?
 */
function _metaverse_user_valid_uuid($uuid) {
  return TRUE;
}
