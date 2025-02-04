#include <stdio.h>

/**
 * binary_search - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: index where value is located, or -1 if not found or array is NULL
 */

int binary_search(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1, mid;
	size_t i;

	/* Check if the array is NULL */
	if (array == NULL)
		return (-1); /* Return -1 if the array is NULL */

	/* Binary search loop */
	while (left <= right)
	{
		/* Print the current subarray being searched */
		printf("Searching in array: ");
		for (i = left; i <= right; ++i)
		{
			printf("%d", array[i]);
			if (i < right)
				printf(", ");
			else
				printf("\n");
		}

		/* Calculate the middle index of the current subarray */
		mid = left + (right - left) / 2;

		/* Check if the middle element is the target value */
		if (array[mid] == value)
			return (mid); /* Return the index if the value is found */

		/* If the target value is greater, search the right half */
		if (array[mid] < value)
			left = mid + 1;
		/* If the target value is smaller, search the left half */
		else
			right = mid - 1;
	}

	/* Return -1 if the target value is not found in the array */
	return (-1);
}
