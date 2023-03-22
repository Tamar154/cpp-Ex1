#include "AdptArray.h"
#include <stdlib.h>
#include <stdio.h>

struct AdptArray_
{
    PElement *arr;
    int size;

    DEL_FUNC del_func;
    COPY_FUNC copy_func;
    PRINT_FUNC print_func;
};

/*
    Initialize an empty array.
*/
PAdptArray CreateAdptArray(COPY_FUNC copy, DEL_FUNC delete, PRINT_FUNC print)
{
    PAdptArray adpt = malloc(sizeof(struct AdptArray_));
    if (adpt == NULL){
        return NULL;
    }
    
    adpt->arr = malloc(sizeof(PElement));
    if (adpt->arr == NULL)
    {
        adpt->size = -1;
    }
    else
        adpt->size = 0;

    adpt->copy_func = copy;
    adpt->del_func = delete;
    adpt->print_func = print;

    return adpt;
}

/*
    Delete the array including all it's elements
*/
void DeleteAdptArray(PAdptArray adpt)
{
    for (int i = 0; i < adpt->size; i++)
    {
        if (adpt->arr[i] != NULL)
            adpt->del_func(adpt->arr[i]);
    }
    free(adpt->arr);
    free(adpt);
}

/*
    Gets an index and an element.
    sets a copy of the element in arr[index]
*/
Result SetAdptArrayAt(PAdptArray adpt, int index, PElement element)
{
    if (index >= adpt->size)
    {
        adpt->arr = realloc(adpt->arr, sizeof(PElement) * (index + 1));

        if (adpt == NULL)
            return FAIL;

        for (int i = adpt->size; i < index + 1; i++)
        {
            adpt->arr[i] = NULL;
        }
        adpt->size = index + 1;
    }

    if (adpt->arr[index] != NULL)
    {
        adpt->del_func(adpt->arr[index]);
    }
    adpt->arr[index] = adpt->copy_func(element);

    return SUCCESS;
}

/*
    Returns a copy of the element at arr[index].
*/
PElement GetAdptArrayAt(PAdptArray adpt, int index)
{
    if (index < adpt->size && adpt->arr[index] != NULL)
    {
        return adpt->copy_func(adpt->arr[index]);
    }

    return NULL;
}

/*
    Returns the size of the array.
    -1 if not initialized properly.
*/
int GetAdptArraySize(PAdptArray adpt)
{
    return adpt->size;
}

/*
    Prints the elements of the array.
*/
void PrintDB(PAdptArray adpt)
{
    for (int i = 0; i < adpt->size; i++)
    {
        if (adpt->arr[i] != NULL)
            adpt->print_func(adpt->arr[i]);
    }
}