/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams-adrien.rocourt
** File description:
** my
*/

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
#include "logging_client.h"
#include <uuid/uuid.h>

#ifndef MY_H_
#define MY_H_
#define READ_SIZE 1024

typedef struct cli
{
    bool login;
    int sock;
    char *uuid;
    char *user_name;
    int port;
} cli_t;

typedef struct s_stack {
    char value;
    struct s_stack *next;
} t_stack;


// init client
void init_client(char *ip, int port);

// get_next_line
char *get_next_line(const int fd);

// str_to_word_array
char **my_str_to_word_array(char *str, char *lim);

// main
void init_val(cli_t *cli);

// check_cmd
void check_cmd(char *tmp);
#endif /* !MY_H_ */
