/*
** EPITECH PROJECT, 2020
** my_put_string
** File description:
** c
*/

#include "include_lib/include_lib.h"

int my_putstring(char *str, int line_break)
{
    int size_string = 0;

    if (str == NULL)
        return (84);
    for (size_string = 0; str[size_string]; size_string++);
    write(1, str, size_string);
    if (line_break != 0)
        write(1, "\n", 1);
    return (0);
}