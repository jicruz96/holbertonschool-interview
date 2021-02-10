#include "palindrome.h"

/**
 * is_palindrome - checks if an unsigned integer is a palindrome
 * @n: number to check
 * Return: 1 if is palindrome | 0 if not
 **/
int is_palindrome(unsigned long n)
{
	unsigned long shaver = 1;

	/* prevent division by zero errors */
	if (!n)
		return (1);

	/* get divisor to same magnitude as n */
	while (n / shaver)
		shaver *= 10;
	shaver /= 10;

	/* verify palindrome-ness */
	while (n > 9)
	{
		/* last digit (n%10) must equal first (n/shaver) */
		if (n % 10 != n / shaver)
			return (0);

		/* remove first and last digits */
		n = (n % shaver) / 10;

		/* re-size shaver to n's new magnitude */
		shaver /= 100;
	}

	return (1);
}
