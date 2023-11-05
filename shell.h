#ifndef SHELL_H
#define SHELL_H

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX_SIZE 1024
#define MAX_WIDTH 100

void check_interact(void);
char **tokenize(char *str);
void mult_strcat(char *str, char *str1);
int execute(char **line, char *path, char **av);
void print_env(char **env);
int check_env(char *arg, char **env);
int check_fail(ssize_t len);

#endif
