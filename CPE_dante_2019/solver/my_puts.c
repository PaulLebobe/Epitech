/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** my_puts
*/

#include "my.h"

int my_putchar(char x)
{
    write(1, &x, 1);
}

void my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
}

void my_putarray(char **str)
{
    for (int i = 0; i < io.lign + 1; i++) {
        my_putstr(str[i]);
        if (i < io.lign)
            my_putchar('\n');
    }
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        i++;
        if (s1[i] == '\0' || s2[i] == '\0')
            return 0;
    }
    return s1[i] - s2[i];
}