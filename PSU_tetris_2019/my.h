/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <getopt.h>
#include <time.h>
struct arg_opt
{
    int level;
    int left;
    int right;
    int turn;
    int drop;
    int quit;
    int pause;
    int row;
    int col;
    char *next;
    int dbg;
};
typedef struct arg_opt arg_opt;
arg_opt opt;
static struct option long_options[] =
{
    {"level=", required_argument, NULL, 'L'},
    {"key-left=", required_argument, NULL, 'l'},
    {"key-right=", required_argument, NULL, 'r'},
    {"key-turn=", required_argument, NULL, 't'},
    {"key_drop=", required_argument, NULL, 'd'},
    {"key-quit=", required_argument, NULL, 'q'},
    {"key-pause=", required_argument, NULL, 'p'},
    {"without-next", required_argument, NULL, 'w'},
    {"map-size=", required_argument, NULL, 'm'},
    {NULL, 0, NULL, 0}
};
struct termi
{
    int error;
    char *path;
    int fill;
    int wight;
    int height;
    int color;
    char *tmp;
    char **piece;
};
typedef struct termi termi;
termi io[50];
struct all
{
    char **map;
    int score;
    int start;
    int win;
    int nb;
    int x;
    int x2;
    int y;
    int y2;
    int lines;
    int max;
    int next;
    int turn;
};
typedef struct all all;
all elem;
struct fall
{
    int nb;
    int speed;
    int new;
    clock_t cl;
    clock_t temp;
};
typedef struct fall fall;
fall act;
long f_size(const char *filename);
void f_buff(char *path);
int fill_struct(char *buff);
int fill_tetriminos(void);
void game(void);
int my_putchar(char x);
void my_putstr(char const *str);
void my_putarray(char **str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void init(void);
int to_ascii(char c);
void resize(char *str);
int my_putnbr(int nb);
void w_map(void);
void check_stop(void);
void moves(int cd);
void check_line(void);
void erase_p(void);
void moves2(int cd, int test);
void p_score(void);
char *into_str(int nb);
void p_lines(void);
void p_score(void);
int rand_inter(int i, int x);
void p_next(void);
void moves3(int cd, int test);
void debug(void);
void debug2(void);
void check_over(void);
void new_fall(void);
#endif /* !MY_H_ */