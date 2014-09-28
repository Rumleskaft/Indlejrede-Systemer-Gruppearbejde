#include <time.h>
#include "filter.h"
// TODO: gør bufferstørelsen til en variabel
static int buffer[5], peaks[30], ptr = 0, peakPtr = 0;
static int RR_AVERAGE1, RR_AVERAGE2, RR_LOW, RR_HIGH, RR_MISS;

int peakDetection(int input, time_t time)	{

	//TODO: gør buffer til et lokalt array i findLocalMaxima() og giv den input istedet.
	// lav et check så den først kører efter 5 inputs.
	buffer[ptr] = input;
	findLocalMaxima();
	findRPeaks();
	return 0;
}

int findLocalMaxima()	{
	//brug bufferstørrelsen istedet for 5 og 30
	if(buffer[loopCheck(ptr -1,5)] < buffer[ptr] && buffer[ptr] > buffer[loopCheck(ptr +1,5)])	{
		//Add the value in peak-array
		peaks[loopCheck(peakPtr,30)] = buffer[loopCheck(ptr,5)];

		peakPtr++;
		ptr++;
	}
    return 0;
}

int findRPeaks()	{
	static int SPKF = 0, NPKF = 0, THRESHOLD1 = 0, THRESHOLD2 = 0;
	static int RPeak[8], RPeakPtr = 0;
	static int RRPeak[5], RRPeakPtr = 0;

	RR_AVERAGE2 = RRAverageUpdate(RPeak);
	if(peaks[peakPtr] < THRESHOLD1)	{ //if Peak is lower
		NPKF = setNPKF(peaks[peakPtr], NPKF);
		THRESHOLD1 = setThreshold1(NPKF, SPKF);
		THRESHOLD2 = setThreshold2(THRESHOLD1);
	}else {
		RPeak[RPeakPtr] = peaks[peakPtr];
		RRUpdate();

		if(RR_LOW < RPeak[RPeakPtr] && RPeak[RPeakPtr] < RR_HIGH)	{
			RRPeak[RRPeakPtr] = RPeak[RPeakPtr]; // Regular RPeaks

			SPKF = setSPKF(peaks[peakPtr], SPKF);
			THRESHOLD1 = setThreshold1(NPKF, SPKF);
			THRESHOLD2 = setThreshold2(THRESHOLD1);
		}else if(RPeak[RPeakPtr] < RR_MISS){
			//Nothing happens
		}else{
			int seekPeakPtr = peakPtr;
			while(1)	{

				if(peaks[peakPtr] > THRESHOLD2)	{
					RRAverageUpdate();
					RRUpdate();
					THRESHOLD1 = setThreshold1(NPKF, SPKF);
					THRESHOLD2 = setThreshold2(THRESHOLD1);
					SPKF = setSPKFSearchback(peaks[peakPtr], SPKF);
					break;
				}else{
					loopCheck(seekPeakPtr--,30);
				}
			}
		}
		loopCheck(RRPeakPtr++, 5);
		loopCheck(RPeakPtr++, 8);
	}
    return 0;
}

int RRUpdate()	{
	RR_LOW = RR_AVERAGE2 / 100 * 92;
	RR_HIGH = RR_AVERAGE2 / 100 * 116;
	RR_MISS = RR_AVERAGE2 / 100 * 166;
    return 0;
}

int RRAverageUpdate(int array[])	{
	int average = 0;
	for(int i=0; i<8; i++){
		average += array[i];
	}
	return average / 8;
}

int setSPKF(int peak, int SPKF)	{
	return 0.125 * peak + 0.875 * SPKF;
}
int setSPKFSearchback(int peak, int SPKF){
	return 0.25 * peak + 0.75*SPKF;
}

int setNPKF(int peak, int NPKF)	{
	return 0.125*peak + 0.875*NPKF;
}

int setThreshold1(int NPKF, int SPKF)	{
	return NPKF + 0.25 * (SPKF - NPKF);
}

int setThreshold2(int threshold1)	{
	return 0.5*threshold1;
}

int loopCheck(int number, int length)	{
	if(number<0){
		return number+length;
	} else
		return number%length;
}
