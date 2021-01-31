#include "sort.h"

/**
 * selection_sort - sorts array of ints into ascending order
 * @array: array of ints
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	int i, j, min_idx;
	int n = size;

	if (!array)
		return;

	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (array[j] < array[min_idx])
				min_idx = j;
				

			swap(&array[min_idx], &array[i]);
			print_array(array, size);
	}
}

/**
 * swap - swaps ints
 * @xp: 1st int
 * @yp: 2nd int
 */

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
