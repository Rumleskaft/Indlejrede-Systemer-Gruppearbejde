//
//  main.c
//  Assignment1
//
//  Created by Daniel Blyme Grundtvig on 10/09/14.
//  Copyright (c) 2014 Daniel Blyme Grundtvig. All rights reserved.
//

#include <stdio.h>
#include "sensor.h"
#include "filter.h"
// int[30] yArray;

int main() {
    // floop
    int x = getNextData();
    int y = filt(x);
    /*peakDetection()
    yArray.push(y)*/
    
    return 0;
}
