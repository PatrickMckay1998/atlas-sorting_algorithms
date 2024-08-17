#include "sort.h"

void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;
    int swapped;

    if (array == NULL || size < 2)
    {
        return;
    }    
    for (i = 0; i < size - 1; ++i)
    {
        swapped = 0;
        for (j = 0; j < size - 1 - i; ++j)
        {
            if (array[j] > array[j + 1])
            {
                /* Swap elements */
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                /* Print array after swap */
                print_array(array, size);
                
                swapped = 1;
            }
        }
        /* If no elements were swapped, the array is sorted */
        if (!swapped)
        {
            break;
        }
    }
}