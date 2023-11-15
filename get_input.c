#include "main.h"

char **get_input(FILE *file);

/**
* get_input - Takes in user input and returns it as a string
* @file: File descriptor to read from
* Return: User input string or NULL if it  failed
*/
char **get_input(FILE *file)
{
	int arr_idx = 0, lbsize = READ_BUFFER, la_size = READ_BUFFER;
	char *line_buffer = NULL, **line_arr = NULL;

	line_arr = malloc(sizeof(char *) * la_size);
	if (!line_arr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	line_buffer = malloc(sizeof(char) * lbsize);
	if (!line_buffer)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(line_buffer, lbsize, file) != NULL)
	{
		line_buffer[strcspn(line_buffer, "\n")] = '\0';
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

		line_buffer = malloc(sizeof(char) * lbsize);
		if (!line_buffer)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
	}
	line_arr[arr_idx] = NULL;

	if (arr_idx == 0)
	{
		free_array(line_arr);
		free(line_buffer);
		return (NULL);
	}

	free(line_buffer);
	return (line_arr);
}
