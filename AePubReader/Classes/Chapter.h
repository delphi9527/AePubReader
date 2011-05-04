//
//  Chapter.h
//  AePubReader
//
//  Created by Federico Frappi on 08/04/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
@class Chapter;

@protocol ChapterProtocol <NSObject>
@required
- (void) chapterDidFinishLoad:(Chapter*)chapter;
@end

@interface Chapter : NSObject <UIWebViewDelegate>{
    NSString* spinePath;
    NSString* title;
    id <ChapterProtocol> delegate;
    int pageCount;
    int chapterIndex;
    CGSize windowSize;
    int fontPercentSize;
}

@property (nonatomic, assign) id delegate;
@property (nonatomic, readonly) int pageCount, chapterIndex;
@property (nonatomic, readonly) NSString *spinePath, *title;

- (id) initWithPath:(NSString*)theSpinePath title:(NSString*)theTitle chapterIndex:(int) theIndex;

- (void) loadChapterWithWindowSize:(CGRect)theWindowSize fontPercentSize:(int) theFontPercentSize;
- (void) webViewDidFinishLoad:(UIWebView*)webView;
- (void) webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error;

@end