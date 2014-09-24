//
//  filter.c
//  Assignment1
//
//  Created by Daniel Blyme Grundtvig on 10/09/14.
//  Copyright (c) 2014 Daniel Blyme Grundtvig. All rights reserved.
//

#include <stdio.h>
#include "filter.h"

static const int l1 = 13, l2 = 33, l3 = 5, l4 = 30;
static int lowArray[l1], highArray[l2], derivArray[l3], windowArray[l4];
static int lowcounter, highcounter, derivcounter, wndcounter;

int filt(int a){
    

    lowcounter = loopCheck(lowcounter, l1);
        printf("%i%s", lowcounter, "   " );
	int b = lowPassFilt(a);
        printf("%i\n", b);
    
    highcounter = loopCheck(highcounter, l2);
       // printf("%i%s", highcounter, "   " );
	int c = highPassFilt(b);
       // printf("%i\n", c);
    derivcounter = loopCheck(derivcounter, l3);
    
	int d = derivativeFilt(c);
    
	int e = squaringFilt(d);
    
    wndcounter = loopCheck(wndcounter, l4);
    
	int f = windowFilt(e);
    
    pushcounter();
    
	return f;
}

// lowpass filter
int lowPassFilt(int input){
	lowArray[loopCheck(lowcounter, l1)] = input;
    return (2 * highArray[loopCheck(lowcounter-1, l2)])
    +    - (highArray[(loopCheck(lowcounter - 2, l2))])
    +    + (lowArray[loopCheck(lowcounter, l1)] - 2*lowArray[loopCheck(lowcounter-6, l1)]+lowArray[loopCheck(lowcounter-12, l1)])/32 ;
}

// highpass filter
int highPassFilt(int input){
	highArray[loopCheck(highcounter, l2)] = input;
    
	return derivArray[loopCheck(highcounter - 1, l2)] - (highArray[highcounter])/32 + highArray[loopCheck(highcounter - 16, l2)] - highArray[loopCheck(highcounter - 17, l2)] + (highArray[loopCheck(highcounter - 32, l2)])/32;
}

int derivativeFilt(int input){
    
	derivArray[loopCheck(derivcounter,l3)] = input;
	return 1/8 * (2 * derivArray[derivcounter] + derivArray[loopCheck(derivcounter - 1, sizeof(derivArray))] - derivArray[loopCheck(derivcounter - 3, sizeof(derivArray))] - 2 * derivArray[loopCheck(derivcounter - 4, l3)]);
}

int squaringFilt(int input){
	return input^2;
}

int windowFilt(int input){
    int output;
	windowArray[wndcounter] = input;

	for(int i = 0; i<l4; i++)	{
		output += windowArray[i];
	}
	return output/l4;
}

   // checks if the pointer is out of bounds
int loopCheck(int number, int length)	{
	if(number >= length)	{
		return (number % length);
    }else if(number<0){
        return length-1-((-number)%(length-1));
    }
	return number;
}


    // increments all pointers
void pushcounter(){
    lowcounter++;
    highcounter++;
    derivcounter++;
    wndcounter++;
}
