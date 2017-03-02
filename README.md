# Apigee Filter API products

This custom module for Drupal adds a capability to the Apigee Edge developer portal that allows portal administrators to filter the list of API Products presented to developers in the "add an app" page.

It is built and tested on Druapl 7. 

## Details

The Apigee Edge devconnect module retrieves the set of public API Products from Apigee Edge, in preparation for displaying that list to the authenticated developer when the developer tries to provision new credentials = aka "add an app".

devconnect calls drupal_alter() on the list, to allow another module to filter that list according to its requirements.

This is such a module.  It allows portal administrators to map API products based on the environments in which the API product is available, into different dev portals.

## Installation and Enabling the Module

You should copy the module source code to your druapl git directory, place it in sites/all/modules/custom.

Then, perform the requisite `git push` to get the source code into the dev site.

Login to the dev site as an admin, and click to Admin / Modules  and then search for, find, and enable the API Product Filtering module.

## Let me show you

[![Click to see the screencast](https://img.youtube.com/vi/UB3V1Lx83Qc/0.jpg)](https://youtu.be/UB3V1Lx83Qc)


## Administering

Once the module is enabled, 
Click Admin / Configuration / Dev Portal / API Product Filtering

There you will see a panel that presents the list of environments for your organization, and allows you to specify whether and how to filter the API products for each organization.

For example, you can set it so that the API Product filtering for the dev site will be different than the filter for the live site. This means a developer logging into the dev site would see a different set of API products than a developer logigng into the live site.

Obviously, the settings apply only to the site you are currently administering. If you want the settings administratively specified in the dev site to also apply to the test and live sites, you will need to either repeat those settings, or copy the database from dev to test and from dev to live. Be careful if you element to use this option!


## The Experience of the Developer or User

A developer or user visiting the devportal site will see nothing different, nothing different in their experience, except that the list of API products in the dropdown box will be filtered.

## Availability

This module relies on enhancement DEVSOL-2137 in the Apigee Edge developer portal. This was first implemented in April 2016. Make sure your developer portal has this enhancement before trying to use this module. 

## License

This material is copyright 2016 Apigee Corporation, 2017 Google, Inc.
and is licensed under the [Apache 2.0 License](LICENSE). 


## Bugs

none yet? 