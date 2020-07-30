/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct data
{
    int tunnel;
    int nb_ant;
    int nb_tu;
    int end_nb;
    int st;
    int ex;
    char *entr;
    char *exit;
    int room;
    int ent;
    int ext;
    int nb_path;
    char **tmp_rooms;
    char **file_data;
    char **tmp_tu;
    char *end_room;
};
typedef struct data data;
data elem;

struct room
{
    int end;
    char *name;
    char *prev;
    int x;
    int y;
    int nb;
    int visited;
    int min;
};
typedef struct room room;
room io[1000];
struct tunnel
{
    char *room;
    char *room2;
};
typedef struct tunnel tunnel;
tunnel tu[1000];
struct path
{
    int end;
    int size;
    int tunnel;
    char *pos;
    char *room;
};
typedef struct path path;
path pt[1000];

typedef struct v_graph {
int line_of_ants_nb;
int line_of_room_ref;
int line_of_pipe_ref;
} t_graph;

int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_putchar(char x);
void my_putstr(char const *str);
int my_putnbr(int nb);
void print_par(void);
void print_par2(void);
void f_path2(path p);
void f_path3(int x, path test, int tmp);
void f_path4(int x, path test, int tmp);
void f_path(void);
void p_path(void);
int is_num(char *str);
int is_exist(char *str, char c);
void do_links(struct room *tmp, struct room *io, int size);
char **do_dijkstra(struct room *rooms, int size);
char **dijkstra(void);
void draw_tmp_tu(char *buff, int *j);
int my_strlen(char const *str);
char *my_strdup(char *str);
int f_struct(char *buff);
int f_struct1(char *buff);
int f_struct2(char *name, char *buff);
int f_struct3(char *name, char *buff);
struct room *s_room_val(char *name, struct room *rooms, int size);
char **my_add_str(char **str1, char *str2);
int my_tab_size(char **str);
char **my_split_str(char **tab);
char **my_reverse_tab(char **tab);
char *malloc_str(char *str, char *str2);
char *room_name(char *str, char *str2, char *s);
struct room *fetch_room(struct room *rooms, int size);
int count_line(char **tab);
void *my_malloc(int idx);
int parse_file(void);
void draw_tmp_room(char *buff);
int my_norm_tools(int i, char **tab);
int fuck_file(void);
int verif_double_name(void);
int my_norm_1(int i, char **tab);
int my_norm_2(int i, char **tab);
char **rm_nslash(char **tab);
char **str_to_word_tab(char *buff, char c);
int do_path(char **tab);
void display_tools(path **paths, int endr);
int rooms_val(path **paths, int idx);
void display_r(int r, char *n, int space);
int f_buff(int i);
void f_struct1b(char *buff, char *name, int temp, int w);
#endif /* !MY_H_ */