#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merger(int *l, size_t size_l, int *r, size_t size_r);

#endif /* _SORT_H_ */
