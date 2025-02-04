#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array of integers
 *               using the Jump search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: index where value is located, or -1 if not found or array is NULL
 */

int jump_search(int *array, size_t size, int value)
{
	int jump, jump_size;
	int i = 0, holder = 0;

	if (array == NULL || size == 0)
		return (-1);

	jump = sqrt((int)size);
	jump_size = jump;

	printf("Value checked array[%d] = [%d]\n", holder, array[holder]);

	while (array[jump] <= value && jump <= (int)size - 1)
	{
		if (array[i] == value || array[jump] == value)
			break;
		holder = jump;
		printf("Value checked array[%d] = [%d]\n", holder, array[jump]);
		jump = jump + jump_size;
	}

	printf("Value found between indexes [%d] and [%d]\n", holder, jump);
	while (holder <= jump)
	{
		if (holder >= (int)size)
			return (-1);
		printf("Value checked array[%d] = [%d]\n", holder, array[holder]);

		if (array[holder] == value)
			return (holder);
		holder++;
	}

	return (-1);
}
