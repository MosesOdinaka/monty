#include "monty.h"

/**
 * stack_push - pushes an element to the top of a stack
 * @stack: double pointer to the top of the stack
 * @value: value to push onto the stack
 *
 * Description: pushes an element to the top of a stack_t stack
 */
void stack_push(stack_t **stack, int value)
{
	stack_t *new_node;

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
 * stack_pop - pops an element from the top of a stack
 * @stack: double pointer to the top of the stack
 *
 * Return: the value of the popped element, or -1 if the stack is empty
 *
 * Description: pops an element from the top of a stack_t stack
 */
int stack_pop(stack_t **stack)
{
	int value;
	stack_t *temp;

	if (*stack == NULL)
		return (-1);

	temp = *stack;
	value = temp->n;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);

	return (value);
}

/**
 * is_number - checks if a string represents a valid integer
 * @str: string to check
 *
 * Return: 1 if the string represents a valid integer, 0 otherwise
 */
int is_number(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	if (str[0] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}
