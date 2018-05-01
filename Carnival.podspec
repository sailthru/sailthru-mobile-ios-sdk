Pod::Spec.new do |s|
	s.name 				= 'Carnival'
        s.version 			= '7.3.0'
	s.summary 			= 'Carnival iOS SDK for integrating with http://carnival.io messaging and analytics service.'
	s.author			= {
		'Carnival Mobile' => 'support@sailthru.com'
	}
	s.homepage 			= 'http://docs.carnival.io'
	s.source 			= {
		:git => 'https://github.com/carnivalmobile/carnival-ios-sdk.git',
		:tag => s.version.to_s
	}
	s.source_files = 'Carnival.framework/Headers/*.h'
	s.xcconfig 			= {
		'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/Carnival/**"'
	}
	s.platform = :ios
	s.ios.deployment_target = '8.0'
	s.resources 		= 'Carnival.framework/*.png'
	s.public_header_files = 'Carnival.framework/Headers/*.h'
	s.vendored_frameworks = 'Carnival.framework'
	s.preserve_paths 	= 'Carnival.framework'
	s.frameworks 		= 'UIKit', 'Foundation', 'CoreLocation', 'CoreGraphics', 'QuartzCore', 'UserNotifications'
	s.license = {:type => 'commercial', :text =>'Please refer to our privacy policy and terms of service at http://carnival.io'}
	s.requires_arc = true
end
