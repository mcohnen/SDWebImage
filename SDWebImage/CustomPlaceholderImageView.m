//
//  CustomPlaceholderImageView.m
//  Brewster
//
//  Created by Miguel Cohnen de la Cámara on 2/20/12.
//  Copyright (c) 2012 Brewster. All rights reserved.
//

#import "CustomPlaceholderImageView.h"
#import "SDWebImageManager.h"
#import "UIImageView+WebCache.h"
#import "SDWebImageLoadInfo.h"

@implementation CustomPlaceholderImageView

@synthesize delayShow = _delayShow;

@synthesize delegate = _delegate;

- (id)initWithFrame:(CGRect)frame customPlaceholder:(UIView *)customPlaceholder {
    self = [super initWithFrame:frame];
    if (self) {
        _customPlaceholder = [customPlaceholder retain];
        [self addSubview:_customPlaceholder];
    }
    return self;
}

- (void)dealloc {
    [self cancelCurrentImageLoad];
    [_customPlaceholder release];
    _customPlaceholder = nil;
    _delegate = nil;
    [super dealloc];
}

- (void)webImageManager:(SDWebImageManager *)imageManager didFinishWithInfo:(NSDictionary *)info {
    [super webImageManager:imageManager didFinishWithInfo:info];
    
    [UIView animateWithDuration:0.3 delay:0 options:UIViewAnimationOptionAllowUserInteraction animations:^{
        _customPlaceholder.alpha = 0;
    } completion:^(BOOL finished) {
//        _customPlaceholder.hidden = YES;
    }];
    
    if ([_delegate respondsToSelector:@selector(image:didFinishWithInfo:)]) {
        [_delegate performSelector:@selector(image:didFinishWithInfo:) withObject:self withObject:info];
    }
}

- (void)webImageManagerWillLoadFromDisk:(SDWebImageManager *)manager {
    _customPlaceholder.hidden = NO;
    _customPlaceholder.alpha = 1;
}

- (void)webImageManager:(SDWebImageManager *)imageManager didFailWithError:(NSError *)error {
    _customPlaceholder.hidden = YES;
}

- (void)webImageManagerWillStartDownload:(SDWebImageManager *)imageManager {
    _customPlaceholder.hidden = NO;
    _customPlaceholder.alpha = 1;
}

- (void)layoutSubviews {
    [super layoutSubviews];
    _customPlaceholder.size = self.size;
}

- (void)cancelCurrentImageLoad {
    [super cancelCurrentImageLoad];
//    _customPlaceholder.hidden = YES;
}

@end
