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
    // Run program while we're still receiving data
    while (hasNextData()) {
        int x = getNextData();
        int y = filt(x);
        peakDetection(y);
    }
    return 0;
}
