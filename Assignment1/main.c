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
int counter = 0;
int main() {
    // floop
    while (hasNextData()) {
        printf("%i%s", counter, "   " );
        int x = getNextData();
        int y = filt(x);
        counter++;
       // peakDetection(y);
    }
    
    return 0;
    

}
