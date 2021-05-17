#include "holberton.h"
#include <stdlib.h>

#define true 1
#define false 0
#define user_input_error 98

#define char_to_digit(x) (x - '0')
#define mul_chars(a, b) (char_to_digit(a) * char_to_digit(b))
#define add_chars(a, b) (char_to_digit(a) + char_to_digit(b))
#define isdigit(x) ((x) >= '0' && (x) <= '9')

/**
 * main - entry point for mul program
 * @argc: argument count
 * @argv: argument array
 * Return: 98 on user input error | 0 on success
 */
int main(int argc, char *argv[])
{
	char *result;

	if (argc != 3 || valid_inputs(argv[1], argv[2]) == false)
	{
		_puts("Error");
		exit(user_input_error);
	}

	result = infinite_multiply(argv[1], argv[2]);
	_puts(skip_leading_zeroes(result));
	free(result);
	exit(EXIT_SUCCESS);
}

/**
 * valid_inputs - ensures the two strings are composed of digits only
 *
 * @n1: first number (as a string)
 * @n2: second number (as a string)
 * Return: true if valid inputs | false otherwise
 */
int valid_inputs(char *n1, char *n2)
{
	for (; *n1; n1++)
		if (!isdigit(*n1))
			return (false);

	for (; *n2; n2++)
		if (!isdigit(*n2))
			return (false);

	return (true);
}

/**
 * _puts - custom puts
 * @str: string
 * Return: number of characters printed
 */
int _puts(char *str)
{
	size_t i, len = _strlen(str);

	for (i = 0; i < len; i++)
		_putchar(str[i]);
	_putchar('\n');
	return (i + 1);
}

/**
 * infinite_multiply - multiplies two numbers (represented as strings)
 *
 * @n1: first number
 * @n2: second number
 * Return: result of multiplication (as a string). MUST BE FREED
 */
char *infinite_multiply(char *n1, char *n2)
{
	size_t i, j, n1_size = _strlen(n1), n2_size = _strlen(n2);
	char *buf = _calloc(n1_size + n2_size, sizeof(char));
	int product, digit, carry;

	/* reverse digits -- makes things easier to work with */
	rev_string(n1);
	rev_string(n2);

	for (i = 0; i < n1_size; i++)
	{
		for (carry = 0, j = 0; j < n2_size; j++)
		{
			product = mul_chars(n1[i], n2[j]) + carry;
			digit = product % 10;
			carry = product / 10;
			add_digit(buf + i + j, digit);
		}

		if (carry)
			add_digit(buf + i + j, carry);
	}

	/* reverse buffer -- and voilà ! you have the result */
	rev_string(buf);
	return (buf);
}

/**
 * _strlen - custom strlen
 *
 * @str: string
 * Return: length of string
 */
size_t _strlen(char *str)
{
	size_t len;

	if (!str)
		return (0);

	for (len = 0; str[len]; len++)
		;

	return (len);
}

/**
 * _calloc - custom calloc
 *
 * @nmemb: number of members
 * @size: size of each member
 * Return: pointer to allocated space
 */
void *_calloc(size_t nmemb, size_t size)
{
	char *buf = malloc(nmemb * size);
	size_t i;

	if (buf == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
		buf[i] = 0;

	return ((void *)buf);
}

/**
 * rev_string - reverses a string
 * @str: string
 */
void rev_string(char *str)
{
	size_t i, j;
	char tmp;

	for (i = 0, j = _strlen(str) - 1; i < j; i++, j--)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}
/**
 * add_digit - adds a digit to a char *buffer representing a number, reversed
 *
 * @buf: buffer
 * @digit: digit to add
 */
void add_digit(char *buf, int digit)
{
	int result;

	for (; true; buf++)
	{
		if (*buf)
			result = char_to_digit(*buf) + digit;
		else
			result = digit;
		*buf = (result % 10) + '0';
		digit = result / 10;
		if (digit == 0)
			break;
	}
}

/**
 * skip_leading_zeroes - skip leading zeroes in a string
 * @str: string
 * Return: string after all leading zeroes
 */
char *skip_leading_zeroes(char *str)
{
	while (*(str + 1) && *str == '0')
		str++;

	return (str);
}
