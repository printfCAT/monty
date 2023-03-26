#include "monty.h"
/**
* push - adds an integer to the stack
* @stack: contains a number of elements pushed into it
* @line_number: line we are currently on in the monty bytecode file
*
* Return: nothing
*/
void push(stack_t **stack, unsigned int line_number)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (global.data_struct == 1)
	{
		if (!add_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}

/**
* pall - prints all the values on the stack
* @stack: contains a number of elements that we are going to print
* @line_number: amount of lines
*
* Return: nothing
*/
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	print_stack(*stack);
}

/**
* pint - prints the element at the top of the stack
* @stack: contains a number of elements pushed into it
* @line_number: line we are currently on in the monty bytecode file
*
* Return: nothing
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* pop - removes the top element of the stack
* @stack: contains a number of elements pushed into it
* @line_number: line we are currently on in the monty bytecode file
*
* Return: nothing
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}

/**
* swap - swaps the top 2 elements of the stack
* @stack: contains a number of elements pushed into it
* @line_number: line we are currently on in the monty bytecode file
*
* Return: nothing
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int temp_n = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temp_n = temp->n;
	temp->n = temp_n;
	temp->n = temp->next->n;
	temp->next->n = temp_n;
}
