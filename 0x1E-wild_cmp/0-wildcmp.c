#include "holberton.h"

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
	if (!s1 || !s2)
		return (0);

	if (*s1 == '\0')
	{
		while (*s2)
			if (*(s2++) != '*')
				return (0);

		return (1);
	}

	if (*s2 != '*')
		return (*s1 == *s2 && wildcmp(s1 + 1, s2 + 1));

	while (*s2 == '*')
		if (*(++s2) == '\0')
			return (1);

	for (s1 = _strchr(s1, *s2); s1; s1 = _strchr(s1 + 1, *s2))
		if (wildcmp(s1, s2))
			return (1);

	return (0);
}

/**
 * _strchr - custom implementation of strchr
 * @str: string to search for a char `chr` for
 * @chr: char to search for in string
 * Return: pointer to first instance of chr in str
 **/
char *_strchr(char *str, char chr)
{
	if (!str)
		return (NULL);

	for (; *str; str++)
		if (*str == chr)
			return (str);

	return (chr == '\0' ? str : NULL);
}
