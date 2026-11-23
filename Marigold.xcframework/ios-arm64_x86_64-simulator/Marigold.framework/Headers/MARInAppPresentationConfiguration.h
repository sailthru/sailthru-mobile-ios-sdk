#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MARInAppPresentationStyle) {
    MARInAppPresentationStyleAutomatic,
    MARInAppPresentationStyleBanner,
    MARInAppPresentationStyleModal,
    MARInAppPresentationStyleFullScreen
};

typedef NS_ENUM(NSInteger, MARInAppBannerPosition) {
    MARInAppBannerPositionAutomatic,
    MARInAppBannerPositionTop,
    MARInAppBannerPositionBottom
};

typedef NS_ENUM(NSInteger, MARInAppImageContentMode) {
    MARInAppImageContentModeAutomatic,
    MARInAppImageContentModeAspectFit,
    MARInAppImageContentModeAspectFill
};

typedef NS_ENUM(NSInteger, MARInAppLinkBehavior) {
    MARInAppLinkBehaviorAutomatic,
    MARInAppLinkBehaviorFollowLink,
    MARInAppLinkBehaviorShowMessageWithButton
};

/**
 * Local settings for the SDK's native in-app UI. For each field, valid message
 * presentation settings take priority over callback settings, then app
 * defaults, then SDK defaults. Nil values and Automatic enums inherit.
 * Native-frame styling preserves campaign HTML. Presentation callbacks still
 * decide whether the SDK displays a message, regardless of its payload settings.
 */
@interface MARInAppPresentationConfiguration : NSObject <NSCopying>

/** Creates settings from JSON-compatible presentation fields, without the message payload envelope.
 * Missing or invalid fields inherit. Explicit false and zero values are preserved. */
+ (instancetype)configurationWithDictionary:(NSDictionary<NSString *, id> *)dictionary NS_SWIFT_NAME(from(dictionary:));

/**
 * Editable starting points. Each call returns a new configuration; unspecified
 * fields inherit app/SDK defaults, and payload settings still take priority.
 * Use in a display decision, or assign to the matching presentationDefaults field.
 */
/** Text-only banner, 12-point corners and a five-second duration. */
+ (instancetype)compactBanner NS_SWIFT_NAME(compactBanner());
/** Image-led centred modal, aspect-fit image and manual dismissal. */
+ (instancetype)imageModal NS_SWIFT_NAME(imageModal());
/** Full-screen message content with a native "Open link" button when a URL exists. */
+ (instancetype)contentFirstFullScreen NS_SWIFT_NAME(contentFirstFullScreen());

/** Selects banner or modal for an in-app notification. Detail requests use full-screen options. */
@property (nonatomic) MARInAppPresentationStyle presentationStyle;
@property (nonatomic) MARInAppBannerPosition bannerPosition;

/**
 * Full-screen only. FollowLink opens deep links directly and web links in the detail view (the SDK default).
 * ShowMessageWithButton displays the campaign content, then offers a native button:
 * web links load in this full-screen view; deep links open their app. If the server
 * redirects instead of providing content, the SDK follows the message link directly.
 * Automatic inherits. Messages without a URL continue using the campaign HTML.
 */
@property (nonatomic) MARInAppLinkBehavior linkBehavior;
/** Native link-button label; nil or blank inherits. Defaults to "Open link". */
@property (nullable, nonatomic, copy) NSString *linkButtonTitle;

/** For full-screen messages, these style the native frame and its title/controls. */
@property (nullable, nonatomic, strong) UIColor *backgroundColor;
@property (nullable, nonatomic, strong) UIColor *titleColor;
@property (nullable, nonatomic, strong) UIColor *bodyTextColor;
@property (nullable, nonatomic, strong) UIColor *closeButtonColor;
/** Modal backdrop colour and opacity (0...1) are configured independently. */
@property (nullable, nonatomic, strong) UIColor *backdropColor;
@property (nullable, nonatomic, copy) NSNumber *backdropOpacity;

/** Base fonts, including family, point size and weight. The SDK scales them for Dynamic Type. */
@property (nullable, nonatomic, strong) UIFont *titleFont;
@property (nullable, nonatomic, strong) UIFont *bodyFont;

/** Non-negative values in points. Apply to popup surfaces only. */
@property (nullable, nonatomic, copy) NSNumber *cornerRadius;
@property (nullable, nonatomic, copy) NSNumber *outerSpacing;
@property (nonatomic) MARInAppImageContentMode imageContentMode;
/** NSNumber booleans. Popup images are shown only when the message has an image. */
@property (nullable, nonatomic, copy) NSNumber *showsImage;
@property (nullable, nonatomic, copy) NSNumber *showsCloseButton;
/** Swipe for banners and modals, tap outside for modals, screen-edge swipe for full-screen. An accessible dismissal remains available. */
@property (nullable, nonatomic, copy) NSNumber *allowsGestureDismissal;

/**
 * Popup display duration in seconds, starting once fully visible. Zero means manual
 * dismissal; nil inherits. Full-screen messages always require manual dismissal.
 * Invalid numeric values (negative, non-finite, or opacity > 1) are ignored during
 * resolution so the next valid default is used. Accessibility can extend the duration.
 */
@property (nullable, nonatomic, copy) NSNumber *displayDuration;

@end

/** App-wide defaults, with independent settings for each presentation format. */
@interface MARInAppPresentationDefaults : NSObject <NSCopying>

/** Banner by default. Only Banner and Modal select a notification format. */
@property (nonatomic) MARInAppPresentationStyle notificationStyle;
/** Each configuration starts empty; unspecified fields inherit SDK defaults. */
@property (nonatomic, copy) MARInAppPresentationConfiguration *banner;
@property (nonatomic, copy) MARInAppPresentationConfiguration *modal;
@property (nonatomic, copy) MARInAppPresentationConfiguration *fullScreen;

@end

NS_ASSUME_NONNULL_END
