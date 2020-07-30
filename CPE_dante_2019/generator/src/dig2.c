/*
** EPITECH PROJECT, 2020
** CPEs2
** File description:
** dig2
*/

#include "../include/generate.h"

int new_dig2(int *value, road_t *road, char **laby)
{
    int direction = rand() % (3 - 0 + 1) + 0;

    while (value[direction] == 1)
        direction = rand() % (3 - 0 + 1) + 0;
    if (direction == 0)
        return (dig_way(road->pos_x + 2, road->pos_y, laby, road));
    if (direction == 1)
        return (dig_way(road->pos_x - 2, road->pos_y, laby, road));
    if (direction == 2)
        return (dig_way(road->pos_x, road->pos_y + 2, laby, road));
    if (direction == 3)
        return (dig_way(road->pos_x, road->pos_y - 2, laby, road));
    return (0);
}