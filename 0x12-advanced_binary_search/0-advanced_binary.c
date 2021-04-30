#include <stdio.h>
#include "search_algos.h"

/**
 * print_int_array - prints an array of integers
 * @array: array of integers
 * @size: size of array
 **/
void print_int_array(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
		printf("%s%d", i ? ", " : "", array[i]);

	putchar('\n');
}
/**
 * advanced_binary - advanced binary search
 * @array: SORTED array of integers
 * @size: size of array
 * @value: value to find
 * Return: index of first appearance of value
 **/
int advanced_binary(int *array, size_t size, int value)
{
	int i;
	int mid;

	if (array == NULL || size == 0)
		return (-1);

	print_int_array(array, size);

	i = (size / 2) - (size % 2 == 0);
	mid = i;
	if (array[mid] < value)
	{
		i = advanced_binary(array + i + 1, size - i - 1, value);
		if (i == -1)
			return (-1);
		return (mid + i + 1);
	}

	if (array[mid] == value && mid == 0)
		return (mid);

	i = advanced_binary(array, size - i - (size % 2 == 0), value);

	if (array[mid] > value || (i >= 0 && i < mid))
		return (i);

	return (mid);
}
