//
//  PSPDFFontInfo.h
//  PSPDFKit
//
//  Copyright 2012 Peter Steinberger. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreText/CoreText.h>

@interface PSPDFFontInfo : NSObject {
	CGFloat _ascent;
	CGFloat _descent;
	NSArray *_encodingArray;
}

@property (nonatomic, assign) CGFloat ascent;
@property (nonatomic, assign) CGFloat descent;
@property (nonatomic, strong) NSString *name;

@property (nonatomic, strong) NSArray *encodingArray;
@property (nonatomic, strong) NSMutableDictionary *toUnicodeMap;

- (id)initWithFontDictionary:(CGPDFDictionaryRef)font;
- (CGFloat)widthForCharacter:(uint16_t)c;
- (BOOL)isMultiByteFont;
- (void)parseToUnicodeMapWithString:(NSString *)cmapString;

+ (NSDictionary *)glyphNames;
+ (NSDictionary *)standardFontWidths;

@end


@interface PDFSimpleFontInfo : PSPDFFontInfo {
	CGFloat widths[256];
}

+ (NSArray *)baseArrayForEncoding:(CFStringEncoding)stringEncoding;

@end


@interface PDFCompositeFontInfo : PSPDFFontInfo {
	CGFloat widths[65536];
}

@end