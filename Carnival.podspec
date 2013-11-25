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
  		'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/Carnival/Resources"' ,
  		'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/Carnival.embeddedframework"',
  		'HEADER_SEARCH_PATHS' => '$(SDKROOT)/usr/include/libz' 
  	} 
  	s.resources 		= 'Carnival.embeddedframework/Carnival.framework/Versions/A/Resources' 
  	s.source_files 		= 'Carnival.embeddedframework/Carnival.framework/Versions/A/Headers/*.h' 
  	s.preserve_paths 	= '**/*.framework', '**/Resources' 
  	s.frameworks 		= 'UIKit', 'Foundation', 'CoreLocation', 'CoreGraphics'
  	s.license = {:type => 'commercial', :text =>'Please refer to http://docs.corepush.com'}

end