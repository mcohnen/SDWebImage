/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "SDWebImageCompat.h"
#import "SDWebImageDownloaderDelegate.h"
#import "SDWebImageManagerDelegate.h"
#import "SDImageCacheDelegate.h"

extern NSString *const SDWebImageManagerProgressDidUpdateNotification;
extern NSString *const SDWebImageManagerProgressNotificationInfoProgressKey;

typedef enum
{
    SDWebImageRetryFailed = 1 << 0,
    SDWebImageLowPriority = 1 << 1,
    SDWebImageCacheMemoryOnly = 1 << 2,
    SDWebImageScreenScale = 1 << 3,
    SDWebImageCacheDiskUIThread = 1 << 4,
    SDWebImageCacheDiskOnly = 1 << 5,
    SDWebImageIgnorePlaceHolder = 1 << 6,
} SDWebImageOptions;

@interface SDWebImageManager : NSObject <SDWebImageDownloaderDelegate, SDImageCacheDelegate>
{
    NSMutableArray *downloadDelegates;
    NSMutableArray *downloaders;
    NSMutableArray *cacheDelegates;
    NSMutableDictionary *downloaderForURL;
    NSMutableArray *failedURLs;
}

+ (id)sharedManager;
- (UIImage *)imageWithURL:(NSURL *)url;
- (void)downloadWithURL:(NSURL *)url delegate:(id<SDWebImageManagerDelegate>)delegate;
- (void)downloadWithURL:(NSURL *)url delegate:(id<SDWebImageManagerDelegate>)delegate options:(SDWebImageOptions)options;
- (void)downloadWithURL:(NSURL *)url delegate:(id<SDWebImageManagerDelegate>)delegate retryFailed:(BOOL)retryFailed __attribute__ ((deprecated)); // use options:SDWebImageRetryFailed instead
- (void)downloadWithURL:(NSURL *)url delegate:(id<SDWebImageManagerDelegate>)delegate retryFailed:(BOOL)retryFailed lowPriority:(BOOL)lowPriority __attribute__ ((deprecated)); // use options:SDWebImageRetryFailed|SDWebImageLowPriority instead
- (void)cancelForDelegate:(id<SDWebImageManagerDelegate>)delegate;

@end
