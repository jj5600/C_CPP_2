This is an important section on passing and manipulating Arrays to differnt functions:

Some key details: 
NOTICE how the entire 4-D array is passed to the function

void ComputeAverages(float set[][D1][D2][D3],float *nestedAvg, float *linearAvg)
{
// SLOW METHOD
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
    *nestedAvg = AverageTotal / TOTAL_ELEM;

  // QUICK and EFFICIENT METHOD
    float * ptr = NULL;
    for(ptr = (float *)set; ptr < (float*)set+D0*D1*D2*D3; ++ptr)
    {
        LinCounter+=*ptr;
    }
    *linearAvg = LinCounter/TOTAL_ELEM;
    return;
}
