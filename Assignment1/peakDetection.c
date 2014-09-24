
static int buffer[5], peaks[30], ptr = 0, peakPtr = 0;
static int RR_AVERAGE1, RR_AVERAGE2, RR_LOW, RR_HIGH, RR_MISS;

int peakDetection(int input)	{

	buffer[ptr] = input;
	findLocalMaxima();
	findRPeaks();

	return 0;
}

void findLocalMaxima()	{
	if(buffer[ptr -1] <= buffer[ptr] && buffer[ptr] > buffer[ptr +1])	{
		peaks[peakPtr] = buffer[ptr]; //Add the value in peak-array

		if(peakPtr == 29){
			peakPtr = 0;
		}else{
			peakPtr++;
		}
	}
}

void findRPeaks()	{
	static int SPKF = 0, NPKF = 0, THRESHOLD1 = 0, THRESHOLD2 = 0;
	static int RPeak[8];

	RR_AVERAGE1 = 0
	for(int i=0; i<8; i++){
		RR_AVERAGE1 += peaks[peakPtr -i];
	}
	RR_AVERAGE1 = 1/8*RR_AVERAGE1;

	if(peaks[peakPtr] < THRESHOLD1)	{ //if Peak is lower
		NPKF = 0.125*peaks[peakPtr] + 0.875*NPKF;
		THRESHOLD1 = NPKF + 0.25*(SPKF - NPKF);
		THRESHOLD2 = 0.5*THRESHOLD1;
	}else{

	}

}
