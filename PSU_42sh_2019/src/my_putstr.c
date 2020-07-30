/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** abc
*/

#include "42sh.h"

int my_putchar(char x)
{
    write(1, &x, 1);
}

void my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
}