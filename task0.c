#include "monty.h"
/**
  * push - this function add elements on the stack
  * @stack: double linked list of a stack
  * @line_number: line number
  * Return: nothing
  */
void push(stack_t **stack, unsigned int line_number)
{
	char *valor = strtok(NULL, " \n");
	stack_t *nuevo = malloc(sizeof(stack_t));
	int i;

	if (valor)
	{
		for (i = 0; valor[i]; i++)
		{
			if ((valor[i] >= 48 && valor[i] <= 57) || valor[i] == '-')
			{
				nuevo->n = atoi(valor);
				nuevo->prev = NULL;
				nuevo->next = *stack;
				if (*stack)
					(*stack)->prev = nuevo;
				*stack = nuevo;
			}
			else
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
	}
	if (valor == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (nuevo == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - this function print in the  output
 * @stack: double linked list of a stack
 * @line_number: line number
 * Return: nothing
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *actual = *stack;

	while (actual)
	{
		printf("%d\n", actual->n);
		actual = actual->next;
	}
}
