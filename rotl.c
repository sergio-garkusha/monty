#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *top;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	temp = *stack;

	top = temp->next;
	top->prev = NULL;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;

	(*stack)->next = NULL;
	(*stack)->prev = temp;

	*stack = top;

	(void) line_number;
}
