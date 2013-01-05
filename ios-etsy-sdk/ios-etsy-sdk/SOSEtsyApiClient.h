/*
 Copyright 2012 Sean O' Shea
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <Foundation/Foundation.h>

#import "SOSEtsyConstants.h"
#import "SOSEtsyListingsRequest.h"

/**
 `SOSEtsyApiClient` provides a _very_ simple read-only interface to the Etsy API.
 The only API method supported provides client applications with the ability to look
 up active listings for a particular shop. Simple.
*/

@interface SOSEtsyApiClient : NSObject

/**
 To interact with the Etsy API, client developers MUST provide an API key.
 See http://www.etsy.com/developers for details on how to get API keys.
 */
@property (nonatomic, retain) NSString *apiKey;

/**
 Singleton accessor method for the SOSEtsyApiClient
 
 @return an instance of a SOSEtsyApiClient
 */
+ (SOSEtsyApiClient*)sharedInstance;

#pragma mark Init

/**
 Sets an API key for a SOSEtsyApiClient.
 
 @param apiKey the API key to set.
 */
- (void)initWithApiKey:(NSString*)apiKey;

#pragma mark Listings

/**
 Retrieves listings based on the listingsRequest
 
 @param listingsRequest defining the specifics of the listings request (includes shop id etc)
 @param successBlock executed when the API call executes successfully.
 @param failureBlock executed when the API call fails to execute.
 */
- (NSOperation*)getListings:(SOSEtsyListingsRequest*)listingsRequest
               successBlock:(SOSEtsySuccessBlock)successBlock
               failureBlock:(SOSEtsyFailureBlock)failureBlock;

@end
