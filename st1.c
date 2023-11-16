#include "monty.h"


/**
 *  * push_to_stack - Adds a node to the stack.
 *   * @new_node: Pointer to the new node.
 *    * @line: Intger representing the line number of of the opcode.
 *    */
void push_to_stack(stack_t **new_node, __attribute__((unused))unsigned int line)
{
		stack_t *buf;

			if (new_node == NULL || *new_node == NULL)
						exit(EXIT_FAILURE);
				if (head == NULL)
						{
									head = *new_node;
											return;
												}
					buf = head;
						head = *new_node;
							head->next = buf;
								buf->prev = head;
}


/**
 *  * pall_stack - print the stack.
 *   * @stack: Pointer to a pointer pointing to top node of the stack.
 *    * @line_num: line number of  the opcode.
 *    */
void pall_stack(stack_t **stack, unsigned int line_num)
{
		stack_t *tmp;

			(void) line_num;
				if (stack == NULL)
							exit(EXIT_FAILURE);
					tmp = *stack;
						while (tmp != NULL)
								{
											printf("%d\n", tmp->n);
													tmp = tmp->next;
														}
}

/**
 *  * pop_top - Adds a node to the stack.
 *   * @stack: Pointer to a pointer pointing to top node of the stack.
 *    * @line_num: Interger representing the line number of of the opcode.
 *    */
void pop_top(stack_t **stack, unsigned int line_num)
{
		stack_t *buf;

			if (stack == NULL || *stack == NULL)
						more_err(7, line_num);

				buf = *stack;
					*stack = buf->next;
						if (*stack != NULL)
									(*stack)->prev = NULL;
							free(buf);
}

/**
 *  * pint_top - Prints the top node of the stack.
 *   * @stack: Pointer to a pointer pointing to top node of the stack.
 *    * @line_num: Interger representing the line number of of the opcode.
 *    */
void pint_top(stack_t **stack, unsigned int line_num)
{
		if (stack == NULL || *stack == NULL)
					more_err(6, line_num);
			printf("%d\n", (*stack)->n);
}
