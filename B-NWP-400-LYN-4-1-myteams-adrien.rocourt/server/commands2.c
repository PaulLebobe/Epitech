/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams-adrien.rocourt
** File description:
** commands2
*/

#include "my.h"

void uuid(t_client *client)
{
    uuid_t id;
    char *_uuid = malloc(sizeof(char) *37);
    client->id = malloc(sizeof(char) *37);

    uuid_generate_random(id);
    uuid_unparse_upper(id, _uuid);
    strcpy(client->id, _uuid);
}

void sendMessage(t_client **client, int i, fd_set readfds, char *buff)
{
    t_client *tmp = client[0];
    t_client *tmp2 = client[0];
    char *uuid = malloc(sizeof(char) * 37);
    char *uuid2 = malloc(sizeof(char) * 37);
    char *message = malloc(sizeof(char) * 1024);

    for (int x = 0; x < i; x++)
        tmp = tmp->next;
    uuid = strdup(strtok(buff, " "));
    message = strtok(NULL, "\"");
    if (strlen(uuid) < 3 || uuid[0] != '"' || uuid[strlen(uuid) - 1] != '"')
        return;
    strncpy(uuid2, uuid + 1, strlen(uuid) - 2);
    for (int x = 0; tmp2->next; x++) {
        if (strcmp(tmp2->id, uuid2) == 0) {
            dprintf(tmp2->fd, "%s$%s$%s","/send", tmp->id, message);
            server_event_private_message_sended(tmp->id, uuid2, message);
            return;
        }
        tmp2 = tmp2->next;
    }
    if (strcmp(tmp2->id, uuid) == 0) {
        dprintf(tmp2->fd, "%s$%s$%s","/send", tmp->id, message);
        server_event_private_message_sended(tmp->id, uuid, message);
        return;
    }
    dprintf(tmp->fd, "wrong_uuid");
}