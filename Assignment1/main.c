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
#include "display.h"
#include "peakDetection.h"

int counter = 0;
int main() {
    // floop
    while (hasNextData()) {
        printf("%i%s", counter, "   " );
        int x = getNextData();
        int y = filt(x);
        counter++;
        time_t timeobj = time(NULL);
        peakDetection(y, timeobj);
    }
    //tidsobjekt nedenunder her, den giver jeg til displaydata. men den giver vi til peakdetection istedet. jeg skal lige være sikker på at vi får current time
    time_t result = time(NULL);
    displayData(1200, 1, result);
    return 0;
}
