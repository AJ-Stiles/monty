# Monty Interpreter

This is a Monty interpreter implemented in C. Monty is a scripting language that uses Monty byte codes to manipulate a unique stack.

## Getting Started

To compile the Monty interpreter, use the following command:

```
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
To run the Monty interpreter, execute the following command:

```
./monty <file>
```
Replace <file> with the path to your Monty byte code file.

## Supported Opcodes
The Monty interpreter supports the following opcodes:

* push <int>: Pushes an element onto the stack.
* pall: Prints all the values on the stack.


## Monty Byte Code Files
Monty byte code files have the extension .m. Each line in the file represents an instruction with its argument (if applicable). Blank lines and comments are ignored.

Example Monty byte code file:

* push 1
* push 2
* push 3
* pall


## Requirements
- The code is written in C and follows the C89 standard.
- The code is compiled using gcc with the options -Wall -Werror -Wextra -pedantic -std=c89.
- The code is formatted according to the Betty style.


## File Structure
The Monty project has the following file structure:

- main.c: Entry point of the program.
- monty.h: Header file containing function prototypes and structures.
- stack.c: Implementation of stack-related functions.
- opcode_push.c: Implementation of the push opcode.
- opcode_pall.c: Implementation of the pall opcode.
- Makefile: Makefile to compile the code.


## Compilation & Output
The code will be compiled using the following command:

```
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
The output of the program will be printed on stdout. Any error messages will be printed on stderr.

## Error Handling
The interpreter handles the following error cases:

* Invalid instructions: If the file contains an invalid instruction, it prints the error message L<line_number>: unknown instruction <opcode> and exits with the status EXIT_FAILURE.
* Missing argument for push: If the push opcode is missing its argument or the argument is not an integer, it prints the error message L<line_number>: usage: push integer and exits with the status EXIT_FAILURE.
* Memory allocation failure: If the interpreter can't allocate memory, it prints the error message Error: malloc failed and exits with the status EXIT_FAILURE.
* File not found: If the interpreter can't open the file, it prints the error message Error: Can't open file <file> and exits with the status EXIT_FAILURE.
