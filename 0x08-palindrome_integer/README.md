# Interview Prep: Palindrome Unsigned Integer

## Description of Problem

Write a function in C that checks if a given unsigned interger is a palindrome.

* Prototype: `int is_palindrome(unsigned long n);`
* Return `1` if `n` is a palindrome; `0` otherwise.
* Holberton won't allow you to use the `math.h` library because reasons (???)

## Proposed Solution 💡

### 11 february 2021 - final answer

After speaking with my friend [Usman](https://github.com/UsmanGTA), I realized I could vastly simplify my approach while satisfying all edge cases by manually generating a new number that is the reverse of n. Then, we just return the result of the comparison.

```C++
int is_palindrome(unsigned long n)
{
	unsigned long n_reverse = 0, n_copy = n;

	/* Make a new number that is reverse of n */
	for (n_copy = n; n_copy; n_copy /= 10)
		n_reverse = (n_reverse * 10) + (n_copy % 10);

	return (n_reverse == n);
}
```

### 10 february 2021 - first attempt

This was my first go at the problem. This code would be even simpler if I could have used some math functions. The `shaver` value could have been calculated using `floor(log10(n))` and some typecasts. But this is simple, short and sweet and gets the job done.

```C++
int is_palindrome(unsigned long n)
{
	unsigned long shaver = 1;

	/* prevent division by zero errors */
	if (n < 10)
		return (1);

	/* handles limit edge case */
	if (n == ULONG_MAX)
		return (0);

	/* get divisor to same magnitude as n */
	while (n / shaver)
		shaver *= 10;
	shaver /= 10;

	/* verify palindrome-ness */
	while (n >= 10)
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
```
