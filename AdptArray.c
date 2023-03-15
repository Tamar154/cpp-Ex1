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
};

/*
    Initialize an empty array.
*/
PAdptArray CreateAdptArray(COPY_FUNC copy, DEL_FUNC delete, PRINT_FUNC print)
{
    PAdptArray adpt = (PAdptArray)malloc(sizeof(PAdptArray));

    adpt->arr = NULL;
    adpt->size = 0;
    adpt->capacity = 0;

    adpt->copy_func = copy;
    adpt->del_func = delete;
    adpt->print_func = print;

    return adpt;
}

void DeleteAdptArray(PAdptArray arr)
{
    for (int i = 0; i < arr->capacity; i++)
    {
        free(arr->arr[i]);
    }

    free(arr);
}

Result SetAdptArrayAt(PAdptArray adpt, int index, PElement element)
{
    if (index >= adpt->capacity) 
    {
        adpt = realloc(adpt, sizeof(int)*index);

        if (adpt == NULL)
            return FAIL;

        adpt->capacity = index+1; 
    }
    
    if (adpt->arr[index] != NULL)
    {
        free(adpt->arr[index]);
    }
    adpt->arr[index] = adpt->copy_func(element);
    adpt->size++;

    return SUCCESS;
}

PElement GetAdptArrayAt(PAdptArray adpt, int index)
{
    if (index <= adpt->capacity && adpt->arr[index] != NULL)
    {
        return adpt->copy_func(adpt->arr[index]);
    }

    return NULL;
}

int GetAdptArraySize(PAdptArray adpt)
{
    return adpt->size;
}

void PrintDB(PAdptArray adpt)
{
    for(int i = 0; i <= adpt->size; i++)
    {
        adpt->print_func(adpt->arr[i]);
    }
}