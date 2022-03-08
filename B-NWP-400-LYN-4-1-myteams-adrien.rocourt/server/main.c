/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myftp-paul.lebobe
** File description:
** main
*/

#include "my.h"

t_client *create_new_client(int fd)
{
    t_client *new = malloc(sizeof(t_client));

    new->fd = fd;
    new->quit = false;
    new->user = NULL;
    new->log = 0;
    new->next = NULL;
    new->name = NULL;
    return new;
}

void init(int opt, int port)
{
    if ((server.master = socket(AF_INET , SOCK_STREAM , 0)) == -1)
        perror("socket failed"), exit(EXIT_FAILURE);
    if (setsockopt(server.master, SOL_SOCKET, SO_REUSEADDR,
    (char *)&opt, sizeof(opt)) < 0)
        perror("setsockopt"), exit(EXIT_FAILURE);
    server.ptr.sin_family = AF_INET;
    server.ptr.sin_addr.s_addr = INADDR_ANY;
    server.ptr.sin_port = htons(port);
    if (bind(server.master, (struct sockaddr *)&server.ptr,
    sizeof(server.ptr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
}

void add_client(int socket)
{
    t_client *tmp = server.clients;
    t_client *newClient = malloc(sizeof(t_client));

    newClient->fd = socket;
    newClient->next = NULL;
    if (!tmp) {
        server.clients = create_new_client(socket);
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = create_new_client(socket);
}

void create_client(t_client *client, int i, fd_set readfds)
{
    int new_socket = -1;

    if (FD_ISSET(server.master, &readfds)) {
        if ((new_socket = accept(server.master, (struct sockaddr *)&server.ptr,
        (socklen_t *)&server.addrlen)) < 0)
            perror("accept"), exit(EXIT_FAILURE);
        printf("New connection , socket fd is %d , ip is : %s , port : %d\n",\
    new_socket , inet_ntoa(server.ptr.sin_addr), ntohs(server.ptr.sin_port));
        add_client(new_socket);
        FD_SET (new_socket, &readfds);
    }
}

void inputs(int i, fd_set readfds)
{
    char buffer[2048] = {0};
    char buff[2018] = {0};
    t_client *prec;

    i = 0;
    for (t_client *tmp = server.clients; tmp; prec = tmp, tmp = tmp->next, i++){
        if (FD_ISSET(tmp->fd, &readfds)) {
            if (read(tmp->fd, buffer, 1024) == 0) {
                getpeername(tmp->fd , (struct sockaddr *) &server.ptr,
                (socklen_t *)&server.addrlen);
                //printf("Host disconnected , ip %s , port %d \n",
                //inet_ntoa(server.ptr.sin_addr), ntohs(server.ptr.sin_port));
            } else
                commands(&server.clients, i, buffer, readfds);
        }
    }
}

int main(int ac , char **av)
{
    int opt = 1, i = 0, port;
    struct timeval tv;
    fd_set readfds;
    int val;

    tv.tv_sec = 0;
    tv.tv_usec = 5;
    if (ac == 2 & strcmp(av[1], "-help") == 0) {
        printf("USAGE: ./myteams_server port\n\n\
        port is the port number on which the server socket listens.\n");
        exit(EXIT_FAILURE);
    }
    if (ac != 2)
        perror("Parameter error"), exit(EXIT_FAILURE);
    if (atoi(av[1]) < 0 && atoi(av[1]) > 65535)
        perror("Port error"), exit(EXIT_FAILURE);
    port = atoi(av[1]);
    init(opt, port);
    if (listen(server.master, 5) < 0)
        perror("listen"), exit(EXIT_FAILURE);
    server.addrlen = sizeof(server.ptr);
    puts("Waiting for connections ...");
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
    return 0;
}