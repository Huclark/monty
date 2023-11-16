#include "monty.h"

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: A pointer to a pointer to the head of the stack_t list
 * @line_number: Line number processed
*/
void queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)*stack;

	flag.order = 0;
}


/**
 * _stack - Sets the format of the data to a stack (LIFO).
 * @stack: A pointer to a pointer to the head of the stack_t list
 * @line_number: Line number processed
*/
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)*stack;

	flag.order = 1;
}
