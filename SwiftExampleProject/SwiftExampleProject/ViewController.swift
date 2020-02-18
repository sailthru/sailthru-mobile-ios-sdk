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
import SailthruMobile

class ViewController: UIViewController, STMMessageStreamDelegate, CLLocationManagerDelegate {
    var locationManager: CLLocationManager? = nil
    let sailthruMobile = SailthruMobile()
    
    //MARK: view lifecycle
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.setupLocationManager()
        
        STMMessageStream().setDelegate(self)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        UIApplication.shared.setStatusBarStyle(.default, animated: false)
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        self.startLocationTrackingInBackground()
        
        sailthruMobile.deviceID { deviceID, error in
            print("deviceID for current device: \(deviceID ?? "(No ID)")), with possible error: \(error?.localizedDescription ?? "(No Error)")")
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
        if authorizationStatus != .denied && authorizationStatus != .restricted {
            if let manager = self.locationManager {
                // Check if we are on iOS 8, where we have to requet permissions differently than on previous iOS versions
                if #available(iOS 8.0, *) {
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
        if authorizationStatus != .denied && authorizationStatus != .restricted {
            if let manager = self.locationManager {
                // Check if we are on iOS 8, where we have to requet permissions differently than on previous iOS versions
                if #available(iOS 8.0, *) {
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
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        // Send the last location object as that is the most recent one always
        if let lastLocation = locations.last {
            sailthruMobile.update(lastLocation)
        }
    }
    
    //MARK: CarnivalMessageStreamDelegate
    func willShowMessage(of messageType: STMMessageType) {
        print("willShowMessageOfType: \(messageType)")
        
        // You can use this method to mute audio during videos
    }
    
    func didShowMessage(of messageType: STMMessageType) {
        print("didShowMessageOfType: \(messageType)")
        
        // You can use this method to mute audio during videos
    }
    
    func willDismissMessage(of messageType: STMMessageType) {
        print("willDismissMessageOfType: \(messageType)")
        
        // You can use this method to unmute audio during videos
    }
    
    func didDismissMessage(of messageType: STMMessageType) {
        print("didDismissMessageOfType: \(messageType)")
        
        // You can use this method to unmute audio during videos
    }
    
    func willShowInAppNotification(for messageType: STMMessageType) {
        print("willShowInAppNotificationForMessageType: \(messageType)")
        
        // You can use this method to do something when an in-app notification is shown
    }
    
    func didShowInAppNotification(for messageType: STMMessageType) {
        print("didShowInAppNotificationForMessageType: \(messageType)")
        
        // You can use this method to do something when an in-app notification is shown
    }
    
    //MARK: pressed actions
    @IBAction func setStringButtonPressed(_ sender: UIButton) {
        let attributes = STMAttributes()
        
        attributes.setString("example_string", forKey: "example_string_key")
        
        sailthruMobile.setAttributes(attributes) { (error) in
            print("setAttributes returned with possible error: \(error?.localizedDescription ?? "(No Error)")")
        }
    }
    
    @IBAction func setFloatButtonPressed(_ sender: UIButton) {
        let attributes = STMAttributes()
        
        attributes.setFloat(1.1, forKey: "example_float_key")
        
        sailthruMobile.setAttributes(attributes) { error in
            print("setAttributes returned with possible error: \(error?.localizedDescription ?? "(No Error)")")
        }
    }
    
    @IBAction func setBooleanButtonPressed(_ sender: UIButton) {
        let attributes = STMAttributes()
        
        attributes.setBool(true, forKey: "example_bool_key")
        
        sailthruMobile.setAttributes(attributes) { error in
            print("setAttributes returned with possible error: \(error?.localizedDescription ?? "(No Error)")")
        }
    }
    
    @IBAction func setDateButtonPressed(_ sender: UIButton) {
        let attributes = STMAttributes()
        
        attributes.setDate(Date(), forKey: "example_date_key")
        
        sailthruMobile.setAttributes(attributes) { error in
            print("setAttributes returned with possible error: \(error?.localizedDescription ?? "(No Error)")")
        }
    }
    
    @IBAction func setIntegerButtonPressed(_ sender: UIButton) {
        let attributes = STMAttributes()
        
        attributes.setInteger(123, forKey: "example_integer_key")
        
        sailthruMobile.setAttributes(attributes) { error in
            print("setAttributes returned with possible error: \(error?.localizedDescription ?? "(No Error)")")
        }
    }
    
    @IBAction func removeStringButtonPressed(_ sender: UIButton) {
        sailthruMobile.removeAttribute(withKey: "example_string_key") { error in
            print("removeAttribute returned with possible error: \(error?.localizedDescription ?? "(No Error)")")

        }
    }
    
    @IBAction func setUserIDButtonPressed(_ sender: UIButton) {
        sailthruMobile.setUserId("example_user_id") { error in
            print("setUserID returned with possible error: \(error?.localizedDescription ?? "(No Error)")")
        }
    }
}
