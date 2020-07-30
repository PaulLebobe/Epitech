/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** c
*/

#include "include_lib/include_lib.h"

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}