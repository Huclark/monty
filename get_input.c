#include "main.h"

char **get_input(int fd);

/**
* get_input - Takes in user input and returns it as a string
* @fd: File descriptor to read from
* Return: User input string or NULL if it  failed
*/
char **get_input(int fd)
{
	int line_idx = 0, arr_idx = 0, lbsize = READ_BUFFER, la_size = READ_BUFFER;
	int flag = 1;
	char ch, *line_buffer, **line_arr = malloc(sizeof(char *) * la_size);
	char *temp;

	if (!line_arr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		if (flag)
		{
			line_buffer = malloc(sizeof(char) * lbsize);
			if (!line_buffer)
			{
				fprintf(stderr, "Error: malloc failed\n");
				free_array(line_arr);
				exit(EXIT_FAILURE);
			}
		}
		flag = 0;
		ch = _getchar(fd);

		if (ch == EOF && line_idx == 0)
		{
			free_array(line_arr);
			free(line_buffer);
			return (NULL);
		}

		if (ch == '\n' || ch == EOF)
		{
			line_buffer[line_idx] = '\0';
			line_arr[arr_idx] = strdup(line_buffer);
			if (!line_arr[arr_idx])
			{
				fprintf(stderr, "Error: malloc failed\n");
				free_array(line_arr);
				free(line_buffer);
				exit(EXIT_FAILURE);
			}
			arr_idx++;
			free(line_buffer);

			flag = 1;
			line_idx = 0;
		}
		if (ch == EOF)
			break;
		line_buffer[line_idx] = ch;
		line_idx++;
		if (line_idx == lbsize)
		{
			lbsize += READ_BUFFER;
			temp = line_buffer;
			line_buffer = realloc(line_buffer, lbsize * sizeof(char));
			if (!line_buffer)
			{
				fprintf(stderr, "Error: malloc failed\n");
				free(temp);
				free_array(line_arr);
				exit(EXIT_FAILURE);
			}
		}
	}
	line_arr[arr_idx] = NULL;
	return (line_arr);
}


/**
* _getchar - Reads a character from stdin
* @fd: The file descriptor to read from
* Return: The character read (typecast as an int)
*         Or EOF on failure or there is no character left
*/
int _getchar(int fd)
{
	char ch;

	if (read(fd, &ch, 1) == 1)
		return (ch);
	else
		return (EOF);
}
