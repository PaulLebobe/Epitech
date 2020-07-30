/*
** EPITECH PROJECT, 2020
** Matchstick
** File description:
** Include
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_getnbr(char const *str);
void my_putstr(char const *str);
void my_putchar(char c);
void my_putnbr(int nb);
int my_strlen(char const *str);
int rand_inter(int i, int x);
int input(char *s,int length);
void tree_print(char **tree);
int is_nb(char *buff);
void comput_print(int *nb);
int *comput(int lines, int max, int *nb, char **tree);
int *comput2(int *nb, int max, char **tree);
int *compute3(int *tot, char **tree, int e);
char **modif(int *nb, char **tree);
char **make_t(int lines);
int game3(char **tree, int turn);
int game2(char **tree, int*nb, int i);
int game(char **tree, int lines, int max, int *nb);
int my_input4(int temp, int *nb, int max);
int *my_input3(int *nb, size_t test);
int *my_input2(int *nb, size_t test, int lines);
void input_print(int *nb);
int *my_input(int lines, int max, int *nb, char **tree);
#endif /* !MY_H_ */