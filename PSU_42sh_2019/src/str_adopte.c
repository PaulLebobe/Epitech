/*
** EPITECH PROJECT, 2020
** str2 = str1[0] to str1[x]
** File description:
** c
*/

#include "42sh.h"

char *str_adopte(char *str1, int size)
{
    int i = 0;
    char *str2 = malloc(sizeof(char) * (size + 1));

    for (i = 0; i < size; i++)
        str2[i] = str1[i];
    str2[i] = '\0';
    return (str2);
}