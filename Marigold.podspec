Pod::Spec.new do |s|
  s.name                    = 'Marigold'
  s.version                 = '16.0.0'
  s.summary                 = 'Marigold iOS SDK for integrating with https://mobile.sailthru.com messaging and analytics service.'
  s.author                  = {
    'Marigold' => 'support@sailthru.com'
  }
  s.homepage                = 'http://docs.mobile.sailthru.com/'
  s.source                  = {
    :git => 'https://github.com/sailthru/sailthru-mobile-ios-sdk.git',
    :tag => s.version.to_s
  }
  s.xcconfig                = {
    'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/Marigold/**"'
  }
  s.platform                = :ios
  s.ios.deployment_target   = '12.0'
  s.license                 = {:type => 'commercial', :text =>'Please refer to our privacy policy and terms of service at https://www.sailthru.com/legal'}
  s.requires_arc            = true
  s.source_files            = 'Marigold.xcframework/ios-*[!-simulator]/Marigold.framework/Headers/*.h'
  s.resources               = 'Marigold.xcframework/ios-*[!-simulator]/Marigold.framework/*.png'
  s.vendored_frameworks     = 'Marigold.xcframework'
  s.public_header_files     = 'Marigold.xcframework/ios-*[!-simulator]/Marigold.framework/Headers/*.h'
  s.preserve_paths          = 'Marigold.xcframework'
  s.frameworks              = 'UIKit', 'Foundation', 'CoreLocation', 'CoreGraphics', 'QuartzCore', 'UserNotifications'
end
