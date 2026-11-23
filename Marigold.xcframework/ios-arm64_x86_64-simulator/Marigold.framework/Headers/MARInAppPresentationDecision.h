#import <Foundation/Foundation.h>
#import <Marigold/MARInAppPresentationConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MARInAppPresentationAction) {
    MARInAppPresentationActionDisplay,
    MARInAppPresentationActionSuppress,
    MARInAppPresentationActionHandled
};

/** The application's decision for one in-app presentation attempt. */
@interface MARInAppPresentationDecision : NSObject

@property (nonatomic, readonly) MARInAppPresentationAction action;
/** A snapshot of per-message overrides. Nil inherits app and SDK defaults. */
@property (nullable, nonatomic, copy, readonly) MARInAppPresentationConfiguration *configuration;

/** Display the SDK's UI. */
+ (instancetype)display;
/** Display SDK UI with local per-message overrides. The configuration is copied. */
+ (instancetype)displayWithConfiguration:(MARInAppPresentationConfiguration *)configuration
    NS_SWIFT_NAME(display(configuration:));
/** Suppress this attempt without displaying custom UI. */
+ (instancetype)suppress;
/** The application owns rendering and impression registration for this attempt. */
+ (instancetype)handled;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
