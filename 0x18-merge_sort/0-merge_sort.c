#include "sort.h"

/**
 * merge_sort - implementation of merge sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	size_t half_size;

	if (size <= 1)
		return;

	half_size = size / 2;
	merge_sort(array, half_size);
	merge_sort(array + half_size, size - half_size);
	merger(array, half_size, array + half_size, size - half_size);
}

/**
 * merger - helper for merge_sort
 *
 * @l: left array
 * @size_l: size of left array
 * @r: right array
 * @size_r: size of right array
 */
void merger(int *l, size_t size_l, int *r, size_t size_r)
{
	size_t i = 0, j = 0, k = 0;
	int *tmp = malloc((size_l) * sizeof(int));

	for (i = 0; i < size_l; i++)
		tmp[i] = l[i];

	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, size_l);
	printf("[right]: ");
	print_array(r, size_r);

	for (i = 0; i < size_l && j < size_r; l[k++] = tmp[i], i++)
		for (; j < size_r && r[j] < tmp[i]; j++)
			l[k++] = r[j];

	for (; i < size_l; i++)
		l[k++] = tmp[i];

	for (; j < size_r; j++)
		l[k++] = r[j];

	printf("[Done]: ");
	print_array(l, size_l + size_r);
	free(tmp);
}
