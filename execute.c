#include "shell.h"
/**
 * execute - execute external program
 * @line: string to be executed
 * @path: path
 * @av: array of arguments
 *
 * Return: void
 */
int execute(char **line, char *path, char **av)
{
    int status;
    char *tok = strtok(path, ":"), final_cmd[MAX_WIDTH];
    pid_t childpid;

    while (tok != NULL)
    {
        sprintf(final_cmd, "%s%s%s", strchr(line[0], '/') == NULL ? tok : "",
                strchr(line[0], '/') == NULL ? "/" : "", line[0]);
        if (access(final_cmd, X_OK) == 0)
        {
            childpid = fork();
            if (childpid < 0)
                perror("\n");
            else if (childpid == 0)
            {
                if (execvp(final_cmd, line) == -1)
                    break;
            }
            else
            {
                wait(&status);
                check_interact();
                if (WIFEXITED(status))
                    return (WEXITSTATUS(status));
            }
        }
        tok = strtok(NULL, ":");
    }
    fprintf(stderr, "%s: 1: %s: not found\n", av[0], line[0]);
    return (127);
}
