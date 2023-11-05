#include "shell.h"
/**
 * tokenize - split input into array of words
 * @str: string to be tokenized
 *
 * Return: array of words
 */

char **tokenize(char *str)
{
    char *token;
    char **words;
    int i = 0;

    words = malloc(sizeof(char *) * MAX_WIDTH);
    if (words == NULL)
    {
        return (NULL);
    }
    token = strtok(str, " ");
    while (token != NULL)
    {
        words[i++] = token;
        token = strtok(NULL, " ");
    }
    words[i] = NULL;
    free(token);
    return (words);
}
