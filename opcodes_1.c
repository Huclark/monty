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
