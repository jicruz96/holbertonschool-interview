#include "palindrome.h"
#include <limits.h>

/**
 * is_palindrome - checks if an unsigned integer is a palindrome
 * @n: number to check
 * Return: 1 if is palindrome | 0 if not
 **/
int is_palindrome(unsigned long n)
{
	unsigned long n_reverse = 0, n_copy = n;

	/* Make a new number that is reverse of n */
	for (n_copy = n; n_copy; n_copy /= 10)
		n_reverse = (n_reverse * 10) + (n_copy % 10);

	return (n_reverse == n);
}
