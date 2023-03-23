#include "monty.h"
/**
* add - adds the top two elements of the stack
* @stack: contains a number of elements pushed into it
* @line_number: line we are currently on in the monty bytecode file
*
* Return: nothing
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	(*stack)->n += temp->n;
	(*stack)->prev = NULL;
	free(temp);
}

/**
* nop - does nothing
*
* Return: 0
*/
int nop(void)
{
	return 0;
}
