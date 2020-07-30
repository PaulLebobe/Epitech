/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** cr_attacks
*/

#include "my.h"

void cr_atkz2(int i)
{
    int w;

    for (int x = 0; x < 50; x++)
        if (tw[i].pos.x < zo2[x].pos.x + tw[i].range && tw[i].pos.x > zo2[x].
        pos.x - tw[i].range && tw[i].pos.y < zo2[x].pos.y + tw[i].range && tw
        [i].pos.y > zo2[x].pos.y - tw[i].range && tw[i].set != -1  && tw[i].set
        != 3 && sfClock_getElapsedTime(ia[i].cl).microseconds > tw[i].speed) {
            w = 0;
            for (; ia[i].set[w] == 1; w++);
            ia[i].set[w] = 1;
            ia[i].target[w] = x;
            ia[i].pos[w] = tw[i].pos;
            ia[i].pos[w].x += 20;
            sfClock_restart(ia[i].cl);
        }
}

void cr_atkz1(int i)
{
    int w = 0;

    for (int x = 0; x < 200; x++)
        if (tw[i].pos.x < zo1[x].pos.x + tw[i].range && tw[i].pos.x > zo1[x].
        pos.x - tw[i].range && tw[i].pos.y < zo1[x].pos.y + tw[i].range &&
        tw[i].pos.y > zo1[x].pos.y - tw[i].range && tw[i].set != -1 && tw[i].
        set != 3 && sfClock_getElapsedTime(ia[i].cl).microseconds > tw[i].
        speed) {
            w = 0;
            for (; ia[i].set[w] == 1; w++);
            ia[i].set[w] = 1;
            ia[i].target[w] = x + 100;
            ia[i].pos[w] = tw[i].pos;
            ia[i].pos[w].x += 20;
            sfClock_restart(ia[i].cl);
        }
}

float order2(int i, float tmp)
{
    for (int x = 0; x < 50; x++)
        if (tw[i].pos.x < zo2[x].pos.x + tw[i].range && tw[i].pos.x > zo2
        [x].pos.x - tw[i].range && tw[i].pos.y < zo2[x].pos.y + tw[i].
        range && tw[i].pos.y > zo2[x].pos.y - tw[i].range &&
        tw[i].set != -1  && tw[i].set != 3 && sfClock_getElapsedTime(ia[i].
        cl).microseconds > tw[i].speed)
            tmp = (zo2[x].pos.x < tmp) ? zo2[x].pos.x : tmp;
    return (tmp);
}

int order_atk(int test, float tmp, int i)
{
    tmp = order2(i, tmp);
    for (int x = 0; x < 200; x++)
        if (tw[i].pos.x < zo1[x].pos.x + tw[i].range && tw[i].pos.x > zo1
        [x].pos.x - tw[i].range && tw[i].pos.y < zo1[x].pos.y + tw[i].
        range && tw[i].pos.y > zo1[x].pos.y - tw[i].range && tw[i].set
        != -1 && tw[i].set != 3 && sfClock_getElapsedTime(ia[i].cl).
        microseconds > tw[i].speed) {
            test = (zo1[x].pos.x < tmp) ? 1 : test;
            tmp = (zo1[x].pos.x < tmp) ? zo1[x].pos.x : tmp;
        }
    for (int x = 0; x < 20; x++)
        if (tw[i].pos.x < zo3[x].pos.x + tw[i].range && tw[i].pos.x > zo3
        [x].pos.x - tw[i].range && tw[i].pos.y < zo3[x].pos.y + tw[i].
        range && tw[i].pos.y > zo3[x].pos.y - tw[i].range && tw[i].set
        != -1 && tw[i].set != 3 && sfClock_getElapsedTime(ia[i].cl).
        microseconds > tw[i].speed) {
            test = (zo3[x].pos.x < tmp) ? 2 : test;
            tmp = (zo3[x].pos.x < tmp) ? zo3[x].pos.x : tmp;
        }
    return (test);
}

void cr_atk(sfRenderWindow *window)
{
    int test = 0;
    float tmp = 2000;

    for (int i = 0; i < 12; i++) {
        test = order_atk(test, tmp, i);
        if (test == 0)
            cr_atkz2(i);
        if (test == 1)
            cr_atkz1(i);
        if (test == 2)
            cr_atkz3(i);
        cr_atkt4(i, window);
    }
}