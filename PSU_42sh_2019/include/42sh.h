/*
** EPITECH PROJECT, 2020
** 42SH
** File description:
** h
*/

#ifndef _42SH_H
#define _42SH_H

#include <stdio.h>
#include <errno.h>

#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>

#include <signal.h>
#include <sys/wait.h>

#include "../lib_my/include_lib/include_lib.h"
#include "../redirections/include/redirections.h"

/* test.c */
int test(char **, char **);

/* read_term.c */
char *read_term(void);

/* env_term_pos_disp.c */
void env_term_pos_disp(char **);

/* my_strcmp.c */
int my_strcmp(char const *s1, char const *s2);
int my_strcmp2(char *str, char *is_in);

/* create_argv.c */
char **create_argv(char *);

/* exec.c */
int exec(char **, char **, int *);

/* clean_string.c */
char *clean_string(char *);

/* str_adopte.c */
char *str_adopte(char *, int);

/* in_path.c */
void path_argv(char **, char **, int *);

/* signal.c */
void signal_transform(char **);

/* first_word.c */
char quote_change(int *quote, char carac, char quote_type);
char *first_word(char *str, int *size);

/* symbol.c */
char *symbol(char *str);

/* commande_line_test.c */
int test_commande_line(char *str);

/* new_create_argv.c */
char **new_create_argv(char *str, int *size_argv);

/* pipe.c */
void close_pipe0(int pipefd[], int *fd_0, int *fd_1);
void close_pipe1(int pipefd[], int *fd_0, int *fd_1);
void open_pipe0(int pipefd[], int *fd_0, int *fd_1);
int *create_pipe(int *fd_0, int *fd_1, int pipefd[]);

/* exec_command.c */
int exec_command(char *str, char **env, char *buf);

char my_strncmp(char const *s1, char const *s2, int n);

int cd(char **argv, char *buf2);

void my_putstr(char const *str);

struct all
{
    char *last;
    char *temp;
};
typedef struct all all;
all io;

#endif /* !_42SH_H */