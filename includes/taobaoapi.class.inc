<?php
/**
 * @file
 * Class of taobaoapi
 */

class TaobaoApiUtil {
  
  var $endpoint;
  var $version = '2.0';
  var $response_format;
  var $app_key;
  var $app_secret;
  
  /**
   * Constructor
   */
  public function TaobaoApiUtil() {
    
  }
  
  /**
   * Set endpoint
   * @param string $endpoint
   */
  function taobaoApiUtilSetEndpoint($endpoint) {
    $this->endpoint = $endpoint;
  }
  
  /**
   * Get endpoint
   * @return string $endpoint
   */
  function taobaoApiUtilGetEndpoint() {
    return $this->endpoint;
  }
  
  function taobaoApiUtilSetAppKey($appkey) {
    $this->app_key = $appkey;
  }
  
  function taobaoApiUtilSetAppSecret($appsecret) {
    $this->app_secret = $appsecret;
  }
  
  /**
   * Get seller information
   */
  function taobaoApiUtilUserGetSeller($fields) {
    
    $timestamp = time();
    
    $params = array(
      'method' => 'taobao.user.seller.get',
      'timestamp' => $timestamp,
      'fields'=> 'nick',
      'format' => $this->response_format,
      'app_key' => $this->app_key,
      'v' => $this->version,
    );
    
    $sign = self::_taobaoApiUtilGenerateSignature($params);
    
    $params += array('sign' => $sign);
    
    $url = self::_taobaoApiUtilGenerateReqUrl($params);
    
    $http_client = http_client();
        
    return $http_client->get($uri);;
  }
  
  /**
   * Build signature
   * 
   * @param array $params
   * @return string
   */
  private function _taobaoApiUtilGenerateSignature($params) {
    ksort($params);
    
    $string = '';
    foreach ($params as $key => $value) {
      $string .= $key . $value;
    }
    
    $string = $this->app_secret . $string . $this->app_secret;
    $signature = md5($string);
    
    return $signature;
  }
  
  /**
   * Generate a request url
   * 
   * @param array $params
   * @return string
   */
  private function _taobaoApiUtilGenerateReqUrl($params) {
    $url = $this->endpoint;
    
    foreach ($params as $key => $value) {
      $temp_var[] = "{$key}={$value}";
    }
    
    return $url .'?'. implode('&', $temp_var);
  }
}