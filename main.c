#include "monty.h"
/**
 * main - entry point for monty interpreter
 * @argc: argument count
 * @argv: argument variable
 * Return: 0 on success, non zero on failure.
 */

int main(int argc, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t n = 0;
	ssize_t len;
	char *opcode;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};
	int i;

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
	while ((len = my_getline(&line, &n, fp, 1024)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
			continue;
		for (i = 0; opcodes[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, opcodes[i].opcode) == 0)
			{
				opcodes[i].f(&stack, line_number);
				break;
			}
		}
		if (opcodes[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number,
					opcode);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(fp);
	return (0);
}
