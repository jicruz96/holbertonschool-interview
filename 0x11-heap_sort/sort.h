#ifndef SORT_H
#define SORT_H

#include <stdio.h>

void print_array(const int *array, size_t size);
void heap_sort(int *A, size_t size);
void heapify(int *arr, int i, int len, size_t size);
void swap(int *arr, int a, int b, size_t size);


#endif /* SORT_H */
