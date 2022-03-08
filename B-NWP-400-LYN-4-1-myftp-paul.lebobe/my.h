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

typedef struct s_client {
    int fd;
    char *ip;
    int fd_mod;
    int port;
    bool passiv;
    bool user;
    bool log;
    char *path;
    bool quit;
    int transfert;
    struct s_client *next;
}t_client;

typedef struct s_server {
    int master;
    int port;
    char *path;
    struct protoent *pr_e;
    struct sockaddr_in ptr;
    socklen_t sock_in_size;
    int addrlen;
    int max_sd;
    t_client *clients;
} t_server;
static t_server server;
t_server passiv;
t_client *create_new_client(int fd);
void init(int opt, char **av);
void main2 (int i, struct timeval tv, fd_set readfds);
void inputs(int i, fd_set readfds);
void create_client(t_client *client, int i, fd_set readfds);
typedef void (*command)(t_client *, int i, fd_set, char *);
void commands(t_client **client, int i, char *buff, fd_set readfds);
void cdup(t_client **client, int i, fd_set readfds, char *buff);
void port(t_client **client, int i, fd_set readfds, char *buff);
void pasv(t_client **client, int i, fd_set readfds, char *buff);
void stor(t_client **client, int i, fd_set readfds, char *buff);
void user(t_client **client, int i, fd_set readfds, char *buff);
void list(t_client **client, int i, fd_set readfds, char *buff);
void dele(t_client **client, int i, fd_set readfds, char *buff);
void cwd(t_client **client, int i, fd_set readfds, char *buff);
void pwd(t_client **client, int i, fd_set readfds, char *buff);
void help(t_client **client, int i, fd_set readfds, char *buff);
void pass(t_client **client, int i, fd_set readfds, char *buff);
void noop(t_client **client, int i, fd_set readfds, char *buff);
void quit(t_client **client, int i, fd_set readfds, char *buff);
void retr(t_client **client, int i, fd_set readfds, char *buff);
#endif /* !MY_H_ */