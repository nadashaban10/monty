#include "monty.h"

/**
 *def_err - Prints appropiate error messages determined by their error code.
 *@error_code: The error codes are the following:
 *(1) => The user does not give any file or more than one file to the program.
 *(2) => The file provided is not a file that can be opened or read.
 *(3) => The file provided contains an invalid instruction.
 *(4) => When the program is unable to malloc more memory.
 *(5) => When the parameter passed to the instruction "push" is not an int.
 *(6) => When the stack it empty for pint.
 *(7) => When the stack it empty for pop.
 *(8) => When stack is too short for operation.
 */
void def_err(int error_code, ...)
{
	va_list list;
	char *op;
	int num;

	va_start(list, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(list, char *));
			break;
		case 3:
			num = va_arg(list, int);
			op = va_arg(list, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 *more_err - handles errors.
 *@error_code: The error codes are the following:
 *(5) => When the parameter passed to the instruction "push" is not an int.
 *(6) => When the stack it empty for pint.
 *(7) => When the stack it empty for pop.
 *(8) => When stack is too short for operation.
 */

void more_err(int error_code, ...)
{
	va_list list;
	char *op;
	int num;

	va_start(list, error_code);
	switch (error_code)
	{
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(list, int));
			break;
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
					va_arg(list, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
					va_arg(list, int));
			break;
		case 8:
			num = va_arg(list, unsigned int);
			op = va_arg(list, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
					va_arg(list, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
