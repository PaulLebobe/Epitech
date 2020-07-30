/*
** EPITECH PROJECT, 2020
** my_strlen_2d
** File description:
** c
*/

#include "include_lib/include_lib.h"

int my_strlen_2d(char **str)
{
    int i = 0;

    for (i = 0; str[i] != NULL; i++);
    return (i);
}