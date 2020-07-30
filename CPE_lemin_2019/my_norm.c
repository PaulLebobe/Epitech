/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#include "my.h"

int my_norm_1(int i, char **tab)
{
    int j = 0;

    if (is_exist(tab[i], '#') == 0 && is_exist(tab[i], ' ') == 0 &&
        is_exist(tab[i], '-') >= 0 && elem.nb_ant == 0) {
        while (tab[i][j] != '\0') {
            if ((tab[i][j] < '0' || tab[i][j] > '9') && tab[i][j] != '-') {
                my_putstr("INVALID ANTS NB\n");
                return (84);
            }
            j++;
        }
    }
    return (0);
}

int my_norm_2(int i, char **tab)
{
    return (0);
}