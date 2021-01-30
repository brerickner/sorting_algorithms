#include "sort.h"


/**
* bubble_sort - sorts an array of ints in ascending order
* @array: prints every time after ints are swapped
* @size: size of the array
*/

void bubble_sort(int *array, size_t size)
{
	int i, j;
	int n = size;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, n);
			}
		}
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
