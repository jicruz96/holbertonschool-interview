#include "sort.h"
#include <stdio.h>

/**
 * radix_sort - sorts an array of integers in ascending order using the
 *              Radix sort algorithm
 * @array: array to sort
 * @size: size of array
 **/
void radix_sort(int *array, size_t size)
{
	int i, digits, *tmp, *count_array;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;

	count_array = malloc(sizeof(int) * 10);
	if (!count_array)
		return;

	digits = num_digits(max_in_array(array, size));

	for (i = 0; i < digits; i++)
		count_sort(array, tmp, count_array, i, size);

	free(tmp);
	free(count_array);
}

/**
 * max_in_array - returns maximum value in array
 *
 * @array: array
 * @size: array size
 * Return: maximum value in array
 */
int max_in_array(int *array, size_t size)
{
	int max = -1;

	while (--size)
		if (max < array[size])
			max = array[size];

	return (max);
}

/**
 * num_digits - returns the number of digits in a number
 *
 * @n: number
 * Return: number of digits in n
 */
int num_digits(int n)
{
	int i;

	for (i = 1; n / 10; i++)
		n /= 10;

	return (i);
}

/**
 * count_sort - sorts an array of integers in ascending order of the value
 *                 of the n'th digit using the counting sort algorithm
 *
 * @array: array
 * @tmp: tmp array
 * @count_array: count array
 * @n: n'th digit to sort by
 * @size: size of array
 */
void count_sort(int *array, int *tmp, int *count_array, int n, size_t size)
{
	int i, divisor = _pow(10, n);

	for (i = 0; i < 10; i++)
		count_array[i] = 0;

	for (i = 0; (size_t)i < size; i++)
		count_array[(array[i] / divisor) % 10] += 1;

	for (i = 1; i < 10; i++)
		count_array[i] += count_array[i - 1];

	for (i = size - 1; i >= 0; i--)
		tmp[--(count_array[(array[i] / divisor) % 10])] = array[i];

	for (i = 0; (size_t)i < size; i++)
		array[i] = tmp[i];

	print_array(array, size);
}

/**
 * _pow - custom pow, only for positive integers
 *
 * @base: base
 * @power: exponent
 * Return: base ** exponent
 */
int _pow(int base, int power)
{
	int result = 1;

	while (power--)
		result *= base;

	return (result);
}
