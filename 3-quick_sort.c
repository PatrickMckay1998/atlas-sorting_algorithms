#include "sort.h"

static int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int temp;

    for (int j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                /* Swap elements */
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;

                /* Print array after swap */
                print_array(array, size);
            }
        }
    }

    if (i + 1 != high)
    {
        /* Swap elements */
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        /* Print array after swap */
        print_array(array, size);
    }

    return i + 1;
}

static void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = lomuto_partition(array, low, high, size);
        quick_sort_recursive(array, low, pi - 1, size);
        quick_sort_recursive(array, pi + 1, high, size);
    }
}

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
    {
        return;
    }
    quick_sort_recursive(array, 0, (int)size - 1, size);
}