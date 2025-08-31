//
//  C2A5E1_SwapObjects.c
//  C_ONLY
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void SwapObjects(void *pa, void *pb, size_t size)
{
    // dyamically allocate a chunk of memory the same size as the regions pointed to by pa and pb
    void * temp = malloc(size);
    if(temp == NULL)
    {
        puts("FAILURE to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    // swap pa and pb
    memcpy(temp, pa, size);
    memcpy(pa,pb,size);
    memcpy(pb,temp,size);
    // free mem
    free(temp);
    return;
}
