#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>




/**
 *struct stack_s - doubly linked list representation of a stack (or queue)
 *@n: integer
 *@prev: points to the previous element of the stack (or queue)
 *@next: points to the next element of the stack (or queue)
 *Description: doubly linked list node structure
 *for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 *struct instruction_s - opcode and its function
 *@opcode: the opcode
 *@f: function to handle the opcode
 *Description: opcode and its function
 *for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

typedef void (*func_op)(stack_t **, unsigned int);

/*file operations*/
void open_file(char *file_name);
int sep_line(char *buff, int line_num, int format);
void ex_file(FILE *fd);
void fun_call(func_op fun, char *op, char *value, int line, int format);
void op_func(char *opcode, char *value, int line, int format);

/*Stack operations*/
stack_t *create_node(int n);
void free_nodes(void);
void pall_stack(stack_t **stack, unsigned int line_num);
void push_to_stack(stack_t **new_node,
		__attribute__((unused))unsigned int line);
void add_to_queue(stack_t **new_node,
		__attribute__((unused))unsigned int ln);
void pint_top(stack_t **stack, unsigned int line_num);
void pop_top(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);
void swap_nodes(stack_t **stack, unsigned int line_num);
void add_nodes(stack_t **stack, unsigned int line_number);
void sub_t(stack_t **stack, unsigned int line_num);
void div_func(stack_t **stack, unsigned int line_num);
void pchar_func(stack_t **stack, unsigned int line_num);

/*Error hanlding*/
void def_err(int error_code, ...);
void more_err(int error_code, ...);

#endif
