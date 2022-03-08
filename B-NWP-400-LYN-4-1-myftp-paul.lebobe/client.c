/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myftp-paul.lebobe
** File description:
** client
*/

#include "my.h"

t_client *create_new_client(int fd)
{
    t_client *new = malloc(sizeof(t_client));

    new->fd_mod = -1;
    new->fd = fd;
    new->ip = 0;
    new->quit = false;
    new->user = NULL;
    new->path = server.path;
    new->log = 0;
    new->passiv = 0;
    return new;
}