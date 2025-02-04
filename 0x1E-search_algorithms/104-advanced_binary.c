#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary_recursive - helper function for advanced binary search
 * @array: pointer to the first element of the array to search in
 * @low: starting index of the subarray
 * @high: ending index of the subarray
 * @value: value to search for
 *
 * Return: index where value is located, or -1 if not found
 */

int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
	size_t i;

	if (high < low)
		return (-1); /* Return -1 if the value is not found in the array */

	/* Print the current subarray being searched */
	printf("Searching in array: ");
	for (i = low; i < high; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	i = low + (high - low) / 2;
	/* Check if current element is target value and is the first occurrence */
	if (array[i] == value && (i == low || array[i - 1] != value))
		return (i);

	/* Adjust the search range based on the comparison with the value */
	if (array[i] >= value)
		return (advanced_binary_recursive(array, low, i, value));

	return (advanced_binary_recursive(array, i + 1, high, value));
}
/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: index where value is located, or -1 if not found
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
