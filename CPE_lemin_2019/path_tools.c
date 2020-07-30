/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#include "my.h"

int rooms_val(path **paths, int idx)
{
    int i = -1;

    while (paths[++i] != NULL) {
        if (my_strcmp(paths[i]->room, elem.entr) == 0)
            paths[i]->tunnel = elem.nb_ant;
        if (my_strcmp(paths[i]->room, elem.exit) == 0)
            paths[i]->tunnel = 0;
            idx = i;
    }
    return (idx);
}