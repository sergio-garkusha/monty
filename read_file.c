#include "monty.h"

/**
 * read_file - reads file, line by line
 * @file: the name of the file
 * @stack: double pointer to top of the stack
 *
 * Return: return an error code or success
 */
void read_file(char *file, stack_t **stack)
{
	size_t len;
	ssize_t read_line;
	unsigned int num = 0;
	char *line = NULL;
	FILE *fd;
	char *command;

	fd = fopen(file, "r");
	if (!fd)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	while ((read_line = getline(&line, &len, fd)) != -1)
	{
		command = strtok(line, DELIMS);
		num++;

		if (command)
			parse_command(stack, command, num);
	}

	if (line)
		free(line);

	fclose(fd);
}
