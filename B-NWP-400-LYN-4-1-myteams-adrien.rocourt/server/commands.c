/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams-adrien.rocourt
** File description:
** commands
*/

#include "my.h"

static command _command[5] = {&logout, &login, &users, &help, &sendMessage};

void logout(t_client **client, int i, fd_set readfds, char *buff)
{
    t_client *prec = NULL;
    t_client *tmp = client[0];

    for (int x = 0; x < i; x++) {
        prec = tmp;
        tmp = tmp->next;
    }
    dprintf(tmp->fd, "%s$%s$%s", "/logout", tmp->name, tmp->id);
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
    tmp->log = 0;
    server_event_user_logged_out(tmp->id);
}

void users(t_client **client, int i, fd_set readfds, char *buff)
{
    t_client *tmp = client[0];
    t_client *tmp2 = client[0];

    for (int x = 0; x < i; x++)
        tmp = tmp->next;
    while (tmp2) {
        if (tmp2->name) {
            dprintf(tmp->fd, "%s$%s$%s$%i\n", "/users", tmp2->id, tmp2->name,
            tmp2->log);
        }
        tmp2 = tmp2->next;
    }
}

void login(t_client **client, int i, fd_set readfds, char *buff)
{
    t_client *tmp = client[0];
    t_client *tmp2 = client[0];

    if (strlen(buff) < 3 || buff[0] != '"' || buff[strlen(buff) - 2] != '"') {
        dprintf(tmp->fd, "Username not valid\n");
        return;
    }
    buff = strtok(buff, "\"");
    for (int x = 0; x < i; x++)
        tmp = tmp->next;
    while (tmp2) {
        if (tmp2->name && strcmp(tmp2->name, buff) == 0 && tmp2->log == 1) {
            dprintf(tmp->fd, "Already_connected\n");
            return;
        }
        tmp2 = tmp2->next;
    }
    tmp->name = buff;
    uuid(tmp);
    server_event_user_logged_in(tmp->id);
    tmp->log = 1;
    dprintf(tmp->fd, "%s$%s$%s", "/login", buff, tmp->id);
}

void help(t_client **client, int i, fd_set readfds, char *buff)
{
    t_client *tmp = client[0];

    for (int x = 0; x < i; x++)
        tmp = tmp->next;
    dprintf(tmp->fd, "Help\n");
}

void commands(t_client **client, int i, char *buff, fd_set readfds)
{
    char *f_word[] = {"/logout\n", "/login", "/users\n", "/help\n",
    "/send", "/user", "/messages", "/subscribe", "/subscribed", "/unsubscribe",
    "/use", "/create", "/list", "/info"};
    t_client *tmp = client[0];
    t_client *tmp2 = client[0];
    char *buff2 = malloc(sizeof(char) * 1024);

    buff2 = strdup(buff);
    for (int x = 0; x < 6; x++) {
        if (!strcmp(f_word[x], strtok(buff, " "))) {
            _command[x](client, i, readfds, buff2 + strlen(buff) + 1);
            return;
        }
    }
}