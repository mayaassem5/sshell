#include "shell.h"

/**
 * print_env - prints env
 * @env: enviroment
 *
 * Return: void
 */
void print_env(char **env)
{
    int i = 0;
    while (env[i] != NULL)
    {
        printf("%s\n", env[i]);
        i++;
    }
}

/**
 * check_env - checks env
 * @arg: argument
 * @env: environment
 *
 * Return: 1 if env, 0 of not
 */
int check_env(char *arg, char **env)
{
    if (!strcmp(arg, "env"))
    {
        print_env(env);
        return (1);
    }
    return (0);
}
