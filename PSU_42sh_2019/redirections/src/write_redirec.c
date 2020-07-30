/*
** EPITECH PROJECT, 2020
** redirections
** File description:
** write_redirec
*/

#include "redirections.h"

void exit_redirection(int new_fd, int *current_fd)
{
    if (*current_fd != new_fd) {
        close(new_fd);
        dup2(*current_fd, new_fd);
        close(*current_fd);
        *current_fd = new_fd;
    }
}

int write_redirection1(char *file)
{
    int fd_file = open(file, O_CREAT | O_TRUNC | O_WRONLY);
    int fd_1 = 1;

    if (fd_file < 0) {
        fd_file = open(file, O_CREAT | O_TRUNC | O_WRONLY);
        chmod(file, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    }
    fd_1 = dup(1);
    dup2(fd_file, 1);
    close(fd_file);
    return (fd_1);
}

int write_redirection2(char *file)
{
    int fd_file = open(file, O_APPEND | O_WRONLY);
    int fd_1 = 1;

    if (fd_file < 0) {
        fd_file = open(file, O_CREAT | O_APPEND | O_WRONLY);
        chmod(file, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    }
    fd_1 = dup(1);
    dup2(fd_file, 1);
    close(fd_file);
    return (fd_1);
}