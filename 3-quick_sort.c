#include "sort.h"

/**
 * quicky - arr[], low, high
 * @arr: doubly linked list
 * @low: doubly linked list
 * @high: doubly linked list
 * description: function to quicksort arr with lomuto partition
 * Return: void
 */
void quicky(int *arr, size_t size, int low, int high)
{
        unsigned int partyIndex;
        /* low  --> 0 - Starting index,  high  --> size - 1 - Ending index */
        if (low < high)
        {
        /* partyIndex is partitioning index, arr[pi] is now
           at right place */
                partyIndex = partition(arr, size, low, high);

                /* Separately sort elements before and after partition */
                quicky(arr, size, low, partyIndex - 1);  /* Before index */
                quicky(arr, size, partyIndex + 1, high); /* After index */
        }
}

/**
 * quick_sort - int *arr, size_t size
 * @arr: arr containing ints to sort
 * @size: size of arr given
 * description: function that sorts an arr of integers in ascending order
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
        int front = 0, back = size - 1;

        if (!array || size < 2)
                return;
        /* low  --> 0 - Starting index,  high  --> size - 1 - Ending index */
        quicky(array, size, front, back);
}

/**
 * partition - arr, size, low, high
 * @arr: arr containing ints to sort
 * @size: size of the arr
 * @low: index of smaller element
 * @high: index
 * description: function to partition unsorted arr
 */
int partition(int *arr, size_t size, int low, int high)
{
        int pivot, index, current;

        pivot = arr[high]; /* pivot = rightmost position */
        index = (low - 1); /* index is idx of smaller element init at -1 */
        current = low;
        for (; current < high - 1; current++)
        {
                /* If current element is smaller than the pivot */
                if (arr[current] < pivot)
                {
                        /* increment index of smaller element */
                        index++;
                        if (index != current)
                        {
                                swap(&arr[index], &arr[current]);
                                print_array(arr, size);
                        }
                }
        }
        /* final swap of greater elements to the right */
        if (arr[index + 1] > arr[high])
        {
                swap(&arr[index + 1], &arr[high]);
                print_array(arr, size); 
        }
        return (index + 1);
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
