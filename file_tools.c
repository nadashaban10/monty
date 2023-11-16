#include "monty.h"

/**
 *open_file - opens a file
 *@file_name: the file namepath
 *Return: void
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		def_err(2, file_name);

	ex_file(fd);
	fclose(fd);
}

/**
 *ex_file - reads a file
 *@fd: pointer to file descriptor
 *Return: void
 */

void ex_file(FILE *fd)
{
	int line_num, tmp = 0;
	char *buff = NULL;
	size_t len = 0;

	for (line_num = 1; getline(&buff, &len, fd) != -1; line_num++)
	{
		tmp = sep_line(buff, line_num, tmp);
	}
	free(buff);
}


/**
 *sep_line - Separates each line into tokens to determine
 *which function to call
 *@buff: line from the file
 *@line_num: line number
 *@format:  storage format. If 0 Nodes will be entered as a stack.
 *if 1 nodes will be entered as a queue.
 *Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int sep_line(char *buff, int line_num, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buff == NULL)
		def_err(4);

	opcode = strtok(buff, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	op_func(opcode, value, line_num, format);
	return (format);
}

/**
 *op_func - find the appropriate function for the opcode
 *@opcode: opcode
 *@value: argument of opcode
 *@format:  storage format. If 0 Nodes will be entered as a stack.
 *@line: line number
 *if 1 nodes will be entered as a queue.
 *Return: void
 */
void op_func(char *opcode, char *value, int line, int format)
{
	int i, flag;

	instruction_t func_list[] = {
		{"push", push_to_stack},
		{"pall", pall_stack},
		{"pint", pint_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_t},
		{"div", div_func},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			fun_call(func_list[i].f, opcode, value, line, format);
			flag = 0;
		}
	}
	if (flag == 1)
		def_err(3, line, opcode);
}


/**
 *fun_call - Calls the required function.
 *@fun: Pointer to the function that is about to be called.
 *@op: string representing the opcode.
 *@value: string representing a numeric value.
 *@line: line numeber for the instruction.
 *@format: Format specifier. If 0 Nodes will be entered as a stack.
 *if 1 nodes will be entered as a queue.
 */
void fun_call(func_op fun, char *op, char *value, int line, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			more_err(5, line);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				def_err(5, line);
		}
		node = create_node(atoi(value) * flag);
		if (format == 0)
			fun(&node, line);
		if (format == 1)
			add_to_queue(&node, line);
	}
	else
		fun(&head, line);
}
