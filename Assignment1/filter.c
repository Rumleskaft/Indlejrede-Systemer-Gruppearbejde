//
//  filter.c
//  Assignment1
//
//  Created by Daniel Blyme Grundtvig on 10/09/14.
//  Copyright (c) 2014 Daniel Blyme Grundtvig. All rights reserved.
//

#include <stdio.h>
#include "filter.h"

const int l1 = 13, l2 = 32, l3 = 4, l4 = 30;
int lowArray[l1], highArray[l2], derivArray[l3], windowArray[l4];
int lowptr, highptr, derivptr, wndptr;

int filt(int a){
    
    lowptr = loopCheck(lowptr, l1);
    
	int b = lowPassFilt(a);
    
    highptr = loopCheck(highptr, l2);
    
	int c = highPassFilt(b);
    
    derivptr = loopCheck(derivptr, l3);
    
	int d = derivativeFilt(c);
    
	int e = squaringFilt(d);
    
    wndptr = loopCheck(wndptr, l4);
    
	int f = windowFilt(e);
    
    pushptr();
    
	return f;
}

int lowPassFilt(int input){
    
	lowArray[lowptr] = input;
	return 2 * highArray[loopCheck(lowptr - 1, sizeof(highArray))] - highArray[loopCheck(lowptr - 2, sizeof(highArray))] + 1/32 *(lowArray[lowptr] - 2 * lowArray[loopCheck(lowptr - 6, sizeof(lowArray))] + lowArray[loopCheck(lowptr - 12, sizeof(lowArray))]);
}

int highPassFilt(int input){
	highArray[highptr] = input;
	return derivArray[loopCheck(highptr - 1, sizeof(derivArray))] - highArray[highptr]/32 + highArray[loopCheck(highptr - 16, sizeof(highArray))] - highArray[loopCheck(highptr - 17, sizeof(highArray))] + (highArray[loopCheck(highptr + 1, sizeof(highArray))])/32;
}

int derivativeFilt(int input){
    
	derivArray[derivptr] = input;
	//return 1/8 * (2 * derivArray[derivptr] + derivArray[loopCheck(derivptr - 1, sizeof(derivArray))] - derivArray[loopCheck(derivptr - 3, sizeof(derivArray))] - 2 * derivArray[loopCheck(derivptr - 4, sizeof(derivArray))]);
    return 0;
}

int squaringFilt(int input){
	return input^2;
}

int windowFilt(int input){
    int N = sizeof(windowArray), output;
	windowArray[wndptr] = input;

	for(int i = 0; i<N; i++)	{
		output += windowArray[i];
	}
	return 1/N * output;
}

   // checks if the pointer is out of bounds
int loopCheck(int number, int limit)	{
	if(number >= limit)	{
		return number % limit;
	}
	return number;
}

    // increments all pointers
void pushptr(){
    lowptr++;
    highptr++;
    derivptr++;
    wndptr++;
}
