/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** attacks
*/

#include "my.h"

void atkzo2(int i, int e, sfRenderWindow *window)
{
    float dx;
    float dy;

    sfSprite_setPosition(ia[i].sprite, ia[i].pos[e]);
    sfRenderWindow_drawSprite(window, ia[i].sprite, NULL);
    dx = ia[i].pos[e].x - zo2[ia[i].target[e]].pos.x - 20;
    dy = ia[i].pos[e].y - zo2[ia[i].target[e]].pos.y - 20;
    while (dx > 4 || dy > 4 || dx < -4 || dy < -4) {
        dx = dx / 2;
        dy = dy / 2;
    }
    ia[i].pos[e].x -= dx;
    ia[i].pos[e].y -= dy;
}

void atkzo2k(int i, int e)
{
    if (ia[i].pos[e].x > zo2[ia[i].target[e]].pos.x && ia[i
    ].pos[e].x < zo2[ia[i].target[e]].pos.x + 100 && ia[i].pos
    [e].y > zo2[ia[i].target[e]].pos.y - 50 && ia[i].pos[e].y <
    zo2[ia[i].target[e]].pos.y + 70) {
        ia[i].set[e] = 0;
        zo2[ia[i].target[e]].life -= ia[i].dgt;
        zo2[ia[i].target[e]].poison = (ia[i].dgt == 5) ? 1 :
        zo2[ia[i].target[e]].poison;
    }
}

void atkzo1(int i, int e, sfRenderWindow *window)
{
    float dx;
    float dy;

    sfSprite_setPosition(ia[i].sprite, ia[i].pos[e]);
    sfRenderWindow_drawSprite(window, ia[i].sprite, NULL);
    dx = ia[i].pos[e].x - zo1[ia[i].target[e] - 100].pos.x - 20;
    dy = ia[i].pos[e].y - zo1[ia[i].target[e] - 100].pos.y - 20;
    while (dx > 4 || dy > 4 || dx < -4 || dy < -4) {
        dx = dx / 2;
        dy = dy / 2;
    }
    ia[i].pos[e].x -= dx;
    ia[i].pos[e].y -= dy;
}

void atkzo1k(int i, int e)
{
    if (ia[i].pos[e].x > zo1[ia[i].target[e] - 100].pos.x && ia[i
    ].pos[e].x < zo1[ia[i].target[e] - 100].pos.x + 100 && ia[i].pos
    [e].y > zo1[ia[i].target[e] - 100].pos.y - 50 && ia[i].pos[e].y <
    zo1[ia[i].target[e] - 100].pos.y + 70) {
        ia[i].set[e] = 0;
        zo1[ia[i].target[e] - 100].life -= ia[i].dgt;
        zo1[ia[i].target[e] - 100].poison = (ia[i].dgt == 5) ?
        1 : zo1[ia[i].target[e] - 100].poison;
    }
}

void attack(sfRenderWindow *window)
{
    for (int i = 0; i < 12; i++)
        for (int e = 0; e < 50; e++) {
            if (ia[i].set[e] != 0 && ia[i].target[e] <
            100) {
                    atkzo2(i, e, window);
                    atkzo2k(i, e);
            }
            if (ia[i].set[e] != 0 && ia[i].target[e] >
            99 && ia[i].target[e] < 300) {
                atkzo1(i, e, window);
                atkzo1k(i, e);
            }
            if (ia[i].set[e] != 0 && ia[i].target[e] > 299 ) {
                atkzo3(i, e, window);
                atkzo3k(i, e);
            }
        }
}