/*
 *     Generated by class-dump 3.1.1.
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2006 by Steve Nygard.
 */

#import <UIKit/UIView.h>

@class NSMutableArray, UISegmentedSelectionIndicator;

@interface UISegmentedControl : UIView
{
    NSMutableArray *_segments;
    int _selectedSegment;
    UISegmentedSelectionIndicator *_selectionIndicator;
    id _delegate;
    struct {
        unsigned int style:2;
        unsigned int showsDisclosure:1;
        unsigned int delegateSelectedSegmentChanged:1;
        unsigned int delegateDisclosureButtonClicked:1;
        unsigned int momentaryClick:1;
        unsigned int reserved:26;
    } _segmentedControlFlags;
}

+ (float)defaultHeight;	// IMP=0x3240f23c
+ (float)defaultHeightForStyle:(int)fp8;	// IMP=0x3240f21c
- (void)addSegmentWithTitle:(id)fp8;	// IMP=0x32410198
- (void)dealloc;	// IMP=0x3240f430
- (void)drawRect:(struct CGRect)fp8;	// IMP=0x3240fcd4
- (id)initWithFrame:(struct CGRect)fp8;	// IMP=0x3240f248
- (id)initWithFrame:(struct CGRect)fp8 withStyle:(int)fp24 withItems:(id)fp28;	// IMP=0x3240f308
- (void)insertSegment:(int)fp8 withImage:(id)fp12 animated:(BOOL)fp16;	// IMP=0x3240f61c
- (void)insertSegment:(int)fp8 withTitle:(id)fp12 animated:(BOOL)fp16;	// IMP=0x3240f5f0
- (void)layoutSubviews;	// IMP=0x32411b20
- (void)mouseDown:(struct __GSEvent *)fp8;	// IMP=0x3240fe5c
- (void)mouseDragged:(struct __GSEvent *)fp8;	// IMP=0x32410190
- (void)mouseUp:(struct __GSEvent *)fp8;	// IMP=0x32410194
- (int)numberOfSegments;	// IMP=0x3240f938
- (void)removeAllSegments;	// IMP=0x3240f648
- (void)removeSegment:(int)fp8 animated:(BOOL)fp12;	// IMP=0x32410a64
- (void)selectSegment:(int)fp8;	// IMP=0x3240f984
- (int)selectedSegment;	// IMP=0x3240f96c
- (void)setDelegate:(id)fp8;	// IMP=0x3240f484
- (void)setEnabled:(BOOL)fp8 forSegment:(int)fp12;	// IMP=0x3240f8a0
- (void)setFrame:(struct CGRect)fp8;	// IMP=0x3240fbc0
- (void)setImage:(id)fp8 forSegment:(int)fp12;	// IMP=0x3240f73c
- (void)setImagePadding:(struct CGSize)fp8 forSegment:(int)fp16;	// IMP=0x3240f7a4
- (void)setMomentaryClick:(BOOL)fp8;	// IMP=0x3240f5d8
- (void)setSelectedSegment:(int)fp8;	// IMP=0x324101ec
- (void)setShowsDisclosure:(BOOL)fp8;	// IMP=0x3240f500
- (void)setTitle:(id)fp8 forSegment:(int)fp12;	// IMP=0x3240f6d4
- (void)setWidth:(float)fp8 forSegment:(int)fp12;	// IMP=0x3240f814

@end

