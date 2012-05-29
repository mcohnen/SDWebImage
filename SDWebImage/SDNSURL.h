//
//  SDNSURL.h
//  Snap
//
//  Created by Miguel Cohnen de la Cámara on 5/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SDNSURL : NSURL

@property (nonatomic, copy) NSString *cacheKey;
@property (nonatomic, readonly) BOOL isEmptyURL;

+ (SDNSURL *)URLWithString:(NSString *)url cacheKey:(NSString *)cacheKey;

@end
