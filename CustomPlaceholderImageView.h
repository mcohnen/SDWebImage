//
//  CustomPlaceholderImageView.h
//  Brewster
//
//  Created by Miguel Cohnen de la Cámara on 2/20/12.
//  Copyright (c) 2012 Brewster. All rights reserved.
//

#import "SDWebImageManager.h"
#import "UIImageView+WebCache.h"

@interface CustomPlaceholderImageView : UIImageView {
    id _delegate;
    UIView *_customPlaceholder;
}

@property (nonatomic, assign) id delegate;

- (id)initWithFrame:(CGRect)frame customPlaceholder:(UIView *)customPlaceholder;
- (void)webImageManager:(SDWebImageManager *)imageManager didFinishWithInfo:(NSDictionary *)info;
- (void)webImageManagerWillStartDownload:(SDWebImageManager *)imageManager;

@end
