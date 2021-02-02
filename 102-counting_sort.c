#include "sort.h"

/**
 * counting_sort - sorts an array of ints in ascending order
 * @array: array of ints
 * @size: size of array
 */

void counting_sort(int *array, size_t size)
{
	int i, n, max;
	int *count;
	int *output;

	n = size;

	max = array[0];
	/* changed to i to 0, finding max below */
	for (i = 1; (size_t)i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	/* range is one greater than the max, malloc for that */
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	for (i = 0; i < max + 1; i++)
		count[i] = 0;

	for (i = 0; (size_t)i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	output = malloc(sizeof(int) * size);
	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; (size_t)i < size; i++)
		array[i] = output[i];
	print_array(array, n);
	free(count);
	free(output);
}
