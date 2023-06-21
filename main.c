#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * process_instruction - Process a single instruction from the file
 * @file: Pointer to the file
 * @stack: Pointer to the stack
 * @line_number: Current line number
 *
 * Return: 0 on success, -1 on failure
 */
int process_instruction(FILE *file, stack_t **stack, int line_number)
{
	char opcode[100];
	char value_str[100];
	int value;

	if (fscanf(file, "%99s", opcode) != 1)
	{
		fprintf(stderr, "L%d: Missing opcode\n", line_number);
		return (-1);
	}

	if (strcmp(opcode, "push") == 0)
	{
		if (fscanf(file, "%99s", value_str) != 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
				return (-1);
		}
		value = atoi(value_str);
		opcode_push(stack, value);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		opcode_pall(stack);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		if (*stack == NULL)
		{
			fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
			return (-1);
		}
		opcode_pint(*stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		return (-1);
	}

	return (0);
}

/**
 * main - Entry point of the Monty program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: EXIT_SUCCESS upon successful execution, otherwise EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	stack_t *stack = NULL;
	int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}


	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	/* Create the stack */

	while (!feof(file))
	{
		if (process_instruction(file, &stack, line_number) == -1)
		{
			fclose(file);
			return (EXIT_FAILURE);
		}
		line_number++;
	}

	fclose(file);
	return (EXIT_SUCCESS);
}
