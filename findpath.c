#include "shell.h"
/**
 * findpath - find the directory
 *@command: string with the command
 *@r: return value of exit
 * Return: the directory
 */
char *findpath(char *command, int *r)
{
	char *path, *toprint;
	struct stat stats;
	char *current, *tok;

	if (stat(command, &stats) == 0)
		return (command);

	path = _getenv("PATH");
	tok = strtok(path, ":");
	toprint = command;
	command = _concat("/", command);

	while (tok != NULL)
	{
		current = str_concat(tok, command);
		if (stat(current, &stats) == 0)
		{
			free(command);
			return (current);
		}
		free(current);
		tok = strtok(NULL, ":");
	}

	error_printing(path, find_length(command), toprint);
	print_string(": not found", 0);
	free(command);
	*r = 127;
	return (NULL);
}
