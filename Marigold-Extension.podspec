Pod::Spec.new do |s|
  s.name                    = 'Marigold-Extension'
  s.version                 = '18.1.0'
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
    'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/MarigoldExtension/**"'
  }
  s.platform                = :ios
  s.ios.deployment_target   = '15.6'
  s.license                 = {:type => 'commercial', :text =>'Please refer to our privacy policy and terms of service at https://www.sailthru.com/legal'}
  s.requires_arc            = true
  s.module_name             = 'MarigoldExtension'
  s.source_files            = 'MarigoldExtension.xcframework/ios-*[!-simulator]/MarigoldExtension.framework/Headers/*.h'
  s.vendored_frameworks     = 'MarigoldExtension.xcframework'
  s.public_header_files     = 'MarigoldExtension.xcframework/ios-*[!-simulator]/MarigoldExtension.framework/Headers/*.h'
  s.preserve_paths          = 'MarigoldExtension.xcframework'
  s.frameworks              = 'Foundation', 'UserNotifications'
end
