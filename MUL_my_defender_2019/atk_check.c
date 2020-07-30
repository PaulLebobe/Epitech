/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** atk_check
*/

#include "my.h"

void att_check(void)
{
    for (int i = 0; i < 12; i++)
        for (int e = 0; e < 50; e++) {
            if (ia[i].target[e] < 100 && zo2[ia[i].target[e]].life <= 0)
                ia[i].set[e] = 0;
            if (ia[i].target[e] > 99 && ia[i].target[e] < 300 && zo1[ia[i].
            target[e] - 100].life <= 0)
                ia[i].set[e] = 0;
            if (ia[i].target[e] >  299 && zo3[ia[i].target[e] - 300].life <= 0)
                ia[i].set[e] = 0;
        }
}