#ifndef MONTY_H
#define MONTY_H


#include <stdio.h>
#include <stddef.h>

/* Structures */
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
}	stack_t;

/* Function Prototypes */
void opcode_push(stack_t **stack, int value);
void opcode_pall(stack_t **stack);
void opcode_pint(stack_t *stack, int line_number);
void opcode_pop(stack_t **stack, int line_number);
int handle_opcode_push(FILE *file, stack_t **stack, int line_number);
int handle_opcode_pall(stack_t **stack);
int handle_opcode_pint(stack_t **stack, int line_number);
int handle_opcode_pop(stack_t **stack, int line_number);
int handle_opcode_swap(stack_t **stack, int line_number);
size_t stack_length(const stack_t *stack);
void swap_top_two(stack_t **stack);

#endif /* MONTY_H */

