/*
** EPITECH PROJECT, 2020
** CPEs2
** File description:
** pair
*/

#include "../include/generate.h"

void pair(char **laby)
{
    if (my_strlen_2d(laby) % 2 == 0) {
        for (int i = 0; i < my_strlen(laby[0]); i += 2)
            laby[my_strlen_2d(laby) - 1][i] = '*';
    }
    if (my_strlen(laby[0]) % 2 == 0) {
        for (int i = 0; i < my_strlen_2d(laby); i += 2)
            laby[i][my_strlen(laby[0]) - 1] = '*';
    }
    if (my_strlen_2d(laby) % 2 == 0 && my_strlen(laby[0]) % 2 == 0
        && my_strlen_2d(laby) - 2 >= 0)
        laby[my_strlen_2d(laby) - 2][my_strlen(laby[0]) - 1] = 'X';
    laby[my_strlen_2d(laby) - 1][my_strlen(laby[0]) - 1] = '*';
}