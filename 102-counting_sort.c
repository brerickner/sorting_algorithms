#include "sort.h"

/**
 * counting_sort - sorts an array of ints in ascending order
 * @array: array of ints
 * @size: size of array
 */

void counting_sort(int *array, size_t size)
{
    size_t output, i, n, max;
    n = size;

    max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
        max = array[i];
    }

    int count[10];

    for (i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }

    for (i = 0; i < size; i++)
    {
        count[array[i]]++;
    }

    for (i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    
    }

    for (i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
    print_array(array, n);
}
