//
//  C2A4E1_ComputeAverages.cpp
// 
//
//  Created by  on 8/22/25.
//

#include <stdio.h>
#include "C2A4E1_ArraySize.h"
#include <stdlib.h>
#include <time.h>
// compute the averages of the 4d array using the two differnt methods
// 1.) uses the nested for loops to iteratea and count each element
// 2.) uses the pointer based approach ( more efficient method)
// return type is void
void ComputeAverages(float set[][D1][D2][D3],float *nestedAvg, float *linearAvg)
{
    float AverageTotal = 0.0;
    float LinCounter = 0.0;
    for ( int index0=0; index0 < D0; ++index0)
    {
        for ( int index1 = 0; index1<D1; ++index1)
        {
            for (int index2 = 0; index2<D2;++index2)
            {
                for (int index3 =0; index3<D3;++index3)
                {
                    AverageTotal+=set[index0][index1][index2][index3];
                }
            }
        }
    }
    // save the average result calculated in the address referenced to by the poiner
    *nestedAvg = AverageTotal / TOTAL_ELEM;

    // Method 2 poiner based
    float * ptr = NULL;
    for(ptr = (float *)set; ptr < (float*)set+D0*D1*D2*D3; ++ptr)
    {
        LinCounter+=*ptr;
    }
    *linearAvg = LinCounter/TOTAL_ELEM;
    return;
}
