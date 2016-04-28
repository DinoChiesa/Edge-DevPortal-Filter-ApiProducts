<?php
/**
 * @file
 * Apigee API Product list filter - included functions
 * 
 * Supporting functions used in the module and the .install
 *
 */

function apigee_filter_apiproducts_all_environments() {
  $available_environments = array("prod, test");
  try {
    $dca = new Apigee\ManagementAPI\DeveloperAppAnalytics(devconnect_default_org_config());
    $available_environments = $dca->getAllEnvironments();

    // the following did not work for me. :(
    /* $org = new Apigee\ManagementAPI\Organization(devconnect_default_org_config()); */
    /*  */
    /* $available_environments = $org->getEnvironments(); */
  }
  catch (Apigee\Exceptions\ResponseException $e) {
    watchdog('apiprods_filter',
             "Exception while retrieving environments: !exc",
             array('!exc' => $e),
             WATCHDOG_WARNING);
  }
  return $available_environments;
}


function apigee_filter_apiproducts_drupal_hostname() {
  global $GLOBALS;
  // $GLOBALS['base_url'] refers to the root URL for the site, eg,
  //  == https://foo.bar.bam

  $hostname = $GLOBALS['base_url'];
  if (strpos($hostname, 'http://')==0) {
    $hostname = substr($hostname, 7);
  }
  elseif (strpos($hostname, 'https://')==0) {
    $hostname = substr($hostname, 8);
  }
  return $hostname;
}


function apigee_filter_apiproducts_regexize_host() {
  $drupal_hostname = str_replace(".", "\\.",
                                 apigee_filter_apiproducts_drupal_hostname());
  return "^" . $drupal_hostname;
}


?>
