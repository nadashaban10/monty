#include "monty"

void pchar_func(stack_t **stack, unsigned int line_num)
{
  int char_cde;
  char charac;

  /*Check if the stack is empty*/
  if (*stack == NULL)
{
    fprintf(stderr, "L%u: can't pchar, stack empty\n", ln);
    exit(EXIT_FAILURE);
  }

  /*Get the character code from the top of the stack*/
  char_code = (*stack)->n;

  /*if the charac is within the ASCII range*/
  if (char_code < 0 || char_code > 127)
{
    fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
    exit(EXIT_FAILURE);
  }

  /*Convert charac to a character and print it*/
  charac = (char) char_code;
  putchar(charac);
}
