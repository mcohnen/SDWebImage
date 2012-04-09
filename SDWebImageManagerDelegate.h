/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

@class SDWebImageManager;

@protocol SDWebImageManagerDelegate <NSObject>

@optional

- (void)webImageManager:(SDWebImageManager *)imageManager didFinishWithImage:(UIImage *)image;
- (void)webImageManager:(SDWebImageManager *)imageManager didFailWithError:(NSError *)error;
- (void)webImageManager:(SDWebImageManager *)imageManager didFinishWithInfo:(NSDictionary *)info;
- (void)webImageManager:(SDWebImageManager *)imageManager didFailWithInfo:(NSDictionary *)info;

- (void)webImageManagerWillStartDownload:(SDWebImageManager *)imageManager;
- (void)webImageManagerWillLoadFromDisk:(SDWebImageManager *)imageManager;

@end
