//
//  C2A4E1_WorkerFunction.cpp
//  CPP_JDM
//

#include <stdio.h>
#include "C2A4E1_ArraySize.h"
void ComputeAverages(float set[][D1][D2][D3],float *nestedAvg, float *linearAvg);
void RandomizeArray(float set[][D1][D2][D3]);



void WorkerFunction(float *nestedAverage, float *linearAverage)
{
    // create a 4D array
    float testArray[D0][D1][D2][D3];
    RandomizeArray(testArray);
    ComputeAverages(testArray,nestedAverage,linearAverage);
    return;
}
