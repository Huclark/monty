#include "main.h"

int execute(char *file_input, unsigned int line_no);
int number, opcode_flag;

/**
 * execute - Executes opcodes in each line in a monty ByteCode file
 * @file_input: An array of strings of each line in ByteCode file
 * @line_no: Line number processed in file
 * Return: 0 on success or 1 on failure
*/
int execute(char *file_input, unsigned int line_no)
{
	stack_t **stack = NULL;
	char *tokens, **tokenized_array;
	int idx = 0, i = 0, j = 0, status = 1;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	printf("struct\n");
	tokenized_array = malloc(sizeof(char *) * READ_BUFFER);
	if (!tokenized_array)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	printf("%s\n", file_input);
	tokens = strtok(file_input, " \t\r\n");
	printf("%s\n", tokens);
	while (tokens)
	{
		tokenized_array[j] = strdup(tokens);
		if (!tokenized_array[j])
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_array(tokenized_array);
			return (EXIT_FAILURE);
		}
		j++;
		tokens = strtok(NULL, " \t\r\n");
	}
	tokenized_array[j] = NULL;
	printf("strtok success\n");
	while (opcodes[idx].opcode)
	{
		if (strcmp(tokenized_array[0], opcodes[idx].opcode) == 0)
		{
			if (idx == 0)
			{
				if (!_isdigit(tokenized_array[i]))
				{
					printf("before push");
					number = atoi(tokenized_array[1]);
					push(stack, line_no);
					printf("after push\n");
					status = 0;
					break;
				}
				fprintf(stderr, "L%d: usage: push integer", line_no);
				free_array(tokenized_array);
				return (EXIT_FAILURE);
			}
			opcodes[idx].f(stack, line_no);
			status = 0;
			break;
		}
		idx++;
	}
	if (status && tokenized_array)
	{
		fprintf(stderr, "L%d: unknown instruction %s", line_no, tokenized_array[0]);
		free_array(tokenized_array);
		return (EXIT_FAILURE);
	}
	free_array(tokenized_array);

	if (!opcode_flag)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


/**
 * push - Pushes an element to the stack
 * @stack: A pointer to a pointer to the head of the stack_t list
 * @line_number: Line number processed
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *temp;

	(void)line_number;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		if (*stack)
			free_list(stack);

		opcode_flag = 0;
		return;
	}
	new_node->n = number;

	if (!*stack)
	{
		*stack = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else
	{
		temp = *stack;
		*stack = new_node;
		new_node->next = temp;
		temp->prev = new_node;
		new_node->prev = NULL;
	}
}
