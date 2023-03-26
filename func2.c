#include "monty.h"
/**
* add - adds the top two elements of the stack
* @stack: contains a number of elements pushed into it
* @line_number: line we are currently on in the monty bytecode file
*
* Return: nothing
*/
void _add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = result;
}

/**
* nop - does nothing
* @stack: contains a number of elements pushed into it
* @line_number: line we are currently on in the monty bytecode file
*
* Return: 0
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * _div - divides the next top value by the top value
 * @stack: stack given by main
 * @line_number: line counter
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
		;
		return;
	}

	result = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * mod - computes the remainder of the division
 * @stack: stack given by main
 * @line_number: line counter
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	result = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * _mul - divides the next top value by the top value
 * @stack: stack given by main
 * @line_number: line counter
 *
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	result = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = result;
}
