#include "monty.h"
void sub_t(stack_t **stack, unsigned int ln) 
{
	int secondValue;
	int firstValue;
	int result;
	stack_t *temp;
	
	/*Check if the stack contains less than two elements*/
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	/*Perform the subtraction operation*/
	secondValue = (*stack)->next->n;
	firstValue = (*stack)->n;
	result = secondValue - firstValue;

	/* Update the second top element with the result*/
	(*stack)->next->n = result;

	/*remove the top element from the stack*/
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

