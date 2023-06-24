#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the top of the stack
<<<<<<< HEAD
 * @line_number: line number of the opcode in the file
=======
 * @line_number: line number of the opcode in the script file
 *
 * Description: pushes an element to the top of a stack_t stack
>>>>>>> a6ef00a2aa3dfcaf8d36d0fc3e9f748b23ec6a1d
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *n;

	n = global_n;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = argument;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
