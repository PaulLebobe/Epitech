/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myftp-paul.lebobe
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <ctype.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <uuid/uuid.h>
#include "../libs/myteams/logging_server.h"

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

typedef struct s_client {
    int fd;
    bool user;
    bool log;
    bool quit;
    char *name;
    char *id;
    struct s_client *next;
}t_client;

typedef struct s_server {
    int master;
    int port;
    struct protoent *pr_e;
    struct sockaddr_in ptr;
    socklen_t sock_in_size;
    int addrlen;
    int max_sd;
    t_client *clients;
} t_server;
static t_server server;

void commands(t_client **client, int i, char *buff, fd_set readfds);
typedef void (*command)(t_client *, int i, fd_set, char *);
void logout(t_client **client, int i, fd_set readfds, char *buff);
void login(t_client **client, int i, fd_set readfds, char *buff);
void users(t_client **client, int i, fd_set readfds, char *buff);
void help(t_client **client, int i, fd_set readfds, char *buff);
void sendMessage(t_client **client, int i, fd_set readfds, char *buff);
int linkedLenght (t_client *client);
char *parse_str_login(char *str);
#endif /* !MY_H_ */