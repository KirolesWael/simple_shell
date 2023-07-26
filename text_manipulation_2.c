#include "main.h"

/**
 * digits - Cout the numbe of digits of a number
 *
 * @n: Number
 *
 * Return: Digits
 **/
int digits(int n)
{
	int i;

	for (i = 0; n != 0; i++, n /= 10)
		;

	return (i);
}

/**
 * to_string - Conver @number to string
 *
 * @number: Number to convert
 *
 * Return: Number as string
 **/
char *to_string(int number)
{
	int n_digits, i;
	char *_number;

	n_digits = digits(number);
	_number = malloc(n_digits * sizeof(char) + 2);
	if (number == 0)
	{
		_number[0] = '0';
		_number[1] = '\0';
		return (_number);
	}
	_number[n_digits] = '\0';
	for (i = n_digits - 1; number != 0; number /= 10, i--)
		_number[i] = (number % 10) + '0';

	return (_number);
}

/**
 * _isdigit - determine if digit
 *
 * @c: character to determine
 *
 * Return: gives boolean
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts string to integer
 * @s: string to convert
 *
 * Return: returns integer value
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	do {
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');
		else if (num > 0)
			break;
	} while (*s++);

	return (num * sign);
}

/**
 * contains_letter - Search non-digits in a string
 *
 * @s: String for search
 *
 * Return: If a non-digits was found, return 1
 * if not, return 0
 **/
int contains_letter(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (_isdigit(s[i]) == 0)
			return (1);
	}

	return (0);
}
