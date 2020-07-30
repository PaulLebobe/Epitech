/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
struct dat
{
    int lign;
    int col;
    int find;
};
typedef struct dat dat;
dat io;
long f_size(const char *filename);
char **buffer(char **av);
int main(int ac, char **av);
char **to_array(char *str);
int my_putchar(char x);
void my_putstr(char const *str);
void my_putarray(char **str);
int my_strcmp(char const *s1, char const *s2);
char **cr_temp(char **buff);
#endif /* !MY_H_ */