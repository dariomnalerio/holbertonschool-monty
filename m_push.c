#include "monty.h"
/**
* m_push - pushes an element to the stack
* @stack: double linked list
* @line_number: line number of the monty file
*/
void m_push(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	char *n;
	int num = 0;

	n = strtok(NULL, " \t");
	num = verify_digit(n);
	if (num == 0)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	h = malloc(sizeof(stack_t));
	if (!h)
		exit(EXIT_FAILURE);

	if (!(*stack))
	{
		h->n = atoi(n);
		h->prev = NULL;
		h->next = NULL;
	}
	else
	{
		h->n = atoi(n);
		h->prev = NULL;
		h->next = *stack;
		(*stack)->prev = h;
	}
	*stack = h;
}

/**
* verify_digit - verifies if the string is a number
* @num: string to verify
* Return: 1 if string is a number, 0 otherwise
*/
int verify_digit(char *num)
{
	int i = 1;

	if (!num)
		return (0);
	for (i = 0; num[i]; i++)
	{
		if (num[i] == '-' && i == 0)
			continue;
		if (isdigit(num[i]) == 0)
			return (1);
	}
	return (0);
}
