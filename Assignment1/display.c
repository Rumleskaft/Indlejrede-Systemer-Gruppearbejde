//
//  display.c
//  Assignment1
//
//  Created by Daniel Blyme Grundtvig on 24/09/14.
//  Copyright (c) 2014 Daniel Blyme Grundtvig. All rights reserved.
//

#include <stdio.h>
#include <time.h>

int displayData(rPeak, missed, time){
    if(rPeak<2000){
        printf("%s%i\n", "ALERT ! Low R-peak value: " ,rPeak );
        printf("%i", time);
    }else{
        printf("%s%i\n", "R-peak value:" ,rPeak );
        printf("%i", time);
    }
    
    if(missed){
        printf("%s\n", "Missed RR_Low and RR_high five times in a row ");
    }
    
    return 0;
}
s