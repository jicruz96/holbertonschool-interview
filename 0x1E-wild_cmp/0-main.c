#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *s1, *s2;

	s1 = "main.c";
	s2 = "*.c";
	printf("%s %s= %s\n", s1, wildcmp(s1, s2) ? "" : "!", s2);
	s1 = "main.c";
	s2 = "m*a*i*n.*c*";
	printf("%s %s= %s\n", s1, wildcmp(s1, s2) ? "" : "!", s2);
	s1 = "main.c";
	s2 = "main.c";
	printf("%s %s= %s\n", s1, wildcmp(s1, s2) ? "" : "!", s2);
	s1 = "main.c";
	s2 = "m*c";
	printf("%s %s= %s\n", s1, wildcmp(s1, s2) ? "" : "!", s2);
	s1 = "main.c";
	s2 = "ma********************************c";
	printf("%s %s= %s\n", s1, wildcmp(s1, s2) ? "" : "!", s2);
	s1 = "main.c";
	s2 = "*";
	printf("%s %s= %s\n", s1, wildcmp(s1, s2) ? "" : "!", s2);
	s1 = "main.c";
	s2 = "***";
	printf("%s %s= %s\n", s1, wildcmp(s1, s2) ? "" : "!", s2);
	s1 = "main.c";
	s2 = "m.*c";
	printf("%s %s= %s\n", s1, wildcmp(s1, s2) ? "" : "!", s2);
	s1 = "main.c";
	s2 = "**.*c";
	printf("%s %s= %s\n", s1, wildcmp(s1, s2) ? "" : "!", s2);
	s1 = "main-main.c";
	s2 = "ma*in.c";
	printf("%s %s= %s\n", s1, wildcmp(s1, s2) ? "" : "!", s2);
	s1 = "main";
	s2 = "main*d";
	printf("%s %s= %s\n", s1, wildcmp(s1, s2) ? "" : "!", s2);
	s1 = "abc";
	s2 = "*b";
	printf("%s %s= %s\n", s1, wildcmp(s1, s2) ? "" : "!", s2);
	return (0);
}
