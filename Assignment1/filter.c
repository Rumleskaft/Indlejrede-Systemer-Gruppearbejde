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

int filter(int input){
	int a = input;
	int b = lowPassFilt(a);
	int c = highPassFilt(b);
	int d = derivativeFilt(c);
	int e = squaringFilt(d);
	int f = windowFilt(e);
	return f;
}

int lowPassFilt(int input){
	int pointer;
	int first = 1, output = 0;
	if(first == 1)	{
		lowArray[] = {0};
		pointer = 0;
		first = 0
	}
	lowArray[pointer] = input;

	output = 2 * highArray[loopCheck(highPassFilt.pointer - 1,highArray.sizeof)] - highArray[loopCheck(highPassFilt.pointer - 2, highArray.sizeof] + 1/32 *(lowArray[pointer] - 2 * lowArray[loopCheck(pointer - 6, lowArray.sizeof)] + lowArray[loopCheck(pointer - 12, lowArray.sizeof)]);
	loopCheck(pointer++, lowArray.sizeof);

	return output;
}

int highPassFilt(int input){
	int pointer;
	int first = 1, output = 0;
	if(first == 1)	{
		highArray[] = {0};
		pointer = 0;
		first = 0
	}
	highArray[pointer] = input;

	output = derivArray[loopCheck(derivativeFilt.pointer - 1, derivArray.sizeof)] - highArray[pointer]/32 + highArray[loopCheck(pointer - 16, highArray.sizeof)] - highArray[loopCheck(pointer - 17, highArray.sizeof)] + (highArray[loopCheck(pointer + 1, highArray.sizeof)])/32;
	loopCheck(pointer++, highArray.sizeof);

	return output;
}

int derivativeFilt(int input){
	int pointer;
	int first = 1, output = 0;;
	if(first == 1)	{
		derivArray[] = {0};
		pointer = 0;
		first = 0
	}
	derivArray[pointer] = input;

	output = 1/8 * (2 * derivArray[pointer] + derivArray[loopCheck(pointer - 1, derivArray.sizeof)] - derivArray[loopCheck(pointer - 3, derivArray.sizeof)] - 2 * derivArray[loopCheck(pointer - 4, derivArray.sizeof)]);
	loopCheck(pointer++, derivArray.sizeof);

	return output;
}

int squaringFilt(int input){
	return input^2;
}

int windowFilt(int input){
	int pointer;
	int first = 1, output = 0, N = windowArray.sizeof;
	if(first == 1)	{
		windowArray[] = {0};
		pointer = 0;
		first = 0
	}
	windowArray[pointer] = input;

	for(int i = 0, i < N, i++)	{
		output =+ windowArray[i];
	}
	output = 1/N * output;
	loopCheck(pointer++, windowArray.sizeof);

	return output;
}

int loopCheck(int number, int limit)	{
	if(number >= limit)	{
		return number % limit;
	}
	return number;
}
