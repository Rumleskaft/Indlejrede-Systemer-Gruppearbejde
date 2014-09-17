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
int outputArray[100], ptr = 0;

int main() {
    // floop
    while (hasNextData()) {
        int x = getNextData();
        filt(x);
    }
    /*peakDetection()
    yArray.push(y)*/
    
    return 0;

}
