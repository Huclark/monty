#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

/* Standard library headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>


/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* Custom function prototypes */
char **get_input(FILE *);
int execute(char *, unsigned int, stack_t **);
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void free_array(char **);
void push(stack_t **, unsigned int);
char *_isdigit(char *);
void free_list(stack_t **);


/* MACROS */
#define READ_BUFFER		1024

#endif
