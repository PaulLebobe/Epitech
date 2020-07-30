/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** abc
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
    for (int i = 0; str[i] != NULL; i++)
        my_putstr(str[i]);
}

int my_putnbr(int nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb > 9)
        my_putnbr(nb / 10);
    my_putchar(nb % 10 + '0');
}

void final_print(char **map, char **map2, int nb)
{
    my_putstr("\nmy_positions:\n");
    my_putarray(map2);
    my_putstr("\nenemy's positions:\n");
    my_putarray(map);
    nb == 1 ? my_putstr("\nEnnemy won\n") : my_putstr("\nI won\n");
}