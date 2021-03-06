#include <time.h>
#include "filter.h"
#include "peakDetection.h" 
#include <stdio.h>
#include "display.h"
#include <math.h>

static int buffer[4], peaks[30],Rpeaks[30], RRpeaksOK[9],RRpeaks[9];
int pulse;
double RR, RR_low, RR_high, RR_miss, currentTime, lastEvent, SPKF, NPKF, RR_average1, RR_average2,threshold1, threshold2;
int  init=0, counter =0, peakcounter = 0, rpeakcounter = 0, rrpeakcounter = 0, rrpeakcounterok = 0, misscounter = 0, sampleCounter = 1;


int peakDetection(int input){
    currentTime = sampleCounter/250;
    sampleCounter++;
    if(init<2){
        buffer[loopCheck(init,4)] = input;
        init++;
        counter = init;
    }else{
        bufferData(input);
        checkData(input);
        counter++;
        if(misscounter==5){
            printf("Missed 5 times in a row.\n");
            misscounter = 0;
        }
    }
	return 0;
}

int checkData(int input)	{
	if(buffer[loopCheck(counter-2,4)] < buffer[loopCheck(counter-1,4)] && buffer[loopCheck(counter-1,4)] > buffer[loopCheck(counter,4)])	{
		peaks[loopCheck(peakcounter,30)] = buffer[loopCheck(counter-1,4)];
        
        if(peaks[loopCheck(peakcounter,30)] > threshold1){
            Rpeaks[loopCheck(rpeakcounter,30)] = peaks[loopCheck(peakcounter,30)];
            calculateRR();
            pulse = (1/RR)*60;
            if(RR_low < RR && RR < RR_high){
                storeRPeakOK(rpeakcounter);
                misscounter = 0;
            }else{
                misscounter++;
                if(RR > RR_miss){
                    searchBack();
                }
            displayData(peaks[loopCheck(peakcounter,30)], pulse, (int)currentTime);
            }
            rpeakcounter++;
            lastEvent = currentTime;
        }
        
        else{
            setNPKF(peaks[loopCheck(peakcounter-1,30)]);
            setThreshold1();
            setThreshold2();
        }
        peakcounter++;
    }
    return 0;
}


void setSPKF(int peak)	{
	SPKF = peak/8 + 0.875 * SPKF;
}
void setSPKFSearchback(int peak){
	SPKF = peak/4 + 0.75*SPKF;
}

void setNPKF(int peak)	{
	NPKF = peak/8 + 0.875*NPKF;
}

void setThreshold1()	{
	threshold1 = NPKF + ((SPKF - NPKF)/4);
}

void setThreshold2()	{
	threshold2 = threshold1/2;
}
void RRUpdate()	{
	RR_low = (RR_average2 / 100) * 92;
	RR_high = (RR_average2 / 100) * 116;
	RR_miss = (RR_average2 / 100) * 166;
}

int RRAverageUpdate(int array[])	{
	int average = 0;
	for(int i=0; i<8; i++){
		average += array[i];
	}
	return average / 8;
}

void calculateRR(){
    RR = currentTime-lastEvent;
}

void storeRPeakOK(int count){

    RRpeaksOK[loopCheck(rrpeakcounterok, 9)] = RR;
    RR_average2 = RRAverageUpdate(RRpeaksOK);
    rrpeakcounterok++;
    storeRPeak(count);
}

void storeRPeak(int count){
    RRpeaks[loopCheck(rrpeakcounter, 9)] = RR;
    RR_average1 = RRAverageUpdate(RRpeaks);
    setSPKF(Rpeaks[loopCheck(count,30)]);
    RRUpdate();
    setThreshold1();
    setThreshold2();
    rrpeakcounter++;
}

void searchBack(){
    int tempcounter = peakcounter-1;
    while(peaks[loopCheck(tempcounter,30)] < RR_miss){
        tempcounter--;
    }
    storeRPeak(tempcounter);
}

void bufferData(int input){
    buffer[loopCheck(counter,4)] = input;
}

