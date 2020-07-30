/*
** EPITECH PROJECT, 2020
** main
** File description:
** c
*/

#include "../include/42sh.h"

int main(int argc, char **av, char **envpath)
{
    int quit = 0;
    char *str;
    char **argv;
    char *buf = malloc(sizeof(char) * 200);
    io.temp = malloc(sizeof(char) * 200), io.last = malloc(sizeof(char) * 200);

    getcwd(io.temp, 200);
    while (quit == 0) {
        getcwd(buf, 200);
        my_putstr(buf), my_putstr(" ->");
        str = read_term();
        str = clean_string(str);
        exec_command(str, envpath, buf);
    }
    return (0);
}