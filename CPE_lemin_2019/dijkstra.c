/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#include "my.h"

struct room *update_room(struct room *rooms, int size)
{
    struct room *swap = NULL;

    swap = s_room_val(elem.entr, rooms, size);
    swap->name = rooms->name;
    rooms->name = my_strdup(elem.entr);
    rooms->min = 0;
    rooms->visited = 0;
    return (rooms);
}

char **dijkstra(void)
{
    struct room *tmp = NULL;
    struct room *rooms = io;
    int size = elem.room;
    rooms = update_room(rooms, size);
    struct room *endr = s_room_val(elem.exit, rooms, size);
    char **tab = NULL;
    char **result = NULL;
    int j = -1;

    while ((tmp = fetch_room(rooms, size)) != NULL)
        do_links(tmp, rooms, size);
    while (endr->prev != NULL) {
        tab = my_add_str(tab, endr->name);
        endr = s_room_val(endr->prev, rooms, size);
    }
    tab = my_add_str(tab, endr->name);
    result = my_split_str(my_reverse_tab(tab));
  
    return (result);
}