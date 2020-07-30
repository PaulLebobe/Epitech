/*
** EPITECH PROJECT, 2020
** my_split_str.c
** File description:
** split str
*/

#include "my.h"

char **my_split_str(char **tab)
{
    int i = 0;
    char **dest = malloc(sizeof(char *) * 2);

    dest[0] = "\0";
    dest[1] = NULL;
    while (tab[i] != NULL) {
        if (i > 0)
            *dest = malloc_str(*dest, "-");
        *dest = malloc_str(*dest, tab[i]);
        i = i + 1;
    }
    return (dest);
}