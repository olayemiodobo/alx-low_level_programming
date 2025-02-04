#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located,
 * or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	if (list == NULL)
		return (NULL);

	skiplist_t *prev, *curr;

	prev = list;
	curr = list->express;

	while (curr)
	{
		printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
		if (curr->n >= value)
			break;
		prev = curr;
		curr = curr->express;
		if (!curr)
		{
			while (prev->next)
				prev = prev->next;
			break;
		}
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       prev->index, curr ? curr->index : prev->index);

	while (prev && prev->index <= (curr ? curr->index : prev->index))
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
