#include "monty.h"
#include <stdio.h>

/**
 * main - entry point for monty interpreter
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0 on success, non zero on failure.
 */
int main(int argc, char **argv)
{
	FILE *script_file;
	char *line = NULL;
	size_t len = 0;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	char *opcode;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	script_file = fopen(argv[1], "r");
	if (script_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, script_file) != -1)
	{
		line_number++;
		opcode = strtok(line, "\t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue;

		for (int i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				char *n = strtok(NULL, "\t\n");
				global_n = n;

				instructions[i].f(&stack, line_number, n);
				break;
			}
		}
	}
	free(line);
	fclose(script_file);
	return (0);
}
