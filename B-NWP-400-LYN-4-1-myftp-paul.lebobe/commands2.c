/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myftp-paul.lebobe
** File description:
** commands2
*/

#include "my.h"

void cdup(t_client **client, int i, fd_set readfds, char *buff)
{
    t_client *tmp = client[0];

    for (int x = 0; x < i; x++)
        tmp = tmp->next;
    if (tmp->log == 0) {
        dprintf(tmp->fd, "530\n");
    } else {
        dprintf(tmp->fd, "200\n");
        chdir(server.path);
    }
}

void port(t_client **client, int i, fd_set readfds, char *buff)
{
    t_client *tmp = client[0];

    for (int x = 0; x < i; x++)
        tmp = tmp->next;
    if (tmp->log == 0) {
        dprintf(tmp->fd, "530\n");
    } else {
        dprintf(tmp->fd, "200\n");
    }
}

void pasv(t_client **client, int i, fd_set readfds, char *buff)
{
    t_client *tmp = client[0];

    for (int x = 0; x < i; x++)
        tmp = tmp->next;
    if (tmp->log == 0) {
        dprintf(tmp->fd, "530\n");
    } else
        dprintf(tmp->fd, "227\n");
}

void stor(t_client **client, int i, fd_set readfds, char *buff)
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
        dprintf(tmp->fd, "226\n");
}

void user(t_client **client, int i, fd_set readfds, char *buff)
{
    t_client *tmp = client[0];

    for (int x = 0; x < i; x++)
        tmp = tmp->next;
    if (tmp->log == 0 && strcmp(buff, "Anonymous\r\n") == 0) {
        dprintf(tmp->fd, "331\n");
        tmp->user = 1;
    } else
        dprintf(tmp->fd, "503\n");
    return;
}