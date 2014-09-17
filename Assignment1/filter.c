//
//  filter.c
//  Assignment1
//
//  Created by Daniel Blyme Grundtvig on 10/09/14.
//  Copyright (c) 2014 Daniel Blyme Grundtvig. All rights reserved.
//

#include <stdio.h>
#include "filter.h"

int lowArray[13], highArray[32], derivArray[4], windowArray[30];
int lowptr, highptr, derivptr, wndptr;

int filt(int a){
    
    lowptr = loopCheck(lowptr, sizeof(lowArray));
    
	int b = lowPassFilt(a);
    
    highptr = loopCheck(highptr, sizeof(highArray));
    
	int c = highPassFilt(b);
    
    derivptr = loopCheck(derivptr, sizeof(highArray));
    
	int d = derivativeFilt(c);
    
	int e = squaringFilt(d);
    
    wndptr = loopCheck(wndptr, sizeof(windowArray));
    
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
	return = derivArray[loopCheck(derivptr - 1, sizeof(derivArray))] - highArray[highptr]/32 + highArray[loopCheck(highptr - 16, sizeof(highArray))] - highArray[loopCheck(pointer - 17, sizeof(highArray))] + (highArray[loopCheck(pointer + 1, sizeof(highArray))])/32;
}

int derivativeFilt(int input){
	derivArray[pointer] = input;

	output = 1/8 * (2 * derivArray[pointer] + derivArray[loopCheck(pointer - 1, sizeof(derivArray))] - derivArray[loopCheck(pointer - 3, sizeof(derivArray))] - 2 * derivArray[loopCheck(pointer - 4, sizeof(derivArray))]);

	return output;

}

int squaringFilt(int input){
	return input^2;
}

int windowFilt(int input){
    int N = sizeof(windowArray);
	windowArray[pointer] = input;

	for(int i = 0; i<N; i++)	{
		output += windowArray[i];
	}
	output = 1/N * output;

	return output;
}

   // checks if the pointer is out of bounds
int loopCheck(int number, int limit)	{
	if(number >= limit)	{
		return number % limit;
	}
	return number;
}

    // increments all pointers
void pushptr{
    lowptr++;
    highptr++;
    derivptr++;
    wndptr++;
}
