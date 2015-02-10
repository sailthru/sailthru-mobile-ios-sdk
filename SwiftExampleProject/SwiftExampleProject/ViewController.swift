//
//  ViewController.swift
//  SwiftExampleProject
//
//  Created by Blair McArthur on 10/09/14.
//  Copyright (c) 2014 Carnival Labs. All rights reserved.
//

import UIKit

class ViewController: UIViewController, CarnivalMessageStreamDelegate, CLLocationManagerDelegate {
    var locationManager: CLLocationManager? = nil
    
    //MARK: view lifecycle
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.setupLocationManager()
        
        // Set this viewcontroller as the CarnivalMessageStream's delegate
        CarnivalMessageStream.setDelegate(self)
        
        // Style the stream naivgation controller to have a blue navigation bar and white text
        let navVC = CarnivalMessageStream.streamNavigationController()
        navVC.navigationBar.titleTextAttributes = [NSForegroundColorAttributeName : UIColor.whiteColor()]
        navVC.navigationBar.barTintColor = UIColor.blueColor()
    }
    
    override func viewWillAppear(animated: Bool) {
        super.viewWillAppear(animated)
        
        UIApplication.sharedApplication().setStatusBarStyle(UIStatusBarStyle.Default, animated: false)
    }
    
    override func viewDidAppear(animated: Bool) {
        super.viewDidAppear(animated)
        
        self.startLocationTrackingInBackground()
    }
    
    //MARK: setup
    func setupLocationManager() {
        // Create the location manager and set ourselves as the delegate
        
        self.locationManager = CLLocationManager()
        self.locationManager?.delegate = self
        
        // The above is all you need for significant location updates
        // For standard location services you may want some extra settings
        //self.locationManager?.desiredAccuracy = kCLLocationAccuracyThreeKilometers
        //self.locationManager?.distanceFilter = 1000.0
    }
    
    //MARK: location tracking
    func startLocationTrackingInBackground() {
        let authorizationStatus = CLLocationManager.authorizationStatus()
        
        // Always check if you are authorized to start location services
        if authorizationStatus != CLAuthorizationStatus.Denied && authorizationStatus != CLAuthorizationStatus.Restricted {
            if let manager = self.locationManager {
                // Check if we are on iOS 8, where we have to requet permissions differently than on previous iOS versions
                if manager.respondsToSelector("requestAlwaysAuthorization") {
                    // Request permission to always monitor location updates, in foreground and background
                    // Note: this method prompts the user for location permissions on iOS 8 and above
                    manager.requestAlwaysAuthorization()
                }
                
                if CLLocationManager.significantLocationChangeMonitoringAvailable() {
                    // Note: this method prompts the user for location permissions on iOS 7 and below
                    manager.startMonitoringSignificantLocationChanges()
                }
                else {
                    // If you want to support devices that don't have significant location monitoring you can fall back to standard location services
                    // Note: this method prompts the user for location permissions on iOS 7 and below
                    manager.startUpdatingLocation()
                }
            }
        }
    }
    
    func stopLocationTrackingInBackground() {
        if CLLocationManager.significantLocationChangeMonitoringAvailable() {
            self.locationManager?.stopMonitoringSignificantLocationChanges()
        }
        else {
            self.locationManager?.stopUpdatingLocation()
        }
    }
    
    func startLocationTrackingInForegroundOnly() {
        let authorizationStatus = CLLocationManager.authorizationStatus()
        
        // Always check if you are authorized to start location services
        if authorizationStatus != CLAuthorizationStatus.Denied && authorizationStatus != CLAuthorizationStatus.Restricted {
            if let manager = self.locationManager {
                // Check if we are on iOS 8, where we have to requet permissions differently than on previous iOS versions
                if manager.respondsToSelector("requestWhenInUseAuthorization") {
                    // Request permission to monitor location updates when the app is in use
                    // Note: this method prompts the user for location permissions on iOS 8 and above
                    manager.requestWhenInUseAuthorization()
                }
                
                // Note: this method prompts the user for location permissions on iOS 7 and below
                manager.startUpdatingLocation()
            }
        }
    }
    
    func stopLocationTrackingInForegroundOnly() {
        self.locationManager?.stopUpdatingLocation()
    }
    
    //MARK: CLLocationManagerDelegate
    func locationManager(manager: CLLocationManager!, didUpdateLocations locations: [AnyObject]!) {
        // Send the last location object as that is the most recent one always
        if let lastLocation = locations.last as? CLLocation {
            Carnival.updateLocation(lastLocation)
        }
    }
    
    //MARK: CarnivalMessageStreamDelegate
    func carnivalMessageStreamNeedsDisplay(streamNavigationController: UINavigationController!, fromApplicationState applicationState: UIApplicationState) {
        if self.presentedViewController != nil {
            // When the application is active we want to animate the Carnival Message Stream onto the screen
            // Otherwise the application is in the background or inactive so we want to have the Carnival Message Stream there when the application is active
            let animated = applicationState == UIApplicationState.Active ? true : false
            self.presentViewController(streamNavigationController, animated: animated, completion: nil)
        }
    }
    
    func willShowMessageStream(messageStreamViewController: UIViewController!) {
        UIApplication.sharedApplication().setStatusBarStyle(UIStatusBarStyle.LightContent, animated: false)
        
        messageStreamViewController.navigationItem.rightBarButtonItem?.tintColor = UIColor.whiteColor()
    }
    
    func willShowMessageDetail(messageDetailViewController: UIViewController!) {
        UIApplication.sharedApplication().setStatusBarStyle(UIStatusBarStyle.LightContent, animated: false)
        
        messageDetailViewController.navigationItem.rightBarButtonItem?.tintColor = UIColor.whiteColor()
        messageDetailViewController.navigationItem.leftBarButtonItem?.tintColor = UIColor.whiteColor()
    }
    
    //MARK: pressed actions
    @IBAction func getTagsButtonPressed(sender: UIButton) {
        // Asyncronously gets the tags for this device.
        Carnival.getTagsInBackgroundWithResponse { (tags: [AnyObject]!, error: NSError!) -> Void in
            println("getTagsInBackgroundWithResponse returned tags: \(tags)")
        }
    }
    
    @IBAction func addTagButtonPressed(sender: UIButton) {
        // Asyncronously adds the tag for this device
        // If the tag is already registered with Carnival, this method does not add the tag again.
        Carnival.addTags(["CARNIVAL_ADD_TAG_EXAMPLE_TAG"], inBackgroundWithResponse: { (tags: [AnyObject]!, error: NSError!) -> Void in
            println("addTag:inBackgroundWithResponse: returned tags: \(tags)")
        })
    }
    
    @IBAction func setTagsButtonPressed(sender: UIButton) {
        let exampleTags = ["CARNIVAL_SET_TAGS_EXAMPLE_TAG_1", "CARNIVAL_SET_TAGS_EXAMPLE_TAG_2"]
        
        // Asyncronously sets the tags for Carnival for this device
        // Calling this method will overwrite any previously set tags for this device.
        // Passing nil for the tags argument will clear the tags for this device
        Carnival.setTagsInBackground(exampleTags, withResponse: { (tags: [AnyObject]!, error: NSError!) -> Void in
            println("setTagsInBackground:withResponse: returned tags: \(tags)");
        })
    }
    
    @IBAction func showMessageStreamButtonPressed(sender: UIButton) {
        // Retrieve the streamNavigationController and present it like you would any normal UIViewController
        let navVc = CarnivalMessageStream.streamNavigationController()
        self.presentViewController(navVc, animated: true, completion: nil)
    }
}