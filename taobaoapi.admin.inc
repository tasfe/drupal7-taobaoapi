<?php
/**
 * 
 * @file
 * admin file
 * 
 */

/**
 * 
 * Taobao api configuration setting variables
 * 
 * @return array
 */
function taobaoapi_admin_settings() {
  $form = array();
  
  $form['taobaoapi_appkey'] = array(
    '#type' => 'textfield',
    '#title' => t('App key'),
    '#default_value' => variable_get('taobaoapi_appkey', ''),
    '#description' => t('The app key get from taobao developer platform of your
      application.'),
    '#required' => TRUE,
  );
  $form['taobaoapi_appsecret'] = array(
    '#type' => 'textfield',
    '#title' => t('App secret'),
    '#default_value' => variable_get('taobaoapi_appsecret', ''),
    '#description' => t('The app secret get from taobao developer platform of your
      application.'),
    '#required' => TRUE,
  );
  
  // Debug model
  $form['taobaoapi_debug'] = array(
    '#type' => 'checkbox',
    '#title' => t('Debug'),
    '#description' => t('Check to set in debug model and sandbox will be used.'),
    '#default_value' => variable_get('taobaoapi_debug', FALSE),
  );
  $form['taobaoapi_sandbox'] = array(
    '#type' => 'textfield',
    '#title' => t('Sandbox'),
    '#description' => t('Provide the sandbox, for example, 
      http://gw.api.tbsandbox.com/router/rest'),
    '#default_value' => variable_get('taobaoapi_sandbox', ''),
  );
  $form['taobaoapi_production_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Sandbox'),
    '#description' => t('Provide the production endpoint, for example, 
      http://gw.api.taobao.com/router/rest'),
    '#default_value' => variable_get('taobaoapi_production_endpoint', ''),
  );
  
  $form['taobaoapi_response_format'] = array(
    '#type' => 'select',
    '#options' => array('xml' => 'XML', 'json' => 'JSON'),
    '#title' => t('Select response data format.'),
    '#description' => t('Currently taobao api only supports response information
      as XML or JSON.'),
    '#default_value' => 'json',
    '#required' => TRUE,
  );
  
  $form['taobaoapi_sign_method'] = array(
    '#type' => 'select',
    '#options' => array('md5' => 'MD5', 'hmac' => 'HMAC'),
    '#title' => t('Select response data format.'),
    '#description' => t('Select parameter encryption method.'),
    '#default_value' => 'md5',
    '#required' => TRUE,
  );
  
  return system_settings_form($form);
}
