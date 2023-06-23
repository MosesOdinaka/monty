#include "monty.h"
/**
 * push - pushes an element to the top of a stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode in the script file
 *
 * Description: pushes an element to the top of a stack_t stack
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node;
	char *n;

	n = global_n;

	if (n == NULL || is_number(n) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(n);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode in the script file
 *
 * Description: prints all the values on a stack_t stack,
 * starting from the top
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (*stack == NULL)
		return;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
