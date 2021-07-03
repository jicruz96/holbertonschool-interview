#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
int max_in_array(int *array, size_t size);
int num_digits(int n);
void count_sort(int *array, int *tmp, int *count_array, int n, size_t size);
int _pow(int base, int power);






#endif /* _SORT_H_ */
