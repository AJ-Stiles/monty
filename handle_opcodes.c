#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * handle_opcode_push - Handles the "push" opcode.
 * @file: Pointer to the input file.
 * @stack: Double pointer to the stack.
 * @line_number: Current line number.
 *
 * Return: 0 on success, -1 on failure.
 *
 * Description: Reads an integer value from the input file and pushes it onto
 * the stack. If the integer value is not provided or cannot be parsed, it
 * prints an error message indicating the correct usage and returns -1.
 */
int handle_opcode_push(FILE *file, stack_t **stack, int line_number)
{
	char value_str[100];
	int value;

	if (fscanf(file, "%99s", value_str) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return (-1);
	}

	value = atoi(value_str);
	opcode_push(stack, value);

	return (0);
}

/**
 * handle_opcode_pall - Handles the "pall" opcode.
 * @stack: Double pointer to the stack.
 *
 * Return: 0.
 *
 * Description: Prints all the values in the stack.
 */
int handle_opcode_pall(stack_t **stack)
{
	opcode_pall(stack);
	return (0);
}

/**
 * handle_opcode_pint - Handles the pint opcode
 * @stack: Pointer to the stack
 * @line_number: Current line number
 *
 * Return: 0 on success, -1 on failure
 */
int handle_opcode_pint(stack_t **stack, int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		return (-1);
	}

	printf("%d\n", (*stack)->n);
	return (0);
}


/**
 * handle_opcode_pop - Handles the "pop" opcode.
 * @stack: Double pointer to the stack.
 * @line_number: Current line number.
 *
 * Return: 0 on success, -1 on failure.
 *
 * Description: Removes the top element from the stack. If the stack is empty,
 * it prints an error message indicating that popping an empty stack is not
 * allowed and returns -1. Otherwise, it removes the top element and returns 0.
 */
int handle_opcode_pop(stack_t **stack, int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		return (-1);
	}

	opcode_pop(stack, line_number);

	return (0);
}


/**
 * handle_opcode_swap - Handles the "swap" opcode.
 * @stack: Double pointer to the stack.
 * @line_number: Current line number.
 *
 * Return: 0 on success, -1 on failure.
 *
 * Description: Checks if the stack has at least two elements. If the stack is
 * too short, it prints an error message indicating that the swap operation
 * cannot be performed. Otherwise, it swaps the top two elements of the stack
 * and returns 0.
 */
int handle_opcode_swap(stack_t **stack, int line_number)
{
	if (stack_length(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		return (-1);
	}

	swap_top_two(stack);

	return (0);
}

