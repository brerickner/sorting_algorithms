#include "sort.h"

/**
 * quicky_hoare - arr[], low, high
 * @arr: doubly linked list
 * @size: size of array
 * @low: starting index
 * @high: ending index
 * description: function to quicksort arr with hoare partition
 * Return: void
 */
void quicky_hoare(int *arr, size_t size, int low, int high)
{
	unsigned int partyIndex;
	/* low  --> 0 - Starting index,  high  --> size - 1 - Ending index */
	if (low < high)
	{
	/* partyIndex is partitioning index, arr[pi] is now at right place */
		partyIndex = hoare_partition(arr, size, low, high);

		/* Separately sort elements before and after partition */
		quicky_hoare(arr, size, low, partyIndex - 1);
		quicky_hoare(arr, size, partyIndex, high);
		}
}

/**
 * quick_sort_hoare - int *array, size_t size
 * @array: array of ints to sort
 * @size: size of arr given
 * description: function that sorts an arr of integers using Hoare partition
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	int front = 0, back = size - 1;

	if (!array || size < 2)
		return;
	/* low  --> 0 - Starting index,  high  --> size - 1 - Ending index */
	quicky_hoare(array, size, front, back);
}

/**
 * hoare_partition - arr, size, low, high
 * @arr: arr containing ints to sort
 * @size: size of the arr
 * @low: index of smaller element
 * @high: index
 * description: function to partition unsorted arr
 * Return: new index position
 */
int hoare_partition(int *arr, size_t size, int low, int high)
{
	int pivot, lftIndex, rtIndex;

	pivot = arr[high];  /* pivot = rightmost position */
	lftIndex = low - 1; /* Initialize left index */
	rtIndex =  high + 1; /* Initialize right index */

/* Loop forever*/
	while (1)
	{
		/* Find a value in left side greater than pivot */
		do {
			lftIndex++;
		} while (arr[lftIndex] < pivot);

	/* Find a value in right side smaller than pivot */
		do {
			rtIndex--;
		} while (arr[rtIndex] > pivot);

		if (lftIndex >= rtIndex)
			return (lftIndex);

		swap(&arr[lftIndex], &arr[rtIndex]);
		print_array(arr, size);
	}

}

/**
 * swap - swaps two ints
 * @xp: 1st int
 * @yp: 2nd int
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
