#include "AdptArray.h"
#include <stdlib.h>


struct AdptArray_
{
    PElement *arr;
    int size;
    int capacity;

    DEL_FUNC del_func;
    COPY_FUNC copy_func;
    PRINT_FUNC print_func;
} adpt;

/*
    Initialize an empty array. 
*/
PAdptArray CreateAdptArray(COPY_FUNC copy, DEL_FUNC delete, PRINT_FUNC print)
{
    adpt.size = 0;
    adpt.capacity = 1;

    adpt.arr = malloc (adpt.capacity * sizeof(PElement));
    
    adpt.copy_func = copy;
    adpt.del_func = delete;
    adpt.print_func = print;
}

void DeleteAdptArray(PAdptArray adpt)
{

}

Result SetAdptArrayAt(PAdptArray adpt, int index, PElement element)
{

}

int GetAdptArraySize(PAdptArray adpt)
{

}

void PrintDB(PAdptArray)
{

}