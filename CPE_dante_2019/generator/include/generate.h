/*
** EPITECH PROJECT, 2020
** CPEs2
** File description:
** generate
*/

#ifndef GENERATE_H_
#define GENERATE_H_

#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include "../src/lib_my/include_lib/include_lib.h"
#include "struct.h"

/* dig.c */
void create_road(int x, int y, road_t *road);
void dig_way2(int x, int y, char **laby, road_t *road);
int dig_way(int x, int y, char **laby, road_t *road);
int new_dig(char **laby, road_t *road);
void dig_rec(char **laby);

/* dig2.c */
int new_dig2(int *value, road_t *road, char **laby);

/* way_free.c */
int test_way_free(char **laby, int x, int y, road_t *road);
int *way_free(char **laby, road_t *road);

/* rm_road.c */
void rm_road(road_t **road);
void to_rm_road(char **laby, road_t **road);

/* pair.c */
void pair(char **laby);

/* imperfect.c */
void imperfect(char **laby);

#endif /* !GENERATE_H_ */
