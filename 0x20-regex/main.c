#include <stdlib.h>
#include <stdio.h>

#include "regex.h"

/**
 * test_match - tests output of regex_match and prints result
 *
 * @s: string
 * @p: regex pattern
 */
void test_match(char const *s, char const *p)
{
	printf("string: %s\npattern: %s\n\n", s, p);

	if (regex_match(s, p))
		printf("result: NOT A MATCH\n\n");
	else
		printf("result: MATCH\n\n");
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	test_match("H", "H");
	test_match("HH", "H");
	test_match("HH", "H*");
	test_match("HHHHHHHHHHHHHHHHH", "H*");

	test_match("Holberton", ".*");
	test_match("Alex", ".*");
	test_match("Guillaume", ".*");
	test_match("Julien", ".*");

	test_match("Holberton", "Z*H.*");
	test_match("Holberton", "Z*H.*olberton");
	test_match("Holberton", "Z*H.*o.");
	test_match("Holberton", "Z*H.*o");

	test_match("Holberton", "holberton");
	test_match("Holberton", ".olberton");

	test_match("!H@o#l$b%e^r&t(o)n_", "!.@.#.$.%.^.&.(.)._");

	return (EXIT_SUCCESS);
}
