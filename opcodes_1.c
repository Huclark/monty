#include "monty.h"

/**
 * pall - all the values on the stack, starting from the top of the stack.
 * @stack: A pointer to a pointer to the head of the stack_t list
 * @line_number: Line number processed
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (!*stack)
		return;

	temp = *stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
 * nop - Does nothing
 * @stack: A pointer to a pointer to the head of the stack_t list
 * @line_number: Line number processed
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)*stack;
	(void)line_number;
}


/**
 * add - Adds the top two elements of the stack
 * @stack: A pointer to a pointer to the head of the stack_t list
 * @line_number: Line number processed
*/
void add(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		flag.opcode_flag = 0;
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n += temp->n;
	free(temp);
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
	size_t len = 0;
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
