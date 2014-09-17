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
int outputArray[30], ptr = 0;

int main() {
    // floop
    int i;
    for(i=0; i<100; i++){
        int x = getNextData();
        int y = filt(x);
        outputArray[0] = y;
    }
    /*peakDetection()
    yArray.push(y)*/
    
    return 0;

}
