#include "monty.h"
/**
  * pstr - prints the string starting at the top of the stack
  * @stack: stack
  * @line_number: line number
  * Return: nothing
  */
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current = *stack;

	if (!stack)
	{
		exit(EXIT_FAILURE);
	}
	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}
