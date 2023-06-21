#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * opcode_push - Pushes an element to the stack.
 * @stack: Double pointer to the stack.
 * @value: Value to be pushed.
 */
void opcode_push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;

}

/**
 * opcode_pall - Prints all the values on the stack.
 * @stack: Double pointer to the stack.
 */
void opcode_pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * opcode_pint - Prints the value at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Current line number.
 */
void opcode_pint(stack_t *stack, int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", stack->n);
}

/**
 * opcode_pop - Removes the top element of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Current line number.
 */
void opcode_pop(stack_t **stack, int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
