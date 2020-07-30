/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** print_nbr
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;
    int sign = 1;

    while (1) {
        if ((str[i] < '0' && str[i] != '+' && str[i]
        != '-') || str[i] > '9' || str[i] == '\0')
            break;
        sign =  (str[i] == '-') ? - sign : sign;
        i = (str[i] == '-') ? i + 1 : i;
        while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0') {
            nb = nb + str[i] - 48;
            nb = nb * 10;
            i = i + 1;
        }
    }
    nb = nb / 10 * sign;
    return nb;
}

void resize(char *str)
{
    int e = 0;

    for (int i = 0; str[i]; i++)
        e = (str[i] == ',') ? i : e;
    if (e == 0)
        exit(84);
    opt.row = my_getnbr(str);
    opt.col = my_getnbr(str + e + 1);
}