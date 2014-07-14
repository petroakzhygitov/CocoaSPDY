//
//  SPDYSession.h
//  SPDY
//
//  Copyright (c) 2014 Twitter, Inc. All rights reserved.
//  Licensed under the Apache License v2.0
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Created by Michael Schore and Jeffrey Pinner.
//

#import <Foundation/Foundation.h>

@class SPDYConfiguration;
@class SPDYOrigin;
@class SPDYProtocol;
@class SPDYSessionManager;

@interface SPDYSession : NSObject

@property (nonatomic, weak) SPDYSessionManager *manager;
@property (nonatomic, readonly) SPDYOrigin *origin;
@property (nonatomic, readonly) bool isCellular;
@property (nonatomic, readonly) bool isOpen;

- (id)initWithOrigin:(SPDYOrigin *)origin
       configuration:(SPDYConfiguration *)configuration
            cellular:(bool)cellular
               error:(NSError **)pError;
- (void)dispatchRequest:(SPDYProtocol *)protocol;
- (void)cancelRequest:(SPDYProtocol *)protocol;
- (void)close;

@end
