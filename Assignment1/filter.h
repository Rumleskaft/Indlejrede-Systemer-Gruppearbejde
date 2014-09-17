//
//  filter.h
//  Assignment1
//
//  Created by Daniel Blyme Grundtvig on 10/09/14.
//  Copyright (c) 2014 Daniel Blyme Grundtvig. All rights reserved.
//

#ifndef Assignment1_filter_h
#define Assignment1_filter_h

int filt(int x);
int loopCheck(int number, int limit);
int lowPassFilt(int input);
int highPassFilt(int input);
int derivativeFilt(int input);
int squaringFilt(int input);
int windowFilt(int input);
void pushcounter();

#endif
