#include "monty.h"
#define BUFFER_SIZE 1024
/**
 * main - entry point for monty interpreter
 * @argc: argument count
 * @argv: argument variable
 * Return: 0 on success, non zero on failure.
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char line[BUFFER_SIZE];
	char *opcode;
	int n;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, BUFFER_SIZE, fp) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			n = atoi(strtok(NULL, " \t\n"));
			push(&stack, line_number, n);
		}
		else if (strcmp(opcode, "pall") == 0)
			pall(&stack, line_number);
		else if (strcmp(opcode, "pint") == 0)
			pint(&stack, line_number);
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number,
				opcode);
			exit(EXIT_FAILURE);
		}
	}
	fclose(fp);
	return (0);
}
