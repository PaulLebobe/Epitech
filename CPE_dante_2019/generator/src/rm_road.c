/*
** EPITECH PROJECT, 2020
** CPEs2
** File description:
** rm_road
*/

#include "../include/generate.h"

void rm_road(road_t **road)
{
    road_t *road_end = NULL;

    while ((*road)->next != NULL)
        *road = (*road)->next;
    road_end = *road;
    *road = (*road)->last;
    free(road_end);
    if (*road != NULL)
        (*road)->next = NULL;
}

void to_rm_road(char **laby, road_t **road)
{
    int *value = malloc(sizeof(int) * 4);

    do {
        free(value);
        if (*road != NULL) {
            rm_road(road);
            value = way_free(laby, *road);
        }
    } while (value[0] == 1 && value[1] == 1 && value[2] == 1
    && value[3] == 1 && *road != NULL);
}