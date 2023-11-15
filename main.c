#include "main.h"

/**
* main - Entry point
* @argc: Argument count
* @argv: Argument vector
* Return: 0 on success
*/
int main(int argc, char **argv)
{
	int fd, idx = 0;
	unsigned int line_number = 0;
	int status;
	char **file_input;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Get user input */
	file_input = get_input(fd);

	while (file_input[idx])
	{
		printf("%s\n", file_input[idx]);
		idx++;
	}
	if (!file_input)
		exit(EXIT_SUCCESS);

	while (file_input[idx])
	{
		line_number++;
		printf("%s\n", file_input[idx]);
		status = execute(file_input[idx], line_number);

		if (status != 0)
		{
			free_array(file_input);
			exit(EXIT_FAILURE);
		}
		idx++;
	}
	free_array(file_input);
	close(fd);
	return (EXIT_SUCCESS);
}
