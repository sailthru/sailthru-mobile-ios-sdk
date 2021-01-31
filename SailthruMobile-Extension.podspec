Pod::Spec.new do |s|
  s.name 				    = 'SailthruMobile-Extension'
  s.version 			    = '12.0.0-beta'
  s.summary 			    = 'Sailthru Mobile iOS SDK for integrating with https://mobile.sailthru.com messaging and analytics service.'
  s.author			    = {
    'Sailthru Mobile' => 'support@sailthru.com'
  }
  s.homepage 			    = 'http://docs.mobile.sailthru.com/'
  s.source 			    = {
    :git => 'https://github.com/carnivalmobile/carnival-ios-sdk.git',
    :tag => s.version.to_s
  }
  s.xcconfig 			    = {
    'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/SailthruMobileExtension/**"'
  }
  s.platform              = :ios
  s.ios.deployment_target = '10.0'
  s.license               = {:type => 'commercial', :text =>'Please refer to our privacy policy and terms of service at https://www.sailthru.com/legal'}
  s.requires_arc          = true
  s.module_name           = 'SailthruMobileExtension'
  s.source_files          = 'SailthruMobileExtension.xcframework/ios-*[!-simulator]/SailthruMobileExtension.framework/Headers/*.h'
  s.vendored_frameworks   = 'SailthruMobileExtension.xcframework'
  s.public_header_files   = 'SailthruMobileExtension.xcframework/ios-*[!-simulator]/SailthruMobileExtension.framework/Headers/*.h'
  s.preserve_paths        = 'SailthruMobileExtension.xcframework'
  s.frameworks            = 'Foundation', 'UserNotifications'
end
