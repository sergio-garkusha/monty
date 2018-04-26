#include "monty.h"

stack_t **global_head;

/**
 * global_free - globally frees memory, previously alocated in the program
 *
 * Return: void
 */
void global_free(void)
{
	stack_t *tmp1;
	stack_t *tmp2 = NULL;

	tmp1 = *global_head;

	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;

		free(tmp1);

		tmp1 = tmp2;
	}
}
