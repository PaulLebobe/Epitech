/*
** EPITECH PROJECT, 2019
** Navi
** File description:
** include
*/

#ifndef MY_H_
#define MY_H_

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

struct mess
{
    int status;
    int pid;
    int cd;
    int cd2;
    int pass;
};
typedef struct mess mess;
mess io;
int my_putchar(char x);
void my_putstr(char const *str);
void my_putarray(char **str);
void buffer(int nb, char **av, char *buff);
char *fill_buff(int ac, char **av, char *buff);
char **fill_map2(char **map, char *buff);
char **fill_map(char *buff, int nb);
char *my_input(char *buff2, char **map2);
char **game(char **map, char **map2);
int my_putnbr(int nb);
int my_getnbr(char const *str);
void hdl(int sig);
void hdl2(int sig);
void hdl3(int sig);
void hdl4(int sig);
void hdstop(int sig);
int atk(char *buff);
char **game_pass(char **map, char **map2);
void f_pid(int sig, siginfo_t *siginfo, void *context);
char **touch(char **map);
void init(void);
int check_buff(char *buff);
void final_print(char **map, char **map2, int nb);
int file_check(int ac, char **av);
#endif /* !MY_H_ */