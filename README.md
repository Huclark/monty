# 0x19. C - Stacks, Queues - LIFO, FIFO
![alt text](https://github.com/Huclark/memes/blob/main/stack%20and%20queus%20meme.jpg?raw=true)

## Table of Contents
- [About](#about)
- [Objective](#objective)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Contribution](#contribution)
- [License](#license)

## About
This is a project based on the implementation of Stacks and Queues in C using doubly linked lists and also covers the implementation of the brainf*ck programming language.

## Objectives
At the end of this project I am expected to explain to anyone, without the help of Google:
- What do LIFO and FIFO mean
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables

## Requirements
- **Allowed editors**: `vi`, `vim`, `emacs`.
- **Interpretation/Compilation Environment**: Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89.
- **New Line Requirement**: All your files should end with a new line.
- **Mandatory README**: A `README.md` file, at the root of the folder of the project, is mandatory.
- **Code Style**: Your code should use the `Betty` style. It will be checked using `betty-style.pl` and `betty-doc.pl`.
- **Global Variables**: You are allowed to use a maximum of one global variables
- **Functions per file**: No more than 5 functions per file.
- **Allowed functions**: You are not allowed to use the C standard library.
- **Test Files**: In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c`files at compilation. Our `main.c` files might be different from the one shown in the examples.
- **Header File**:
	- The prototypes of all your functions should be included in your header file called `monty.h`.
	- Don't forget to push your header file.
	- All your header files should be include guarded.
- You are expected to do the tasks in the order shown in the project
- **Compilation & Output**: 
Your code will be compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
Any output must be printed on `stdout`. Any error message must be printed on `stderr`
- **Data structures**:
You are required to use the following data structures for this project:
```
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
```

```
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
```
## Installation
1. Clone the repository:
```
git clone https://githuv.com/Huclark/monty.git
```
2. Use `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty` to compile.

## Usage
Run the executable with the bytecode file as an argument:<br>
```
./monty <file>
```
where `<file>` is the path to the file containing Monty byte code.<br>

## Contribution
This is a team project with the following contributors:
- [Moses Solomon Ayofemi](https://github.com/solayof)
- [Huclark Vanderpuye](https://github.com/Huclark)

This is a team project for the ALX SE Programme and hence, we won't be accepting any pull requests. However, please feel free to make or suggest any changes that would make the whole code run better. See [AUTHORS](AUTHORS) for our emails to reach us.

## License
This code is in the public domain (see [UNLICENSE](UNLICENSE) for more details). This means you can use, modify, and distribute it without any restriction. We appreciate, but don't require, acknowledgement in derivative works.
