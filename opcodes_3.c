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
 * pchar -  Prints the char at the top of the stack, followed by a new line.
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


/**
 * pstr - Prints the string starting at the top of the stack,
 *       followed by a new line.
 * @stack: A pointer to a pointer to the head of the stack_t list
 * @line_number: Line number processed
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp)
	{
		if (temp->n == 0 || temp->n < 0 || temp->n > 127)
			break;
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}


/**
 * rotl - Rotates the stack to the top
 * @stack: A pointer to a pointer to the head of the stack_t list
 * @line_number: Line number processed
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *current = *stack;
	size_t len = 0;

	(void)line_number;

	while (temp)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
		return;

	temp = *stack;

	while (temp->next)
		temp = temp->next;

	*stack = (*stack)->next;
	temp->next = current;
	(*stack)->prev = NULL;
	current->next = NULL;
	current->prev = temp;
}


/**
 * rotr - Rotates the stack to the bottom
 * @stack: A pointer to a pointer to the head of the stack_t list
 * @line_number: Line number processed
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *current = *stack;
	size_t len = 0;

	(void)line_number;

	while (temp)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
		return;

	temp = *stack;

	while (temp->next)
		temp = temp->next;

	temp->prev->next = NULL;
	*stack = temp;
	(*stack)->prev = NULL;
	(*stack)->next = current;
	current->prev = *stack;
}
