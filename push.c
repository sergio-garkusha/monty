#include "monty.h"

/**
 * push - pushes new node to the end of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the number of a line of the file
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node, *temp;

	if (*stack == NULL)
	{
		*stack = malloc(sizeof(stack_t));
		if (*stack == NULL)
		{
			printf("Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		(*stack)->n = line_number;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
	}
	else
	{
		node = malloc(sizeof(stack_t));
		if (node == NULL)
		{
			printf("Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		temp = *stack;
		while (temp->next)
			temp = temp->next;

		node->n = line_number;
		node->prev = temp;
		node->next = NULL;

		temp->next = node;
	}
}
