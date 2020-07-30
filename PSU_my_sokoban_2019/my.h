/*
** EPITECH PROJECT, 2019
** My_Sokoban
** File description:
** Include
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

long f_size(const char *filename);
char **to_char(char *buff, int lines, int cols);
void find_p(char **str, int *x, int *y);
void init_w(char *buff, int tot);
void game(char **str, int *cd, int tot, char *buff);
void init_w2(char *buff, int *lines, int *cols);
void my_switch5(char **str, char *buff, int tot, int *cd);
void my_switch4(char **str, char *buff, int tot, int *cd);
void my_switch3(char **str, char *buff, int tot, int *cd);
void my_switch2(char **str, char *buff, int tot, int *cd);
void my_switch(char **str, char *buff, int tot, int *cd);
void block(char **str, int tot);