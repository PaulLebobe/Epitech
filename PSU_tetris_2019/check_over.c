/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** check_over
*/

#include "my.h"

void check_over(void)
{
    for (int i = 0; io[elem.next].piece[i] != NULL; i++)
        for (int e = 0; io[elem.next].piece[i][e] != '\n'; e++)
            if (elem.map[i][opt.col + 30 - io[elem.next].wight] > '0' &&
            elem.map[i][opt.col + 30 - io[elem.next].wight] < '9') {
                endwin();
                exit(0);
            }
}