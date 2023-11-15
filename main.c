#include "monty.h"

int main(int argc, char **argv);
/**
* main - Entry point
* @argc: Argument count
* @argv: Argument vector
* Return: 0 on success
*/
int main(int argc, char **argv)
{
	int idx = 0;
	unsigned int line_number = 0;
	int status;
	char **file_input;
	stack_t *stack = NULL;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	file_input = get_input(file);
	if (!file_input)
		exit(EXIT_SUCCESS);

	while (file_input[idx])
	{
		line_number++;
		if (isempty(file_input[idx]) == 1)
		{
			idx++;
			continue;
		}
		status = execute(file_input[idx], line_number, &stack);
		if (status != 0)
		{
			free_array(file_input);
			exit(EXIT_FAILURE);
		}
		idx++;
	}
	free_array(file_input);
	free_list(&stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
