/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myftp-paul.lebobe
** File description:
** commands3
*/

#include "my.h"

void list(t_client **client, int i, fd_set readfds, char *buff)
{
    t_client *tmp = client[0];

    for (int x = 0; x < i; x++)
        tmp = tmp->next;
    if (tmp->log == 0) {
        dprintf(tmp->fd, "530\n");
        return;
    }
    if (tmp->passiv == 0) {
        dprintf(tmp->fd, "425\n");
        return;
    }
        dprintf(tmp->fd, "150\n");
}

void dele(t_client **client, int i, fd_set readfds, char *buff)
{
    t_client *tmp = client[0];

    for (int x = 0; x < i; x++)
        tmp = tmp->next;
    if (tmp->log == 0) {
        dprintf(tmp->fd, "530\n");
    } else {
        dprintf(tmp->fd, "250\n");
        remove(buff);
    }
    return;
}

void cwd(t_client **client, int i, fd_set readfds, char *buff)
{
    t_client *tmp = client[0];

    for (int x = 0; x < i; x++)
        tmp = tmp->next;
    if (tmp->log == 0) {
        dprintf(tmp->fd, "530\n");
    } else {
        dprintf(tmp->fd, "250\n");
        tmp->path = strcat (tmp->path, buff);
        chdir(buff);
    }
}

void pwd(t_client **client, int i, fd_set readfds, char *buff)
{
    t_client *tmp = client[0];

    for (int x = 0; x < i; x++)
        tmp = tmp->next;
    if (tmp->log == 0) {
        dprintf(tmp->fd, "530\n");
    } else
        dprintf(tmp->fd, "%s%s%s", "257\n", tmp->path, "\n");
}

void help(t_client **client, int i, fd_set readfds, char *buff)
{
    t_client *tmp = client[0];

    for (int x = 0; x < i; x++)
        tmp = tmp->next;
    if (tmp->log == 0) {
        dprintf(tmp->fd, "530\n");
    } else
        dprintf(tmp->fd, "214\n");
}