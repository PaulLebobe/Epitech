/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myftp-paul[i]->lebobe
** File description:
** commands
*/

#include "my.h"

static command _command[17] = {&quit, &pass, &pass, &noop, &user, &list, &list,
&dele, &cwd, &cdup, &pwd, &help, &help, &stor, &retr, &port, &pasv};

void retr(t_client **client, int i, fd_set readfds, char *buff)
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

void pass(t_client **client, int i, fd_set readfds, char *buff)
{
    t_client *tmp = client[0];

    for (int x = 0; x < i; x++)
        tmp = tmp->next;
    if (tmp->user == 0) {
        dprintf(tmp->fd, "503\n");
        return;
    }
    if ((strncmp(buff, "                                                      "
    , strlen(buff) - 2) == 0) || strlen(buff) == 0 && tmp->log == 0) {
        dprintf(tmp->fd, "230\n");
        tmp->log = 1;
        return;
    } else {
        dprintf(tmp->fd, "530\n");
        return;
    }
}

void noop(t_client **client, int i, fd_set readfds, char *buff)
{
    t_client *tmp = client[0];

    for (int x = 0; x < i; x++)
        tmp = tmp->next;
    tmp->log == 1 ? dprintf(tmp->fd, "200\n")
    : dprintf(tmp->fd, "530\n");
}

void quit(t_client **client, int i, fd_set readfds, char *buff)
{
    t_client *prec = NULL;
    t_client *tmp = client[0];

    for (int x = 0; x < i; x++) {
        prec = tmp;
        tmp = tmp->next;
    }
    dprintf(tmp->fd, "221\n");
    if (prec) {
        if (tmp->next)
            prec->next = prec->next->next;
        else
            prec->next = NULL;
    } else {
        if (tmp->next)
            client[0] = client[0]->next;
        else {
            close(client[0]->fd);
            FD_CLR(client[0]->fd, &readfds);
            client[0] = NULL;
        }
    }
    close(tmp->fd);
    FD_CLR(tmp->fd, &readfds);
}

void commands(t_client **client, int i, char *buff, fd_set readfds)
{
    char *f_word[] = {"QUIT\r\n", "PASS", "PASS\r\n", "NOOP\r\n", "USER",
    "LIST", "LIST\r\n", "DELE", "CWD", "CDUP\r\n", "PWD\r\n", "HELP", "HELP\r\n", "STOR",
    "RETR", "PORT", "PASV\r\n"};
    t_client *tmp = client[0];
    t_client *tmp2 = client[0];
    char *buff2 = malloc(sizeof(char) * 1024);

    buff2 = strdup(buff);
    for (int x = 0; x < 17; x++) {
        if (!strcmp(f_word[x], strtok(buff, " "))) {
            _command[x](client, i, readfds, buff2 + strlen(buff) + 1);
            return;
        }
    }
    for (int x = 0; x < i; x++)
        tmp = tmp->next;
    dprintf(tmp->fd, "500\n");
}