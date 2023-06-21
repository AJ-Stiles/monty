#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * handle_opcode_add - Handles the add opcode
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed from the Monty file
 * Return: 0 on success, -1 on failure
 */
int handle_opcode_add(stack_t **stack, int line_number)
{
	stack_t *temp;

	if (stack_length(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		return (-1);
	}

	(*stack)->next->n += (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);

	return (0);
}
