#include "monty.h"

/**
 *nop - Does nothing.
 *@stack: Pointer to a pointer pointing to top node of the stack.
 *@line_num: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}


/**
 *swap_nodes - Swaps the top two elements of the stack.
 *@stack: Pointer to a pointer pointing to top node of the stack.
 *@line_num: Interger representing the line number of of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int line_num)
{
	stack_t *buf;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "swap");
	buf = (*stack)->next;
	(*stack)->next = buf->next;
	if (buf->next != NULL)
		buf->next->prev = *stack;
	buf->next = *stack;
	(*stack)->prev = buf;
	buf->prev = NULL;
	*stack = buf;
}

/**
 *add_nodes - Adds the top two elements of the stack.
 *@stack: Pointer to a pointer pointing to top node of the stack.
 *@line_number: Interger representing the line number of of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL; uuuuuuuuuuuuuuu
}
