/*
** EPITECH PROJECT, 2020
** CPEs2
** File description:
** way_free
*/

#include "../include/generate.h"

int test_way_blocked_x(int x, road_t *road)
{
    while (road->next != NULL)
        road = road->next;
    if (road->pos_x < x)
        return (road->pos_x + 1);
    if (road->pos_x > x)
        return (road->pos_x - 1);
    return (road->pos_x);
}

int test_way_blocked_y(int y, road_t *road)
{
    while (road->next != NULL)
        road = road->next;
    if (road->pos_y < y)
        return (road->pos_y + 1);
    if (road->pos_y > y)
        return (road->pos_y - 1);
    return (road->pos_y);
}

int test_way_free(char **laby, int x, int y, road_t *road)
{
    while (road->next != NULL)
        road = road->next;
    if (x >= 0 && x < my_strlen(laby[0]) && y >= 0 && y <
        my_strlen_2d(laby)) {
        if (laby[y][x] == 'X')
            return (0);
    }
    return (1);
}

int *way_free(char **laby, road_t *road)
{
    int *value = malloc(sizeof(int) * 4);

    while (road != NULL && road->next != NULL)
        road = road->next;
    if (road != NULL) {
    value[0] = test_way_free(laby, road->pos_x + 2, road->pos_y, road);
    value[1] = test_way_free(laby, road->pos_x - 2, road->pos_y, road);
    value[2] = test_way_free(laby, road->pos_x, road->pos_y + 2, road);
    value[3] = test_way_free(laby, road->pos_x, road->pos_y - 2, road);
    } else {
        for (int i = 0; i < 4; i++)
            value[i] = 1;
    }
    return (value);
}