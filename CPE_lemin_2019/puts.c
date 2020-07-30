/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** puts
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