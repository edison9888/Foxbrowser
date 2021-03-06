//
//  SGBrowserViewController.h
//  Foxbrowser
//
//  Created by Simon Grätzer on 15.12.12.
//
//
//  Copyright (c) 2012 Simon Peter Grätzer
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import <UIKit/UIKit.h>
#import "SGURLProtocol.h"


@class SGCredentialsPrompt;

// Container for SGWebViewController & SGBlankViewController
@interface SGBrowserViewController : UIViewController <SGHTTPAuthDelegate, UIAlertViewDelegate>

// =========== Abstract =============

/// Adds a tab, don't add the same instance twice!
- (void)addViewController:(UIViewController *)childController;

/// Bring a tab to the frontpage
- (void)showViewController:(UIViewController *)viewController;

// Remove a tap
- (void)removeViewController:(UIViewController *)childController;
- (void)removeIndex:(NSUInteger)index;

// Swap the current view controller. Used to replace the blankView with the webView
- (void)swapCurrentViewControllerWith:(UIViewController *)viewController;

- (void)updateChrome;

@property (readonly, nonatomic) UIViewController *selectedViewController;
@property (readonly, nonatomic) NSUInteger selectedIndex;
@property (readonly, nonatomic) NSUInteger count;
@property (readonly, nonatomic) NSUInteger maxCount;


// ========== Implemented =================

@property (strong, atomic) SGCredentialsPrompt *credentialsPrompt;

// Add and show a SGBlankViewController
- (void)addTab;

- (void)addTabWithURL:(NSURL *)url withTitle:(NSString *)title;

- (void)reload;
- (void)stop;

- (BOOL)isLoading;

- (void)goBack;
- (void)goForward;

- (BOOL)canGoBack;
- (BOOL)canGoForward;

- (BOOL)canStopOrReload;
- (BOOL)canRemoveTab:(UIViewController *)viewController;

- (NSURL *)URL;
- (void)openURL:(NSURL *)url title:(NSString *)title;
- (void)handleURLString:(NSString*)input title:(NSString *)title;

- (void)findInPage:(NSString *)searchPage;

- (void)addSavedTabs;
- (void)saveCurrentTabs;

@end
