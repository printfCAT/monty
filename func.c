#include "monty.h"
/**
* push - adds an integer to the stack
* @stack: contains a number of elements pushed into it
* @arg: integer to be pushed to the stack
* @line_number: line we are currently on in the monty bytecode file
*
* Return: nothing
*/
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;
	int n, i = 0;

	if (arg[i] == '-')
		i++;
	for (; arg[i]; i++)
	{
		if (!isdigit(arg[i]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
* pall - prints all the values on the stack
* @stack: contains a number of elements that we are going to print
*
* Return: nothing
*/
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
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
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	free(temp);
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
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->prev = temp;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	temp->prev = NULL;
	*stack = temp;
}
