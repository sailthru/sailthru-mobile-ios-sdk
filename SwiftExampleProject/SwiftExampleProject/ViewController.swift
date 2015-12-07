//
//  ViewController.swift
//  SwiftExampleProject
//
//  Created by Carnival Mobile
//  Copyright (c) 2015 Carnival Mobile. All rights reserved.
//
//  For documentation see http://docs.carnivalmobile.com
//

import UIKit
import AdSupport

class ViewController: UIViewController, CarnivalMessageStreamDelegate, CLLocationManagerDelegate {
    var locationManager: CLLocationManager? = nil
    
    //MARK: view lifecycle
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.setupLocationManager()
        
        CarnivalMessageStream.setDelegate(self)
    }
    
    override func viewWillAppear(animated: Bool) {
        super.viewWillAppear(animated)
        
        UIApplication.sharedApplication().setStatusBarStyle(.Default, animated: false)
    }
    
    override func viewDidAppear(animated: Bool) {
        super.viewDidAppear(animated)
        
        self.startLocationTrackingInBackground()
        
        Carnival.deviceID { deviceID, error in
            print("deviceID for current device: \(deviceID), with possible error: \(error)")
        }
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
        if authorizationStatus != .Denied && authorizationStatus != .Restricted {
            if let manager = self.locationManager {
                // Check if we are on iOS 8, where we have to requet permissions differently than on previous iOS versions
                if manager.respondsToSelector("requestAlwaysAuthorization") {
                    // Request permission to always monitor location updates, in foreground and background
                    // Note: this method prompts the user for location permissions on iOS 8 and above
                    if #available(iOS 8.0, *) {
                        manager.requestAlwaysAuthorization()
                    } else {
                        // Fallback on earlier versions
                    }
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
        if authorizationStatus != .Denied && authorizationStatus != .Restricted {
            if let manager = self.locationManager {
                // Check if we are on iOS 8, where we have to requet permissions differently than on previous iOS versions
                if manager.respondsToSelector("requestWhenInUseAuthorization") {
                    // Request permission to monitor location updates when the app is in use
                    // Note: this method prompts the user for location permissions on iOS 8 and above
                    if #available(iOS 8.0, *) {
                        manager.requestWhenInUseAuthorization()
                    } else {
                        // Fallback on earlier versions
                    }
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
    func locationManager(manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        // Send the last location object as that is the most recent one always
        if let lastLocation = locations.last! as CLLocation {
            Carnival.updateLocation(lastLocation)
        }
    }
    
    //MARK: CarnivalMessageStreamDelegate
    func willShowMessageOfType(messageType: CarnivalMessageType) {
        print("willShowMessageOfType: \(messageType)")
        
        // You can use this method to mute audio during videos or fake phone calls
    }
    
    func didShowMessageOfType(messageType: CarnivalMessageType) {
        print("didShowMessageOfType: \(messageType)")
        
        // You can use this method to mute audio during videos or fake phone calls
    }
    
    func willDismissMessageOfType(messageType: CarnivalMessageType) {
        print("willDismissMessageOfType: \(messageType)")
        
        // You can use this method to unmute audio during videos or fake phone calls
    }
    
    func didDismissMessageOfType(messageType: CarnivalMessageType) {
        print("didDismissMessageOfType: \(messageType)")
        
        // You can use this method to unmute audio during videos or fake phone calls
    }
    
    func willShowInAppNotificationForMessageType(messageType: CarnivalMessageType) {
        print("willShowInAppNotificationForMessageType: \(messageType)")
        
        // You can use this method to do something when an in-app notification is shown
    }
    
    func didShowInAppNotificationForMessageType(messageType: CarnivalMessageType) {
        print("didShowInAppNotificationForMessageType: \(messageType)")
        
        // You can use this method to do something when an in-app notification is shown
    }
    
    //MARK: pressed actions
    @IBAction func getTagsButtonPressed(sender: UIButton) {
        // Asyncronously gets the tags for this device.
        Carnival.getTagsInBackgroundWithResponse { (tags, error) in
            print("getTagsInBackgroundWithResponse returned tags: \(tags)")
        }
    }
    
    @IBAction func addTagButtonPressed(sender: UIButton) {
        // Asyncronously adds the tag for this device
        // If the tag is already registered with Carnival, this method does not add the tag again.
        Carnival.addTags(["CARNIVAL_ADD_TAG_EXAMPLE_TAG"]) { (tags, error) in
            print("addTag:inBackgroundWithResponse: returned tags: \(tags)")
        }
    }
    
    @IBAction func setTagsButtonPressed(sender: UIButton) {
        let exampleTags = ["CARNIVAL_SET_TAGS_EXAMPLE_TAG_1", "CARNIVAL_SET_TAGS_EXAMPLE_TAG_2"]
        
        // Asyncronously sets the tags for Carnival for this device
        // Calling this method will overwrite any previously set tags for this device.
        // Passing nil for the tags argument will clear the tags for this device
        Carnival.setTagsInBackground(exampleTags) { (tags, error) in
            print("setTagsInBackground:withResponse: returned tags: \(tags)");
        }
    }
    
    @IBAction func showMessageStreamButtonPressed(sender: UIButton) {
        let closeItem = UIBarButtonItem.whiteCloseButton(forTarget: self, action: "closeButtonPressed:")
        
        // Create a CarnivalStreamViewController and present it like you would any other viewcontroller
        let streamVC = CarnivalStreamViewController()
        streamVC.navigationItem.rightBarButtonItem = closeItem
        
        // You will probably want to wrap the streamviewcontroller in a UINavigationController in order to give it a navigationBar
        let navVC = UINavigationController(rootViewController: streamVC)
        navVC.navigationBar.titleTextAttributes = [NSForegroundColorAttributeName : UIColor.whiteColor()]
        navVC.navigationBar.barTintColor = .blueColor()
        
        self.presentViewController(navVC, animated: true) {
            UIApplication.sharedApplication().setStatusBarStyle(.LightContent, animated: false)
        }
    }

    internal func closeButtonPressed(sender: UIButton) {
        self.dismissViewControllerAnimated(true, completion: nil)
    }
    
    @IBAction func setStringButtonPressed(sender: UIButton) {
        Carnival.setString("example_string", forKey: "example_string_key") { error in
            print("setString returned with possible error: \(error)")
        }
    }
    
    @IBAction func setFloatButtonPressed(sender: UIButton) {
        Carnival.setFloat(1.23, forKey: "example_float_key") { error in
            print("setFloat returned with possible error: \(error)")
        }
    }
    
    @IBAction func setBooleanButtonPressed(sender: UIButton) {
        Carnival.setBool(true, forKey: "example_bool_key") { error in
            print("setBOOL returned with possible error: \(error)")
        }
    }
    
    @IBAction func setDateButtonPressed(sender: UIButton) {
        Carnival.setDate(NSDate(), forKey: "example_date_key") { error in
            print("setDate returned with possible error: \(error)")
        }
    }
    
    @IBAction func setIntegerButtonPressed(sender: UIButton) {
        Carnival.setInteger(123, forKey: "example_integer_key") { error in
            print("setInteger returned with possible error: \(error)")
        }
    }
    
    @IBAction func removeStringButtonPressed(sender: UIButton) {
        Carnival.removeAttributeWithKey("example_string_key") { error in
            print("removeAttribute returned with possible error: \(error)")
        }
    }
    
    @IBAction func setUserIDButtonPressed(sender: UIButton) {
        Carnival.setUserId("example_user_id") { error in
            print("setUserID returned with possible error: \(error)")
        }
    }
}