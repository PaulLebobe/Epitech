/*
** EPITECH PROJECT, 2020
** redirections
** File description:
** redirections
*/

#ifndef REDIRECTIONS_H_
#define REDIRECTIONS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../include/42sh.h"
#include "../../lib_my/include_lib/include_lib.h"

/* write_redirec.c */
void exit_redirection(int new_fd, int *current_fd);
int write_redirection1(char *file);
int write_redirection2(char *file);

/* read_redirec.c */
int read_redirection1(char *file);
int read_redirection2(char *folder);

/* condition_to_use_redirection.c */
int write_redirection(char *str);
int read_redirection(char *str);
void redirection(int *fd_0, int *fd_1, int size, char *str);

#endif /* !REDIRECTIONS_H_ */