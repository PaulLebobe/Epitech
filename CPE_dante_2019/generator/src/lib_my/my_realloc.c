/*
** EPITECH PROJECT, 2020
** my_realloc
** File description:
** c
*/

#include "include_lib/include_lib.h"

char *my_realloc_char_star(char *buf, int const size)
{
    int i = 0;
    char *save = 0;

    save = malloc(sizeof(char) * (size + 1));
    for (i = 0; buf[i] != '\0'; i++)
        save[i] = buf[i];
    save[i] = '\0';
    free(buf);
    buf = malloc(sizeof(char) * (size + 1));
    for (i = 0; save[i] != '\0'; i++)
        buf[i] = save[i];
    buf[i] = '\0';
    free(save);
    return (buf);
}