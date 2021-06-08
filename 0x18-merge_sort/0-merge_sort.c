#include "sort.h"

/**
 * merge_sort - implementation of merge sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp = malloc(sizeof(int) * size);

	merge_sort_helper(array, size, tmp);
	free(tmp);
}

/**
 * merge_sort_helper - helper for merge_sort
 * @array: array of integers
 * @size: size of array
 * @tmp: tmp array
 */
void merge_sort_helper(int *array, size_t size, int *tmp)
{
	size_t size_l = size / 2, size_r = size - size_l, i = 0, j = 0, k = 0;
	int *right = array + size_l;

	if (size <= 1)
		return;

	merge_sort_helper(array, size_l, tmp);
	merge_sort_helper(right, size_r, tmp);

	for (i = 0; i < size_l; i++)
		tmp[i] = array[i];

	printf("Merging...\n[left]: ");
	print_array(array, size_l);
	printf("[right]: ");
	print_array(right, size_r);

	i = 0;
	while (i < size_l || j < size_r)
	{
		while (j < size_r && (i >= size_l || right[j] < tmp[i]))
			array[k++] = right[j++];

		while (i < size_l && (j >= size_r || tmp[i] <= right[j]))
			array[k++] = tmp[i++];
	}

	printf("[Done]: ");
	print_array(array, size);
}
