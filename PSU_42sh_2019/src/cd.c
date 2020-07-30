/*
** EPITECH PROJECT, 2020
** cd
** File description:
** c
*/

#include "42sh.h"

int cd2(char **argv, char *cwd, char *temp, char *buf)
{
    if (my_strcmp(io.temp, buf) != 0) {
        io.last = malloc(sizeof(char) * 200);
        for (int i = 0; io.temp[i] != '\0'; i++)
            io.last[i] = io.temp[i];
    }
    if (my_strcmp(buf, io.temp) != 0) {
        io.temp = malloc(sizeof(char) * 200);
        for (int i = 0; buf[i] != '\0'; i++)
            io.temp[i] = buf[i];
    }
    if (argv[1] == NULL) {
        chdir(getenv("HOME"));
        return 1;
    }
    return 0;
}

void cd3(char **argv, char *temp, int t, char *buf)
{
    if (my_strcmp(argv[1], "--") == 0)
        chdir(getenv("OLDPWD"));
    if (my_strcmp(argv[1], "-") == 0)
        chdir(io.last);
    if (my_strcmp(argv[1], "--") != 0 &&
        my_strcmp(argv[1], "-") != 0) {
        my_putstr(argv[1]);
        if (stat(argv[1], &temp) == 0)
            my_putstr(": Not a directory.\n");
        else
            my_putstr(": No such file or directory.\n");
    }
}

int cd(char **argv, char *buf)
{
    char *cwd = malloc(sizeof(char) * 100);
    char *temp = malloc(sizeof(char) * 32);
    int t = 3;
    int test = cd2(argv, cwd, temp, buf);

    if (test == 0) {
        if (chdir(argv[1]) == - 1  && argv[1] != NULL)
            cd3(argv, temp, t, buf);
        return (1);
    }
    return test;
}