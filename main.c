#include "monty.h"

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
		while(temp->next)
			temp = temp->next;

		node->n = line_number;
		node->prev = temp;
		node->next = NULL;

		temp->next = node;
	}
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;

	while(temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

void parse_command(stack_t **stack, char *op, unsigned int line_num)
{
	int i;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode; i++)
		if (strcmp(op, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_num);
			return;
		}

	if (strlen(op) != 0)
	{
		printf("L%u: unknown instruction %s\n", line_num, op);
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char *argv[])
{
	stack_t *head;

	size_t len;
	ssize_t read_line;
	unsigned int line_num = 0;
	char *line = NULL;
	FILE *fd;
	char *command;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], O_RDONLY);
	if (!fd)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read_line = getline(&line, &len, fd)) != -1)
	{
		command = strtok(line, DELIMS);
		line_num++;

		if (command)
			parse_command(&head, command, line_num);
	}

	if (line)
		free(line);

	fclose(fd);

	exit(EXIT_SUCCESS);
}
