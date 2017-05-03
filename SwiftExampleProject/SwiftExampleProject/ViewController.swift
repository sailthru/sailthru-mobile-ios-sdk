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
import Carnival

class ViewController: UIViewController, CarnivalMessageStreamDelegate, CLLocationManagerDelegate {
    var locationManager: CLLocationManager? = nil
    
    //MARK: view lifecycle
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.setupLocationManager()
        
        CarnivalMessageStream.setDelegate(self)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        UIApplication.shared.setStatusBarStyle(.default, animated: false)
    }
    
    override func viewDidAppear(_ animated: Bool) {
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
            Carnival.update(lastLocation)
        }
    }
    
    //MARK: CarnivalMessageStreamDelegate
    func willShowMessage(of messageType: CarnivalMessageType) {
        print("willShowMessageOfType: \(messageType)")
        
        // You can use this method to mute audio during videos
    }
    
    func didShowMessage(of messageType: CarnivalMessageType) {
        print("didShowMessageOfType: \(messageType)")
        
        // You can use this method to mute audio during videos
    }
    
    func willDismissMessage(of messageType: CarnivalMessageType) {
        print("willDismissMessageOfType: \(messageType)")
        
        // You can use this method to unmute audio during videos
    }
    
    func didDismissMessage(of messageType: CarnivalMessageType) {
        print("didDismissMessageOfType: \(messageType)")
        
        // You can use this method to unmute audio during videos
    }
    
    func willShowInAppNotification(for messageType: CarnivalMessageType) {
        print("willShowInAppNotificationForMessageType: \(messageType)")
        
        // You can use this method to do something when an in-app notification is shown
    }
    
    func didShowInAppNotification(for messageType: CarnivalMessageType) {
        print("didShowInAppNotificationForMessageType: \(messageType)")
        
        // You can use this method to do something when an in-app notification is shown
    }
    
    //MARK: pressed actions
    @IBAction func setStringButtonPressed(_ sender: UIButton) {
        let attributes = CarnivalAttributes()
        
        attributes.setString("example_string", forKey: "example_string_key")
        
        Carnival.setAttributes(attributes) { error in
            print("setAttributes returned with possible error: \(error)")
        }
    }
    
    @IBAction func setFloatButtonPressed(_ sender: UIButton) {
        let attributes = CarnivalAttributes()
        
        attributes.setFloat(1.1, forKey: "example_float_key")
        
        Carnival.setAttributes(attributes) { error in
            print("setAttributes returned with possible error: \(error)")
        }
    }
    
    @IBAction func setBooleanButtonPressed(_ sender: UIButton) {
        let attributes = CarnivalAttributes()
        
        attributes.setBool(true, forKey: "example_bool_key")
        
        Carnival.setAttributes(attributes) { error in
            print("setAttributes returned with possible error: \(error)")
        }
    }
    
    @IBAction func setDateButtonPressed(_ sender: UIButton) {
        let attributes = CarnivalAttributes()
        
        attributes.setDate(Date(), forKey: "example_date_key")
        
        Carnival.setAttributes(attributes) { error in
            print("setAttributes returned with possible error: \(error)")
        }
    }
    
    @IBAction func setIntegerButtonPressed(_ sender: UIButton) {
        let attributes = CarnivalAttributes()
        
        attributes.setInteger(123, forKey: "example_integer_key")
        
        Carnival.setAttributes(attributes) { error in
            print("setAttributes returned with possible error: \(error)")
        }
    }
    
    @IBAction func removeStringButtonPressed(_ sender: UIButton) {
        Carnival.removeAttribute(withKey: "example_string_key") { error in
            print("removeAttribute returned with possible error: \(error)")
        }
    }
    
    @IBAction func setUserIDButtonPressed(_ sender: UIButton) {
        Carnival.setUserId("example_user_id") { error in
            print("setUserID returned with possible error: \(error)")
        }
    }
}
