#include "regex.h"
#include <stdio.h>

/**
 * helper - helper for regex_match
 *
 * @str: string to match
 * @pattern: regular expression
 * @trailer: keeps track of previous relevant character in `pattern`
 * @call: for debugging purposes, represents stack depth of function call
 * Return: 1 if pattern matches str, 0 otherwise
 */
int helper(char const *str, char const *pattern, char const *trailer, int call)
{
	fprintf(stderr, "%*s[%s] | [%s]\n", 4 * ++call, "", str, pattern);
	if (*str == '\0')
	{
		if (*pattern == '\0')
			return (1);
		if (*pattern == '*')
		{
			if (!trailer)
				return (0);
			while (*pattern == '*')
				pattern++;
			return (helper(str, pattern, trailer, call));
		}
		return (*(pattern + 1) == '*' && helper(str, pattern + 2, pattern, call));
	}
	if (*str == '*' || *str == '.' || *pattern == '\0')
		return (0);
	if (*pattern == '*')
	{
		if (!trailer)
			return (0);
		if (*trailer == '.' || *trailer == *str)
			if (helper(str + 1, pattern, trailer, call))
				return (1);
	}
	else
	{
		if (*str != *pattern)
		{
			if (*pattern == '.')
				if (helper(str + 1, pattern + 1, pattern, call))
					return (1);
			if (*(pattern + 1) != '*')
				return (0);
		}
		trailer = pattern;
	}
	return (helper(str + (*str == *pattern), pattern + 1, trailer, call));
}

/**
 * regex_match - checks whether a given pattern matches a given string.
 * @str: string to scan
 * @pattern: the regular expression
 * Return: 1 if pattern matches str, 0 otherwise
 * Find additional info in the README
 **/
int regex_match(char const *str, char const *pattern)
{
	if (!pattern || !str)
		return (0);

	return (helper(str, pattern, NULL, 0));
}
