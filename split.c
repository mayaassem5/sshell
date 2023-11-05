#include "shell.h"
/**
 *tokenize - split input
 *
 *@str: string
 *
 *Return: array of words
*/

char **tokenize(char *str)
{
	char *token;
	char **tokens;
	int i = 0;
	char *delimiters = " \t\n";

	tokens = malloc(sizeof(char *) * 100);
	if (tokens == NULL)
		return (NULL);

	token = _strtok(str, delimiters);
	while (token != NULL)
	{
		tokens[i++] = token;
		token = _strtok(NULL, delimiters);
	}
	tokens[i] = NULL;
	free(token);
	return (tokens);
}
