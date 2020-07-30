/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** zomb3
*/

#include "my.h"

void atkzo3(int i, int e, sfRenderWindow *window)
{
    float dx;
    float dy;

    sfSprite_setPosition(ia[i].sprite, ia[i].pos[e]);
    sfRenderWindow_drawSprite(window, ia[i].sprite, NULL);
    dx = ia[i].pos[e].x - zo3[ia[i].target[e] - 300].pos.x - 20;
    dy = ia[i].pos[e].y - zo3[ia[i].target[e] - 300].pos.y - 20;
    while (dx > 4 || dy > 4 || dx < -4 || dy < -4) {
        dx = dx / 2;
        dy = dy / 2;
    }
    ia[i].pos[e].x -= dx;
    ia[i].pos[e].y -= dy;
}

void atkzo3k(int i, int e)
{
    if (ia[i].pos[e].x > zo3[ia[i].target[e] - 300].pos.x && ia[i
    ].pos[e].x < zo3[ia[i].target[e] - 300].pos.x + 300 && ia[i].pos
    [e].y > zo3[ia[i].target[e] - 300].pos.y - 50 && ia[i].pos[e].y <
    zo3[ia[i].target[e] - 300].pos.y + 70) {
        ia[i].set[e] = 0;
        zo3[ia[i].target[e] - 300].life -= ia[i].dgt;
        zo3[ia[i].target[e] - 300].poison = (ia[i].dgt == 5) ?
        1 : zo3[ia[i].target[e] - 300].poison;
    }
}

void en3(sfRenderWindow *window)
{
    for (int i = 0; i < 20; i++) {
        if (sfClock_getElapsedTime(zo3[i].cl).microseconds > 200000) {
            zo3[i].temp = (zo3[i].temp < 11) ? zo3[i].temp + 1 : 0;
            if (zo3[i].poison == 1)
                zo3[i].life -= 3;
            sfClock_restart(zo3[i].cl);
        }
        sfSprite_setPosition(zo3[i].z3, (sfVector2f) {zo3[i].pos.x - 20
        , zo3[i].pos.y - 100});
        sfSprite_setTexture(zo3[i].z3, zo3[0].text[zo3[i].temp], sfTrue);
        sfRenderWindow_drawSprite(window, zo3[i].z3, NULL);
    }
}

void cr_atkz3(int i)
{
    int w;

    for (int x = 0; x < 20; x++)
        if (tw[i].pos.x < zo3[x].pos.x + tw[i].range && tw[i].pos.x > zo3[x].
        pos.x - tw[i].range && tw[i].pos.y < zo3[x].pos.y + tw[i].range && tw
        [i].pos.y > zo3[x].pos.y - tw[i].range && tw[i].set != -1  && tw[i].set
        != 3 && sfClock_getElapsedTime(ia[i].cl).microseconds > tw[i].speed) {
            w = 0;
            for (; ia[i].set[w] == 1; w++);
            ia[i].set[w] = 1;
            ia[i].target[w] = x + 300;
            ia[i].pos[w] = tw[i].pos;
            ia[i].pos[w].x += 20;
            sfClock_restart(ia[i].cl);
        }
}