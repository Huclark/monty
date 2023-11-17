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
	FILE *file;

	flag.order = 1;

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

	get_input(file);

	fclose(file);
	return (EXIT_SUCCESS);
}
