//
//  SDNSURL.m
//  Snap
//
//  Created by Miguel Cohnen de la Cámara on 5/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "SDNSURL.h"

@implementation SDNSURL

@synthesize cacheKey = _cacheKey;

NSString * const empty = @"empty";

+ (SDNSURL *)URLWithString:(NSString *)url cacheKey:(NSString *)cacheKey {
    if (!url) {
        url = empty;
    }
    SDNSURL *ret = [SDNSURL URLWithString:url];
    ret.cacheKey = cacheKey;
    return ret;
}

- (BOOL)isEmptyURL {
    return [self.absoluteString isEqualToString:empty];
}

- (void)dealloc {
    self.cacheKey = nil;
    [super dealloc];
}

@end
