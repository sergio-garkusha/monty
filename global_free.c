#include "monty.h"

/**
 * global_free - globally frees memory, previously alocated in the program
 *
 * Return: void
 */
void global_free(void)
{
	stack_t *to_free;
	stack_t *temp = NULL;

	to_free = *global_head;

	while (to_free)
	{
		temp = to_free->next;

		free(to_free);

		to_free = temp;
	}
}
