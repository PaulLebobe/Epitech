/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** pipe
*/

#include "../include/42sh.h"

void close_pipe1(int pipefd[], int *fd_0, int *fd_1)
{
    close(pipefd[1]);
    dup2(*fd_1, 1);
    close(*fd_1);
    pipefd[1] = -1;
    *fd_1 = 1;
}

void close_pipe0(int pipefd[], int *fd_0, int *fd_1)
{
    close(pipefd[0]);
    dup2(*fd_0, 0);
    close(*fd_0);
    pipefd[0] = -1;
    *fd_0 = 0;
}

void open_pipe0(int pipefd[], int *fd_0, int *fd_1)
{
    *fd_0 = dup(*fd_0);
    dup2(pipefd[0], 0);
    close(pipefd[0]);
    pipefd[0] = 0;
}

int *create_pipe(int *fd_0, int *fd_1, int pipefd[])
{
    pipe(pipefd);
    *fd_1 = dup(*fd_1);
    dup2(pipefd[1], 1);
    close(pipefd[1]);
    pipefd[1] = 1;
    return (pipefd);
}