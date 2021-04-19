#include "sort.h"
#include <stdio.h>



/**
 * heap_sort - sorts an array using heap sort algorithm
 * @arr: array of integers to be sorted
 * @size: size of array
 **/
void heap_sort(int *arr, size_t size)
{
	int i;


	if (!arr || !size)
		return;


	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(arr, i, size, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(arr, 0, i, size);
		heapify(arr, 0, i, size);
	}
}

/**
 * heapify - turn an array of integers into a max heap
 * @arr: array
 * @i: current index in array to inspect
 * @len: size of heap
 * @size: size of array
 **/
void heapify(int *arr, int i, int len, size_t size)
{
	int largest;

	if (i >= (int)size || i < 0)
		return;

	largest = i;
#define LEFT(x) ((2 * (x)) + 1)
#define RIGHT(x) ((2 * (x)) + 2)
	if (LEFT(i) < len && arr[LEFT(i)] > arr[i])
		largest = LEFT(i);

	if (RIGHT(i) < len && arr[RIGHT(i)] > arr[largest])
		largest = RIGHT(i);

	if (largest != i)
	{
		swap(arr, largest, i, size);
		heapify(arr, largest, len, size);
	}
}

/**
 * swap - swaps the values of two indices in an array, then prints array
 * @arr: array
 * @a: first index
 * @b: second index
 * @size: size of array
 **/
void swap(int *arr, int a, int b, size_t size)
{
	int tmp;

	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
	print_array(arr, size);
}
