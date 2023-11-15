#include "monty.h"

int execute(char *file_input, unsigned int line_no, stack_t **stack);
data flag;

/**
 * execute - Executes opcodes in each line in a monty ByteCode file
 * @file_input: An array of strings of each line in ByteCode file
 * @line_no: Line number processed in file
 * @stack: A pointer to a pointer to the head of the list
 * Return: 0 on success or 1 on failure
*/
int execute(char *file_input, unsigned int line_no, stack_t **stack)
{
	char *tokens, **tokenized_array;
	int idx = 0, j = 0, status = 1;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	flag.opcode_flag = 1;

	tokenized_array = malloc(sizeof(char *) * READ_BUFFER);
	if (!tokenized_array)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}

	tokens = strtok(file_input, " \t\r\n");

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

	while (opcodes[idx].opcode)
	{
		if (strcmp(tokenized_array[0], opcodes[idx].opcode) == 0)
		{
			if (idx == 0)
			{
				if (_isdigit(tokenized_array[1]))
				{
					flag.number = atoi(tokenized_array[1]);
					push(stack, line_no);
					status = 0;
					break;
				}
				fprintf(stderr, "L%d: usage: push integer\n", line_no);
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

	if (!flag.opcode_flag)
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
	(void)line_number;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		if (*stack)
			free_list(stack);

		flag.opcode_flag = 0;
		return;
	}
	new_node->n = flag.number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}


/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: A pointer to a pointer to the head of the stack_t list
 * @line_number: Line number processed
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		flag.opcode_flag = 0;
		return;
	}

	printf("%d\n", (*stack)->n);
}



/**
 * pop - Removes the top element of the stack
 * @stack: A pointer to a pointer to the head of the stack_t list
 * @line_number: Line number processed
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		flag.opcode_flag = 0;
		return;
	}

	*stack = (*stack)->next;
	free(temp);
}


/**
 * swap - Swaps the top two elements of the stack
 * @stack: A pointer to a pointer to the head of the stack_t list
 * @line_number: Line number processed
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int len = 0;
	stack_t *temp = *stack;

	while (temp)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		flag.opcode_flag = 0;
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;

	temp->next = temp->next->next;
	temp->prev = *stack;
	(*stack)->next = temp;
	(*stack)->prev = NULL;
}
