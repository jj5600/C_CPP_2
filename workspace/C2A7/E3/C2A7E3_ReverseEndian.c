#include <stdio.h>
void *ReverseEndian(void *ptr, size_t size)
{
    char * head = (char *)ptr;
    char * tail = (char *)ptr + size -1 ;
    for(;tail>head; --tail, ++head)
    {
        char temp = *tail;
        *tail = *head;
        *head = temp;
    }
    return ptr;
}
