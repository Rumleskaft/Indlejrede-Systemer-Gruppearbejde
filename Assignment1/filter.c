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
static int lowcounter = 0, highcounter = 0, derivcounter = 0, wndcounter = 0;

int filt(int a){

    lowcounter = loopCheck(lowcounter, l1);
        printf("%i%s", lowcounter, "   " );
	int b = lowPassFilt(a);
        printf("%i%s", b, "   " );
    
    highcounter = loopCheck(highcounter, l2);
	int c = highPassFilt(b);
        printf("%i%s", c, "   " );
    derivcounter = loopCheck(derivcounter, l3);
    
	int d = derivativeFilt(c);
            printf("%i%s", d, "   " );
	int e = squaringFilt(d);
            printf("%i%s", e, "   " );
    wndcounter = loopCheck(wndcounter, l4);
    
	int f = windowFilt(e);
    printf("%i\n", f);
    pushcounter();
    
	return f;
}

// lowpass filter
int lowPassFilt(int input){
	lowArray[loopCheck(lowcounter, l1)] = input;
    return (2 * highArray[loopCheck(highcounter - 1, l2)])
       - (highArray[(loopCheck(highcounter - 2, l2))])
     + (lowArray[loopCheck(lowcounter, l1)] - 2*lowArray[loopCheck(lowcounter-6, l1)]+lowArray[loopCheck(lowcounter-12, l1)])/32 ;
}

// highpass filter
int highPassFilt(int input){
	highArray[loopCheck(highcounter, l2)] = input;
    
	return derivArray[loopCheck(derivcounter - 1, l2)] - (highArray[highcounter])/32 + highArray[loopCheck(highcounter - 16, l2)] - highArray[loopCheck(highcounter - 17, l2)] + (highArray[loopCheck(highcounter - 32, l2)])/32;
}

int derivativeFilt(int input){
    
	derivArray[loopCheck(derivcounter,l3)] = input;
    
	return (2 * derivArray[loopCheck(derivcounter,l3)] + derivArray[loopCheck(derivcounter - 1, l3)] - derivArray[loopCheck(derivcounter - 3, l3)] - 2 * derivArray[loopCheck(derivcounter - 4, l3)])/8;
}

int squaringFilt(int input){
	return input*input;
}

int windowFilt(int input){
    int output = 0;
	windowArray[loopCheck(wndcounter,l4)] = input;
	for(int i = 0; i<l4; i++)	{
		output += windowArray[i];
	}
	return output/l4;
}

   // checks if the pointer is out of bounds
int loopCheck(int number, int length)	{
    if(number<0){
        return number+length;
    } else
        return number%length;
}


    // increments all pointers
void pushcounter(){
    lowcounter++;
    highcounter++;
    derivcounter++;
    wndcounter++;
}
