/*
** EPITECH PROJECT, 2019
** my_putnbr
** File description:
** print number
*/

#include "my.h"

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