/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** print
*/

#include "my.h"

void print_par2(void)
{
    my_putstr("#tunnels\n");
    for (int i = 0; tu[i].room != NULL; i++)
        if (tu[i].room != NULL) {
            my_putstr(tu[i].room);
            my_putchar('-');
            my_putstr(tu[i].room2);
            my_putchar('\n');
    }
    my_putstr("#moves\n");
}

void print_par(void)
{
    my_putstr("#number_of_ants\n");
    my_putnbr(elem.nb_ant);
    my_putstr("\n#rooms\n");
    for (int i = 0; io[i].name != NULL; i++) {
        if (my_strcmp(io[i].name, elem.entr) == 0)
            my_putstr("##start\n");
        if (my_strcmp(io[i].name, elem.exit) == 0)
            my_putstr("##end\n");
        my_putstr(io[i].name);
        my_putchar(' ');
        my_putnbr(io[i].x);
        my_putchar(' ');
        my_putnbr(io[i].y);
        my_putchar('\n');
    }
    print_par2();
}