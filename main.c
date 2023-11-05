#include "shell.h"
/**
 * main - the Main fucntion of shell
 * @ac: number of arguments
 * @av: arguments
 * @env: environment variables
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
    size_t buffer_size = MAX_SIZE;
    ssize_t len = 0, x = 0;
    char *line = NULL;
    char **argv = NULL;
    char *plhold = (getenv("PATH")) ? getenv("PATH") : "";
    char *path = strdup(plhold);
    (void)ac;

    check_interact();

    while (1)
    {
        len = getline(&line, &buffer_size, stdin);

        if (check_fail(len))
            break;

        line[len - 1] = '\0';

        if (strlen(line) == 0)
        {
            check_interact();
            continue;
        }

        argv = tokenize(line);

        if (argv[0] == NULL)
            break;

        if (check_env(argv[0], env))
        {
            check_interact();
            continue;
        }

        if (!strcmp(argv[0], "exit"))
            break;

        free(path);
        path = strdup(plhold);

        x = execute(argv, path, av);
        free(line), line = NULL, free(argv), argv = NULL;
    }

    free(line), free(argv), free(path);
    exit(x);
}
