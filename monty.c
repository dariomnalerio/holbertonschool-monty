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
		content = read_file(argv[1]);
	cont_aux = strdup(content);
	free(content);
	token = strtok(cont_aux, "\n");
	/* cont_aux not freed */
	get_function(token);
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

/**
* get_function - Selects correct function
* @name: String corresponding to intended function
* Return: Call to function if found, EXIT_FAILURE otherwise
*/

void (*get_function(char *name))(stack_t **, unsigned int)
{
	int i;

	instruction_t options[] = {
		{"push", m_push},
		{NULL, NULL}
	};

	for (i = 0; options[i].opcode;  i++)
	{
		if (strcmp(options[i].opcode, name) == 0)
		{
			return (options[i].f);
		}
	}
		dprintf(STDERR_FILENO, "L1: unknown instruction %s\n", name);
		exit(EXIT_FAILURE);
}
