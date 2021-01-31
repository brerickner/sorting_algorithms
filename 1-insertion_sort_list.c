#include "sort.h"

/**
 * insertion_sort_list - listint_t **list
 * @list: doubly linked list
 * description: function that sorts a doubly linked list of ints in ascending
 * order using Insertion sort algorithm.
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *runNode;

	if (!list || !(*list) || !(*list)->next)
		return;

	/* go through list */

	for (runNode = (*list)->next; runNode; runNode = runNode->next)
	{
 /* From left, if current number is less than previous nodes number swap */

		while (runNode->prev && runNode->n < runNode->prev->n)
		{
			runNode->prev->next = runNode->next;

/* If not last node, next node's prev ptr points to node left of runner */

			if (runNode->next != NULL)
				runNode->next->prev = runNode->prev;
			runNode->next = runNode->prev,
			runNode->prev = runNode->prev->prev;
			runNode->next->prev = runNode;

/* If leftmost node, make head of list else prev ptr of left node current */

			if (!runNode->prev)
				*list = runNode;
			else
				runNode->prev->next = runNode;

			print_list(*list);
		}
	}
}
