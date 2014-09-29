//
//  main.c
//  Assignment1
//
//  Created by Daniel Blyme Grundtvig on 10/09/14.
//  Copyright (c) 2014 Daniel Blyme Grundtvig. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "sensor.h"
#include "filter.h"
#include <time.h>
#include "peakDetection.h"
#include <unistd.h>

int main() {
    // floop
    while (hasNextData()) {
        int x = getNextData();
        int y = filt(x);
        //printf("%u\n", (unsigned)time(NULL));
       // sleep(1);

       peakDetection(y);
    }
    //tidsobjekt nedenunder her, den giver jeg til displaydata. men den giver vi til peakdetection istedet. jeg skal lige være sikker på at vi får current time
    return 0;
}
