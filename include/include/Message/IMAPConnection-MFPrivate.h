/*
 *     Generated by class-dump 3.1.1.
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2006 by Steve Nygard.
 */

#import <Message/IMAPConnection.h>

@interface IMAPConnection (MFPrivate)
- (id)_fetchArgumentForMessageSkeletonsWithHeaders:(id)fp8;	// IMP=0x30b4b91d
- (id)_fetchArgumentForMessageUidsAndFlags;	// IMP=0x30b4a9ad
- (BOOL)_isFetchResponseValid:(id)fp8;	// IMP=0x30b4a9b9
- (id)_readDataOfLength:(int)fp8;	// IMP=0x30b4a88d
- (id)_responseFromSendingCommands:(CDAnonymousStruct7 *)fp8 count:(unsigned int)fp12;	// IMP=0x30b4a9bd
- (void)didFinishCommands:(CDAnonymousStruct7 *)fp8 count:(unsigned int)fp12;	// IMP=0x30b4c689
- (BOOL)sendResponsesForCommand:(CDAnonymousStruct7 *)fp8 toQueue:(id)fp12;	// IMP=0x30b4aa91
@end

