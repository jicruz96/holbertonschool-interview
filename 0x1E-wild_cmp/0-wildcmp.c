#include "holberton.h"
#include <stdio.h>
#ifndef NULL
#define NULL ((void *)0)
#endif

/**
 * wildcmp - checks if two strings can be considered identical, assuming '*' in
 *           s2 can replace any string (including empty string)
 * @s1: string 1
 * @s2: string 2
 * Return: 1 if strings are identical | o if not
 **/
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*s1 && wildcmp(s1 + 1, s2))
			return (1);
		return (wildcmp(s1, s2 + 1));
	}

	if (*s1 != *s2)
		return (0);

	if (!*s1)
		return (1);

	return (wildcmp(s1 + 1, s2 + 1));
}
