#include "AdptArray.h"
#include <stdlib.h>
#include <stdio.h>

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

    PAdptArray adpt = malloc(sizeof(struct AdptArray_));
    adpt->arr = malloc(sizeof(PElement));
    adpt->size = 0;
    adpt->capacity = 1;

    adpt->copy_func = copy;
    adpt->del_func = delete;
    adpt->print_func = print;

    return adpt;
}

void DeleteAdptArray(PAdptArray adpt)
{
    for (int i = 0; i < adpt->capacity; i++)
    {
        if (adpt->arr[i] != NULL)
            adpt->del_func(adpt->arr[i]);
    }

    // free(adpt);
}

Result SetAdptArrayAt(PAdptArray adpt, int index, PElement element)
{
    if (index >= adpt->capacity)
    {
        adpt->arr = realloc(adpt->arr, sizeof(PElement) * (index + 1));

        if (adpt == NULL)
            return FAIL;

        for (int i = adpt->capacity; i < index + 1; i++)
        {
            adpt->arr[i] = NULL;
        }
        adpt->capacity = index + 1;
    }

    if (adpt->arr[index] != NULL)
    {
        adpt->del_func(adpt->arr[index]);
    }
    adpt->arr[index] = adpt->copy_func(element);
    adpt->size++;

    return SUCCESS;
}

PElement GetAdptArrayAt(PAdptArray adpt, int index)
{
    if (index < adpt->capacity && adpt->arr[index] != NULL)
    {
        return adpt->copy_func(adpt->arr[index]);
    }

    return NULL;
}

int GetAdptArraySize(PAdptArray adpt)
{
    return adpt->capacity;
}

void PrintDB(PAdptArray adpt)
{
    for (int i = 0; i < adpt->capacity; i++)
    {
        if (adpt->arr[i] != NULL)
            adpt->print_func(adpt->arr[i]);
    }
}