#include "monty.h"
/**
* main - interpreter for a monty bytecode
* @argc: argument count
* @argv: argument vector
*
* Return: 0
*/
int main(int argc, char *argv[])
{
	unsigned int line_number = 0;
	FILE *monty;
	size_t len = 0;
	ssize_t rd;
	char *line = NULL, *opcode, *arg;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty = fopen(argv[1], "r");
	if (!monty)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((rd = getline(&line, &len, monty)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (!opcode || opcode[0] == '#')
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \t\n");
			if (arg == NULL)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&stack, line_number, arg);
		}
		else if (strcmp(opcode, "pall") == 0)
			pall(&stack);
		else if (strcmp(opcode, "pint") == 0)
			pint(&stack, line_number);
		else if (strcmp(opcode, "pop") == 0)
			pop(&stack, line_number);
		else if (strcmp(opcode, "swap") == 0)
			swap(&stack, line_number);
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	fclose(monty);

	return (0);
}
