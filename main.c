#include "monty.h"

int main(int argc, char *argv[])
{
	int fd;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
	}

	(void) argv;

	return (0);
}
