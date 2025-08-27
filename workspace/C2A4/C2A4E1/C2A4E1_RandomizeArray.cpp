//
//  C2A4E1_RandomizeArray.cpp
//  

#include "C2A4E1_ArraySize.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
void RandomizeArray(float set[][D1][D2][D3])
{
    // lets do this the fast and efficent way;
    
    float * ptr = NULL;
    // seed the random number generator
    srand((unsigned int)time(NULL));
    // start at the beginning of the array and interate through setting the value
    for(ptr = (float*)set; ptr < (float *)set + TOTAL_ELEM; ++ptr)
    {
        *ptr = (float)rand();
    }
    return;
}
