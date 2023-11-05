#include "shell.h"
/**
 * check_interact - checks if interactive
 *
 * Return: void
 */
void check_interact(void)
{
    int interactive_mode = isatty(fileno(stdin));
    if (interactive_mode)
    printf("~$ ");
}

/**
 * check_fail - checks if failed
 * @len: length of the string
 *
 * Return: 1 if failed, 0 if success
 */
int check_fail(ssize_t len)
{
    if (len <= 0)
    {
        if (isatty(STDIN_FILENO))
            printf("$ ");
        return (1);
    }
    return (0);
}
