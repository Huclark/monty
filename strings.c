#include "main.h"

/**
 * _isdigit - Checks if a character is a decimal digit(0 -9)
 * @str: string to check
 * Return: The string or NULL if it fails
*/
char *_isdigit(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (NULL);
		i++;
	}
	return (str);
}
