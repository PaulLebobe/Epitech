/*
** EPITECH PROJECT, 2019
** my put nbr
** File description:
** display number given in parameter
*/

#include "my.h"

void print_my_nbr(int nbr)
{
    int digit = nbr % 10;
    if (nbr / 10 != 0)
        print_my_nbr(nbr / 10);
    if (digit >= 0)
        my_putchar(digit + 48);
    if (digit < 0)
        my_putchar((-digit) + 48);
    return;
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        nb = 147483648;
        my_putchar('-');
        my_putchar('2');
    }
    if (nb < 0){
        nb = -nb;
        my_putchar('-');
    }
    print_my_nbr(nb);
    return (0);
}
