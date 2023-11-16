#include "monty.h"
void sub_t(stack_t **stack, unsigned int line_num) 
{
	int second_value;
	int first_value;
	int result;
	stack_t *temp;
	
	/*Check if the stack contains less than two elements*/
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	/*Perform the subtraction operation*/
	second_value = (*stack)->next->n;
	first_value = (*stack)->n;
	result = second_value - first_value;

	/* Update the second top element with the result*/
	(*stack)->next->n = result;

	/*remove the top element from the stack*/
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

