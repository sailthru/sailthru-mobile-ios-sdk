Pod::Spec.new do |s|
	s.name 				= 'Carnival'
	s.version 			= '3.7.0'
	s.summary 			= 'Carnival iOS SDK for integrating with http://carnival.io messaging and analytics service'
	s.author			= {
		'Carnival Mobile' => 'support@carnival.io'
	}
	s.homepage 			= 'http://docs.carnival.io'
	s.source 			= { 
		:git => 'https://github.com/carnivalmobile/carnival-ios-sdk.git',
		:tag => s.version.to_s
	} 
	s.xcconfig 			= {
		'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/Carnival/**"'
	}
	s.platform = :ios
	s.ios.deployment_target = '7.0' 
	s.resources 		= 'Carnival.embeddedframework/Carnival.framework/Versions/A/Resources/CarnivalResources.bundle' 
	s.public_header_files = 'Carnival.embeddedframework/Carnival.framework/Versions/A/Headers/*.h'
	s.vendored_frameworks = 'Carnival.embeddedframework/Carnival.framework'
	s.preserve_paths 	= 'Carnival.embeddedframework/Carnival.framework' 
	s.frameworks 		= 'UIKit', 'Foundation', 'CoreLocation', 'CoreGraphics', 'AVFoundation', 'MediaPlayer', 'QuartzCore'
	s.license = {:type => 'commercial', :text =>'Please refer to our privacy policy and terms of service at http://carnivalmobile.com'}
	s.requires_arc = true
end
