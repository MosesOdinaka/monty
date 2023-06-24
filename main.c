#include "monty.h"
#include <stdio.h>

/**
 * main - entry point for monty interpreter
 *
 * Return: 0 on success, non zero on failure.
 */
int main(void)
{
	stack_t *stack = NULL;

	push(&stack, 1, 1); /* Push 1 onto the stack */
	push(&stack, 2, 2); /* Push 2 onto the stack */
	push(&stack, 3, 3); /* Push 3 onto the stack */
	pall(&stack, 4); /* Print all values on the stack */

	return (0);
}
