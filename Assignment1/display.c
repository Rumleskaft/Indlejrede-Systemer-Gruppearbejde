//
//  display.c
//  Assignment1
//
//  Created by Daniel Blyme Grundtvig on 24/09/14.
//  Copyright (c) 2014 Daniel Blyme Grundtvig. All rights reserved.
//

#include <stdio.h>
#include <time.h>

int displayData(rPeak, pulse, time){

    if(rPeak<2000){
        printf("%s%i\n", "WARNING: Low R-peak value: " ,rPeak );
    }else{
        printf("%s%i\n", "R-peak value:" ,rPeak );
        if(time==1){
            printf ("Peak occurred after: %i%s\n", time, " second");
        }else{
            printf ("Peak occurred after: %i%s\n", time, " seconds");
        }
        printf ("The patients pulse is: %i%s\n", pulse, " beats/min");
    }
    return 0;
}
