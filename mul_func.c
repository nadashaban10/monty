#include "monty.h"
/**
 * mul_func - multiplation function
 * @line_num: the number of arguments
 * @stack: pointer to pointer
 * Return: void
 */

void mul_func(stack_t **stack, unsigned int line_num)
{

	int second_value;
	int first_value;
	int result;
	stack_t *temp;


	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	second_value = (*stack)->next->n;
	first_value = (*stack)->n;
	result = second_value * first_value;


	(*stack)->next->n = result;


	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}




#include "monty.h"

/**
 * mod_func - moduls function
 * @line_num: the number of arguments
 * @stack: pointer to pointer
 * Return: void
 */


void mod_func(stack_t **stack, unsigned int line_num)
{
	int second_value;
	int first_value;
	int result;
	stack_t *temp;


	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}


	second_value = (*stack)->next->n;
	first_value = (*stack)->n;
	result = second_value % first_value;


	(*stack)->next->n = result;


	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
