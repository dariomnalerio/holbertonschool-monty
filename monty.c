#include "monty.h"

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: List of arguments
 * Return: 0 if success, EXIT_FAILURE
*/

int main(int argc, char *argv[])
{
	char *content = NULL, *cont_aux = NULL, *token = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
		content = handle_command(argv[1]);
	cont_aux = strdup(content);
	free(content);
	/* Implement tokenisation functionality*/
}

/**
 * read_file - Reads file
 * @argv: Argument
 * Return: file content
*/

char *read_file(char *argv)
{
	size_t buffsize = 1024;
	int fd;
	char *buf = NULL;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	else
	{
		buf = malloc(buffsize);
		read(fd, buf, buffsize);
	}
	close(fd);
	return (buf);
}
