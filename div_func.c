#include "monty.h"


/**
*div_func - division two element
*@stack: pointer to pointer
*@line_num: integer line num opcode
*/


void div_func(stack_t **stack, unsigned int line_num)
{

	int secondValue;
	int firstValue;
	int result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	/*if the top element is zero*/
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	/* apply division operation*/
	secondValue = (*stack)->next->n;
	firstValue = (*stack)->n;
	result = secondValue / firstValue;

	/*Update the second top element*/
	(*stack)->next->n = result;

	/*Remove top element mn the stack*/
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
