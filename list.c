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


/**
 * rev_list - Reverses stack_t doubly linked list
 * @stack: A pointer to a pointer to the head of the list
*/
void rev_list(stack_t **stack)
{
	stack_t *next = NULL, *prev = NULL, *current = *stack;

	while (current)
	{
		next = current->next;
		current->next = prev;
		current->prev = next;
		prev = current;
		current = next;
	}
	*stack = prev;
}
