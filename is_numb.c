#include "monty.h"

/**
 * is_number - takes as input a string.
 * @str: the string as input.
 *
 * Return: true
 */

bool is_number(char *str)
{
	if (str == NULL)
		return (false);
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (false);
	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}
