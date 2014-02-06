Pod::Spec.new do |s|
	s.name 				= 'Carnival'
	s.version 			= '1.42'
	s.summary 			= 'Carnival iOS SDK for integrating with Carnival.com push service'
	s.author			= {
		'Carnival Labs Ltd' => 'sam@carnivallabs.com'
	}
	s.homepage 			= 'http://docs.corepush.com'
	s.source 			= { 
		:git => 'https://sam_carnival@bitbucket.org/carnivallabs/carnival-ios-sdk.git',
		:tag => s.version.to_s
	} 
  	s.xcconfig 			= { 
  		'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/Carnival.embeddedframework/Resources"' ,
  		'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/Carnival/**"'
  	} 
  	s.resources 		= 'Carnival.embeddedframework/Carnival.framework/Versions/A/Resources' 
  	s.public_header_files = 'Carnival.embeddedframework/Carnival.framework/Versions/A/Headers/*.h'
  	s.vendored_frameworks = 'Carnival.embeddedframework/Carnival.framework'
  	s.preserve_paths 	= 'Carnival.embeddedframework/Carnival.framework' 
  	s.frameworks 		= 'UIKit', 'Foundation', 'CoreLocation', 'CoreGraphics', 'AdSupport'
  	s.license = {:type => 'commercial', :text =>'Please refer to http://docs.corepush.com'}
  	s.requires_arc = true
  	s.library = 'z'

end