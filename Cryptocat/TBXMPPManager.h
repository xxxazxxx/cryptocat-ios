//
//  TBXMPPManager.h
//  Cryptocat
//
//  Created by Thomas Balthazar on 23/09/13.
//  Copyright (c) 2013 Thomas Balthazar. All rights reserved.
//
//  This file is part of Cryptocat for iOS.
//
//  Cryptocat for iOS is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Cryptocat for iOS is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with Cryptocat for iOS.  If not, see <http://www.gnu.org/licenses/>.
//

#import <Foundation/Foundation.h>

@class XMPPMessage, XMPPJID, XMPPRoom, XMPPStream, TBBuddy;
@protocol TBXMPPManagerDelegate;

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
@interface TBXMPPManager : NSObject

@property (nonatomic, weak) id <TBXMPPManagerDelegate> delegate;
@property (nonatomic, readonly) TBBuddy *me;
@property (nonatomic, strong) NSMutableArray *buddies;
@property (nonatomic, readonly) XMPPStream *xmppStream;
@property (nonatomic, readonly) XMPPRoom *xmppRoom;
@property (nonatomic, assign) BOOL isConnected;
@property (nonatomic, assign) BOOL isConnecting;

- (id)init;
- (BOOL)connectToRoomName:(NSString *)roomName withNickname:(NSString *)nickname;
- (void)disconnect;

@end

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
@protocol TBXMPPManagerDelegate <NSObject>

@required

- (void)XMPPManager:(TBXMPPManager *)XMPPManager didJoinRoom:(XMPPRoom *)room;
- (void)XMPPManager:(TBXMPPManager *)XMPPManager didReceiveMessage:(XMPPMessage *)message;
- (void)XMPPManagerDidFailToAuthenticate:(TBXMPPManager *)XMPPManager;
- (void)XMPPManagerDidFailToConnect:(TBXMPPManager *)XMPPManager;
- (void)XMPPManagerDidDisconnect:(TBXMPPManager *)XMPPManager;
- (void)XMPPManagerDidStartReconnecting:(TBXMPPManager *)XMPPManager;

- (void)XMPPManager:(TBXMPPManager *)XMPPManager buddyDidSignIn:(TBBuddy *)buddy;
- (void)XMPPManager:(TBXMPPManager *)XMPPManager buddyDidGoAway:(TBBuddy *)buddy;
- (void)XMPPManager:(TBXMPPManager *)XMPPManager buddyDidSignOut:(TBBuddy *)buddy;
- (void)XMPPManager:(TBXMPPManager *)XMPPManager
didTryToRegisterAlreadyInUseUsername:(NSString *)username;
@end