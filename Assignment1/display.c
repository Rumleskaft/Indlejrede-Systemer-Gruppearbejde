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

/*
 
 introduktion
 
 problemanalyse
 
 design
 
 implementation
 
 resultatet (outputs, DIFF!!!!, optimere, kunne goeres bedre, koeretid, stroemforbrug)
 
 konklusion (opsumering)
 
 alt dette kan udledes af writing-reports.pfd
 
 gprof til at profilere program - analysere alt og alle funktioner
 
 */
