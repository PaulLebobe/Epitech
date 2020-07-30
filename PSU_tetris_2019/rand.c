/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** rand
*/

#include "my.h"

int rand_inter(int i, int x)
{
    return (rand() % (x - i) + i);
}