#include "monty.h"

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
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (str[i] < '0' || str[i] > '9')
			return (NULL);
		i++;
	}
	return (str);
}


/**
 * isempty - Checks if a string is empty(blank or newline)
 * @str: string to check
 * Return: 1 if true or 0 if otherwise
*/
int isempty(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}

	return (1);
}
