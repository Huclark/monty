#include "monty.h"

void push(stack_t **stack, unsigned int line_number);

/**
 * push - Pushes an element to the stack
 * @stack: A pointer to a pointer to the head of the stack_t list
 * @line_number: Line number processed
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *temp = *stack;

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
	if (flag.order)
	{
		new_node->prev = NULL;
		new_node->next = *stack;

		if (*stack)
			(*stack)->prev = new_node;

		*stack = new_node;
	}

	else
	{
		if (*stack)
		{
			while (temp->next)
				temp = temp->next;

			temp->next = new_node;
			new_node->prev = temp;
			new_node->next = NULL;
		}
		else
		{
			*stack = new_node;
			new_node->next = NULL;
			new_node->prev = NULL;
		}
	}
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
 * sub - Subtracts the top element of the stack from the second top
 *       element of the stack.
 * @stack: A pointer to a pointer to the head of the stack_t list
 * @line_number: Line number processed
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	size_t len = 0;

	while (temp)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		flag.opcode_flag = 0;
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n -= temp->n;
	free(temp);
}

/**
 * mydiv - divides the second top element of the stack
 *       by the top element of the stack.
 * @stack: A pointer to a pointer to the head of the stack_t list
 * @line_number: Line number processed
*/
void mydiv(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	size_t len = 0;

	while (temp)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		flag.opcode_flag = 0;
		return;
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		flag.opcode_flag = 0;
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n /= temp->n;
	free(temp);
}


/**
 * mymul - Multiplies the second top element of the stack
 *       with the top element of the stack.
 * @stack: A pointer to a pointer to the head of the stack_t list
 * @line_number: Line number processed
*/
void mymul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	size_t len = 0;

	while (temp)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		flag.opcode_flag = 0;
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n *= temp->n;
	free(temp);
}
