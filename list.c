#include "monty.h"

/**
 * free_list - Frees stack_t doubly linked list
 * @stack: A pointer to a pointer to the head of the list
*/
void free_list(stack_t **stack)
{
	stack_t *temp = *stack;

	if (!*stack)
		return;

	while (*stack)
	{
		*stack = (*stack)->next;
		free(temp);
		temp = *stack;
	}
}
