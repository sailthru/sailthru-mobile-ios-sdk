Pod::Spec.new do |s|
	s.name 				    = 'SailthruMobile'
  s.version 			    = '12.0.0-beta2'
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
		'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/SailthruMobile/**"'
	}
	s.platform              = :ios
	s.ios.deployment_target = '10.0'
	s.license               = {:type => 'commercial', :text =>'Please refer to our privacy policy and terms of service at https://www.sailthru.com/legal'}
	s.requires_arc          = true
  s.source_files          = 'SailthruMobile.xcframework/ios-*[!-simulator]/SailthruMobile.framework/Headers/*.h'
  s.resources             = 'SailthruMobile.xcframework/ios-*[!-simulator]/SailthruMobile.framework/*.png'
  s.vendored_frameworks   = 'SailthruMobile.xcframework'
  s.public_header_files   = 'SailthruMobile.xcframework/ios-*[!-simulator]/SailthruMobile.framework/Headers/*.h'
  s.preserve_paths        = 'SailthruMobile.xcframework'
  s.frameworks            = 'UIKit', 'Foundation', 'CoreLocation', 'CoreGraphics', 'QuartzCore', 'UserNotifications'
end
