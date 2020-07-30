/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#include "my.h"

void do_links2(struct room *sm_room, int tmp_s, struct room *tmp)
{
    if (sm_room->min > tmp_s) {
        sm_room->min = tmp_s;
        sm_room->prev = tmp->name;
    }
}

void do_links(struct room *tmp, struct room *rooms, int size)
{
    int i = 0;
    char *name = NULL;
    struct room *sm_room = NULL;
    int tmp_s = 0;

    while (i < elem.nb_tu) {
        if ((my_strcmp(tu[i].room, tmp->name) == 0 ||
            my_strcmp(tu[i].room2, tmp->name) == 0)) {
            name = room_name(tu[i].room, tu[i].room2, tmp->name);
            sm_room = s_room_val(name, rooms, size);
            if (sm_room != NULL) {
                tmp_s = 1 + tmp->min;
                if (sm_room->min == -1) {
                    sm_room->min = tmp_s;
                    sm_room->prev = tmp->name;
                }
                do_links2(sm_room, tmp_s, tmp);
            }
        }
        i++;
    }
}

int count_line(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        i++;
    }
    return (i);
}