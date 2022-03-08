/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myftp-paul.lebobe
** File description:
** main2
*/

#include "my.h"

void main2 (int i, struct timeval tv, fd_set readfds)
{
    while (1) {
        FD_ZERO(&readfds);
        FD_SET(server.master, &readfds);
        server.max_sd = server.master;
        for (t_client *tmp = server.clients; tmp; tmp = tmp->next) {
            FD_SET(tmp->fd, &readfds);
            if (tmp->fd > server.max_sd)
                server.max_sd = tmp->fd;
        }
        switch (select(server.max_sd + 1, &readfds, NULL, NULL, &tv)) {
            case -1: break;
            case 0: break;
            default:
                create_client(server.clients, i, readfds);
                inputs(i, readfds);
        }
    }
}