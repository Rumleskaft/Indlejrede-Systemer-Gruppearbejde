//
//  peakDetection.h
//  Assignment1
//
//  Created by Daniel Blyme Grundtvig on 28/09/14.
//  Copyright (c) 2014 Daniel Blyme Grundtvig. All rights reserved.
//

#ifndef Assignment1_peakDetection_h
#define Assignment1_peakDetection_h

int peakDetection(int input);
int checkData(int input);
int findRPeaks();
void RRUpdate();
int RRAverageUpdate(int array[]);
void setSPKF(int peak);
void setSPKFSearchback(int peak);
void setNPKF(int peak);
void setThreshold1();
void setThreshold2();
void calculateRR();
void storeRPeak();
void storeRPeakOK();
void searchBack();
void bufferData(int input);

#endif
