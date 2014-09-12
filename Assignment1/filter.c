//
//  filter.c
//  Assignment1
//
//  Created by Daniel Blyme Grundtvig on 10/09/14.
//  Copyright (c) 2014 Daniel Blyme Grundtvig. All rights reserved.
//

#include <stdio.h>
#include "filter.h"

int filter(int x){
    int a = x;
    int b = lowPassFilt(a);
    int c = highPassFilt(b);
    int d =derivativeFilt(c);
    int e =squaringFilt(d);
    int f = windowFilt(e);
    return f;
}

int lowPassFilt(int x){
    int lowArray[12];
    return 0;
}

int highPassFilt(int x){
    int highArray[32];
    return 0;
}

int derivativeFilt(int x){
    int derivArray[4];
    return 0;
}

int squaringFilt(int x){
    x=x^2;
    return x;
}

int windowFilt(int x){
    int windowArray[30];
    return 0;
}


