/*
** EPITECH PROJECT, 2020
** read_term
** File description:
** c
*/

#include "42sh.h"

char *read_term(void)
{
    char *str = '\0';
    char ok = '\0';
    int i = 0;

    str = malloc(sizeof(char) * 2);
    str[0] = '\0';
    read(0, &ok, 1);
    str[0] = ok;
    for (i = 1; ok != '\n' && ok != '\0'; i++) {
        str = my_realloc_char_star(str, i + 1);
        read(0, &ok, 1);
        str[i] = ok;
    }
    str[i] = '\0';
    if (ok == '\0') {
        free(str);
        my_putstring("exit", 1);
        exit(0);
    }
    return (str);
}