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
int yArray[30];

int main() {
    // floop
    
    int x = getNextData();
    printf("%d", x);
    int y = filt(x);
    printf("%d", y);
    yArray[0] = y;
    
    /*peakDetection()
    yArray.push(y)*/
    
    return 0;
}
