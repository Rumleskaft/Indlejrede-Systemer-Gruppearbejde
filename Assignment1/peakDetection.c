
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
	static int RPeak[8], RPeakPtr = 0;
	static int RRPeak[5], RRPeakPtr = 0;

	RR_AVERAGE1 = 0;
	for(int i=0; i<8; i++){
		RR_AVERAGE1 += peaks[i];
	}
	RR_AVERAGE1 = RR_AVERAGE1 / 8;

	if(peaks[peakPtr] < THRESHOLD1)	{ //if Peak is lower
		NPKF = 0.125*peaks[peakPtr] + 0.875*NPKF;
		THRESHOLD1 = NPKF + 0.25*(SPKF - NPKF);
		THRESHOLD2 = 0.5*THRESHOLD1;
	}else{
		RPeak[RPeakPtr] = peaks[peakPtr];

		RR_AVERAGE2 = 0;
		for(int i=0; i<8; i++)	{
			RR_AVERAGE2 += RPeak[i];
		}
		RR_AVERAGE2 = RR_AVERAGE2 / 8;

		RR_LOW = RR_AVERAGE2 / 100 * 92;
		RR_HIGH = RR_AVERAGE2 / 100 * 116;
		RR_MISS = RR_AVERAGE2 / 100 * 166;

		if(RR_LOW < RPeak[RPeakPtr] && RPeak[RPeakPtr] < RR_HIGH)	{
			RRPeak[RRPeakPtr] = RPeak[RPeakPtr]; // Regular RPeaks

			SPKF = 0.125 * peaks[peakPtr] + 0.875 * SPKF;
			THRESHOLD1 = NPKF + 0.25 * (SPKF - NPKF);
			THRESHOLD2 = 0.5 * THRESHOLD1;
		}else if(RPeak[RPeakPtr] < RR_MISS){
			//Nothing happens
		}else{
			searchBack();
		}

		RPeakPtr++;
	}

}

void searchBack()	{
	peaks[]
}
