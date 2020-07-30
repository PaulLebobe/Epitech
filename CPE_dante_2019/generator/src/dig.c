/*
** EPITECH PROJECT, 2020
** src
** File description:
** dig
*/

#include "../include/generate.h"

void create_road(int x, int y, road_t *road)
{
    road_t *next_road = NULL;

    while (road->next != NULL)
        road = road->next;
    next_road = malloc(sizeof(road_t));
    next_road->last = road;
    next_road->next = NULL;
    road->next = next_road;
    next_road->pos_x = x;
    next_road->pos_y = y;
}

void dig_way2(int x, int y, char **laby, road_t *road)
{
    while (road->next != NULL)
        road = road->next;
    if (y < road->pos_y)
        laby[y + 1][x] = '*';
    if (y > road->pos_y)
        laby[y - 1][x] = '*';
    if (x < road->pos_x)
        laby[y][x + 1] = '*';
    if (x > road->pos_x)
        laby[y][x - 1] = '*';
    laby[y][x] = '*';
}

int dig_way(int x, int y, char **laby, road_t *road)
{
    if (x >= 0 && y >= 0 && x < my_strlen(laby[0]) && y < my_strlen_2d(laby)) {
        if (laby[y][x] == 'X') {
            dig_way2(x, y, laby, road);
            create_road(x, y, road);
            return (1);
        }
    }
    return (0);
}

int new_dig(char **laby, road_t *road)
{
    int success = 0;
    int *value = NULL;

    while (road != NULL && road->next != NULL)
        road = road->next;
    value = way_free(laby, road);
    if (value[0] == 1 && value[1] == 1 && value[2] == 1 && value[3] == 1) {
        free(value);
        return (-1);
    }
    while (success == 0) {
        success = new_dig2(value, road, laby);
    }
    free(value);
    return (0);
}

void dig_rec(char **laby)
{
    road_t *road = malloc(sizeof(road_t));

    road->next = NULL;
    road->last = NULL;
    road->pos_x = 0;
    road->pos_y = 0;
    while (road != NULL) {
        if (new_dig(laby, road) == -1) {
            to_rm_road(laby, &road);
        }
    }
    pair(laby);
}