#include "monty.h"

/**
 * mymod - Computes the rest of division of the second top element of the stack
 *       by the top element of the stack.
 * @stack: A pointer to a pointer to the head of the stack_t list
 * @line_number: Line number processed
*/
void mymod(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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
	(*stack)->n %= temp->n;
	free(temp);
}


/**
 * pchar - all the values on the stack, starting from the top of the stack.
 * @stack: A pointer to a pointer to the head of the stack_t list
 * @line_number: Line number processed
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		flag.opcode_flag = 0;
		return;
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		flag.opcode_flag = 0;
		return;
	}

	putchar((*stack)->n);
	putchar('\n');

}
