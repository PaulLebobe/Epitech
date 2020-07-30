/*
** EPITECH PROJECT, 2020
** exec
** File description:
** c
*/

#include "42sh.h"

int exec(char **argv, char **envpath, int *exec_exit)
{
    pid_t pid = fork();
    pid_t w;

    if (pid == -1)
        perror("fork");
    else if (pid == 0) {
        execve(argv[0], argv, envpath);
        exit(84);
    } else {
        w = wait(exec_exit);
        if (w == -1)
            perror("wait");
    }
    return (w);
}