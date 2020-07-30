/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#include "my.h"

struct room *fetch_room(struct room *rooms, int size)
{
    int i = 0;

    while (i < size) {
        if (rooms[i].visited == 0 && rooms[i].min != -1) {
            rooms[i].visited = 1;
            return (&(rooms[i]));
        }
        i++;
    }
    return (NULL);
}

struct room *s_room_val(char *name, struct room *rooms, int size)
{
    int i = 0;

    while (i < size) {
        if (my_strcmp(rooms[i].name, name) == 0)
            return (&(rooms[i]));
        i = i + 1;
    }
    return (NULL);
}