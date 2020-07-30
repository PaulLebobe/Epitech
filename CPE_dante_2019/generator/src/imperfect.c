/*
** EPITECH PROJECT, 2020
** CPEs2
** File description:
** imperfect
*/

#include "../include/generate.h"

int laby_place(char **laby)
{
    int j = 0;
    int star = 0;

    for (int i = 0; laby[j] != NULL; i++) {
        if (laby[j][i] == '*')
            star++;
        if (laby[j][i] == '\0') {
            j++;
            i = 0;
        }
    }
    return (star);
}

static void transform_laby(char **laby)
{
    int x_rand = 0;
    int y_rand = 0;
    int more1 = 0;
    int change = 0;

    while (change == 0) {
        x_rand = rand() % (my_strlen(laby[0]) / 2 - 0) + 0;
        y_rand = rand() % (my_strlen_2d(laby) / 2 - 0) + 0;
        x_rand *= 2;
        y_rand *= 2;
        more1 = rand() % 2;
        more1 == 1 ? y_rand++ : x_rand++;
        if (y_rand < my_strlen_2d(laby) && x_rand <
            my_strlen(laby[0]) && laby[y_rand][x_rand] == 'X') {
            laby[y_rand][x_rand] = '*';
            change++;
        }
    }
}

void imperfect(char **laby)
{
    int randomer = (rand() % (((my_strlen(laby[0]) * my_strlen_2d(laby)) -
    (my_strlen(laby[0]) * my_strlen_2d(laby)) / 2)) + ((my_strlen(laby[0])
    * my_strlen_2d(laby)) / 2)) / 10;

    for (int i = 0; i < randomer && laby_place(laby) != 0; i++) {
        transform_laby(laby);
    }
}