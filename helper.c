#include "monty.h"
#include <stddef.h>
#include <stdio.h>

/**
 * stack_length - Computes the length of the stack
 * @stack: Pointer to the stack
 *
 * Return: Length of the stack
 */
size_t stack_length(const stack_t *stack)
{
	size_t length = 0;
	const stack_t *current = stack;

	while (current != NULL)
	{
		length++;
		current = current->next;
	}

	return (length);
}

/**
 * swap_top_two - Swaps the top two elements of the stack
 * @stack: Pointer to the stack
 */
void swap_top_two(stack_t **stack)
{
	int temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
}

