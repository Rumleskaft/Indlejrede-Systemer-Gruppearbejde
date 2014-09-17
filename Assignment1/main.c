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
<<<<<<< HEAD
	// floop

	int input = getNextData();
	printf("Before: %d%s", input, " ");
	int output = filt(input);
	printf("After: %d\n", output);
	outputArray[ptr] = output;

	/*peakDetection()
    	outputArraoutput.push(output)*/
	loopCheck(ptr++, sizeof(outputArray));

	return 0;
=======
    // floop
    int i;
    for(i=0; i<100; i++){
        int x = getNextData();
        int y = filt(x);
        yArray[0] = y;
    }
    /*peakDetection()
    yArray.push(y)*/
    
    return 0;
>>>>>>> origin/master
}
