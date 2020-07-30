/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** str_copy
*/

#include "include_lib/include_lib.h"

char *str_copy(char *str)
{
    char *copy = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    for (i = 0; str[i]; i++)
        copy[i] = str[i];
    copy[i] = '\0';
    return (copy);
}

char *str_ncopy(char *str, int lenght)
{
    char *copy = malloc(sizeof(char) * (lenght + 1));
    int i = 0;

    for (i = 0; str[i] && i < lenght; i++)
        copy[i] = str[i];
    for (i = i; i <= lenght; i++)
        copy[i] = '\0';
    return (copy);
}