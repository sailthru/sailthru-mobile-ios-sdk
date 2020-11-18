Pod::Spec.new do |s|
	s.name 				    = 'SailthruMobile'
    s.version 			    = '11.1.0'
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
	s.ios.deployment_target = '8.0'
	s.license               = {:type => 'commercial', :text =>'Please refer to our privacy policy and terms of service at https://www.sailthru.com/legal'}
	s.requires_arc          = true
    s.source_files          = 'SailthruMobile.framework/Headers/*.h'
    s.resources             = 'SailthruMobile.framework/*.png'
    s.public_header_files   = 'SailthruMobile.framework/Headers/*.h'
    s.vendored_frameworks   = 'SailthruMobile.framework'
    s.preserve_paths        = 'SailthruMobile.framework'
    s.frameworks            = 'UIKit', 'Foundation', 'CoreLocation', 'CoreGraphics', 'QuartzCore', 'UserNotifications'
    s.subspec 'Extension' do |extension|
        extension.source_files           = 'SailthruMobileExtension.framework/Headers/*.h'
        extension.public_header_files    = 'SailthruMobileExtension.framework/Headers/*.h'
        extension.vendored_frameworks    = 'SailthruMobileExtension.framework'
        extension.preserve_paths         = 'SailthruMobileExtension.framework'
        extension.frameworks             = 'Foundation', 'UserNotifications'
    end
end
