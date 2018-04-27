#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack) || !((*stack)->next))
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;

	(*stack)->prev = temp;

	(*stack) = temp;

	(void) line_number;
}
