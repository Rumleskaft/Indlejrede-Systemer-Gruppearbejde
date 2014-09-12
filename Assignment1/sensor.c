//
//  sensor.c
//  Assignment1
//
//  Created by Daniel Blyme Grundtvig on 10/09/14.
//  Copyright (c) 2014 Daniel Blyme Grundtvig. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "sensor.h"

FILE *file;
int check = 0;
static const char filename[] = "/Users/DanielBG/Documents/C workspace/Assignment1/Assignment1/ECG.txt";

int getNextData(){
    if(check==0){
       file = fopen(filename, "r");
        check = 1;
    }
    int data;
    fscanf(file, "%i", &data);
    return 0;
}

// TODO lav en open funktion