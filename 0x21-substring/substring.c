#include "substring.h"
#include <stdlib.h>

/**
 * find_substring - finds all possible substrings containing a list of words
 *                  within a given string.
 * @s: string to scan
 * @words: array of words all substrings must be a concatenation arrangement of
 * @nb_words: number of elements in the array words
 * @n: pointer where number of elements in returned array is stored
 * Return: an array storing each index in `s` at which a substring was found.
 *         If no solution is found, `NULL` can be returned.
 * NOTES:
 *    * All words in the array words are the same length
 *    * A valid substring of `s` is the concatenation of each word in `words`
 *      exactly once and without any intervening characters
 *
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i, j, *result = NULL, *seen, words_len, len;

	if (!s || !words || !(*words) || !nb_words || !n)
		return (NULL);

	*n = 0;

	seen = malloc(sizeof(int) * nb_words);
	if (!seen)
		return (NULL);

	words_len = _strlen(*words);
	len = _strlen(s);
	i = 0;
	for (i = 0; (len - i) >= (words_len * nb_words); i++)
	{
		if (is_substring(s + i, words, nb_words, words_len, seen))
		{
			if (append(&result, n, i) == -1)
			{
				free(seen);
				return (NULL);
			}
		}
		for (j = 0; j < nb_words; j++) /* reset seen array */
			seen[j] = 0;
	}
	free(seen);
	return (result);
}

/**
 * is_substring - checks if a string is the start of a substring, where a
 *                substring is defined as a string that is a concatentation
 *                of all the words in the `words` array, with each word
 *                appearing only once and with no extra characters in between
 *
 * @s: string
 * @words: words
 * @nb_words: number of words
 * @len: length of words in `words`
 * @seen: helper array to keep track of which words have been seen
 * Return: 1 if string is start of substring, 0 if not
 */
int is_substring(char const *s, char const **words,
	int nb_words, int len, int *seen)
{
	int i, all_seen = 1;

	if (!(*s))
	{
		for (i = 0; i < nb_words; i++)
			if (seen[i] == 0)
				return (0);
		return (1);
	}

	for (i = 0; *s && i < nb_words; i++)
	{
		if (!seen[i] && !_strncmp(s, words[i], len))
		{
			seen[i] = 1;
			return (is_substring(s + len, words, nb_words, len, seen));
		}
		if (seen[i] == 0)
			all_seen = 0;
	}

	return (all_seen);
}

/**
 * append - appends an integer to the end of an allocated integer array
 *
 * @arr: pointer to pointer to array
 * @arr_size: pointer to array size
 * @n: number to append to array
 * Return: 0 on success, -1 on failure (malloc)
 */
int append(int **arr, int *arr_size, int n)
{

	if (!arr_size)
		return (-1);

	if (!arr)
	{
		*arr_size = 0;
		return (-1);
	}

	*arr_size += 1;
	*arr = realloc(*arr, *arr_size * sizeof(int));

	if (!(*arr))
	{
		*arr_size = 0;
		return (-1);
	}

	(*arr)[*arr_size - 1] = n;

	return (0);

}

/**
 * _strncmp - custom strncmp
 *
 * @s1: string 1
 * @s2: string 2
 * @n: number of characters to compare
 * Return: 0 if same, else difference between first different character
 */
int _strncmp(char const *s1, char const *s2, int n)
{
	int i;

	if (!n)
		return (0);

	for (i = 0; i < n && s1[i] && s2[i] && s1[i] == s2[i]; i++)
		;

	if (i == n || s1[i] == s2[i])
		return (0);

	return (s2[i] - s1[i]);
}

/**
 * _strlen - custom strlen
 *
 * @s: string
 * Return: length of string
 */
int _strlen(char const *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (s[i])
		i++;

	return (i);

}
