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
	unsigned int i = 1;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
		content = read_file(argv[1]);
	token = strtok(content, " \n");
	while (token)
	{
		if (isdigit(token[0]) != 0)
		{
			token = strtok(NULL, " \n");
			continue;
		}
		get_function(token, content, i);
		token = strtok(NULL, " \n");
		i++;
	}
	free(content);
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

void (*get_function(char *name, char *content))(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t options[] = {
		{"pint", m_pint},
		{NULL, NULL}
	};

	for (i = 0; options[i].opcode;  i++)
	{
		if (strcmp(options[i].opcode, name) == 0)
		{
			return (options[i].f) // need to fix this;
		}
	}
		dprintf(STDERR_FILENO, "L1: unknown instruction %s\n", name);
		free(content);
		exit(EXIT_FAILURE);
}
