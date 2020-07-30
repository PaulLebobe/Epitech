/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** c
*/

#include "42sh.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] == s2[i]; i++)
        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
    return s1[i] - s2[i];
}

int my_strcmp2(char *str, char *is_in)
{
    int i = 0;
    int size2 = 0;
    int is_ok = 0;

    for (size2 = 0; is_in[size2]; size2 += 1);
    for (i = 0; str[i]; i++) {
        if (str[i] == is_in[is_ok]) {
            is_ok++;
        } else
            is_ok = 0;
        if (is_ok == size2)
            return (1);
    }
    return (0);
}