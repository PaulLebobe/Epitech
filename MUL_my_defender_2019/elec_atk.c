/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** elec_atk
*/

#include "my.h"

void cr_atk43(int i)
{
    if (sfClock_getElapsedTime(ia[i].cl).microseconds
    > tw[i].speed && tw[i].set == 3) {
        for (int x = 0; x < 200; x++)
            if (tw[i].pos.x < zo1[x].pos.x + tw[i].range && tw[i].pos.x >
            zo1[x].pos.x - tw[i].range && tw[i].pos.y < zo1[x].pos.y +
            tw[i].range && tw[i].pos.y > zo1[x].pos.y - tw[i].range)
            zo1[x].life -= 2;
        for (int x = 0; x < 50; x++)
            if (tw[i].pos.x < zo2[x].pos.x + tw[i].range && tw[i].pos.x >
            zo2[x].pos.x - tw[i].range && tw[i].pos.y < zo2[x].pos.y
            + tw[i].range && tw[i].pos.y > zo2[x].pos.y - tw[i].range)
            zo1[x].life -= 2;
        for (int x = 0; x < 20; x++)
            if (tw[i].pos.x < zo3[x].pos.x + tw[i].range && tw[i].pos.x >
            zo3[x].pos.x - tw[i].range && tw[i].pos.y < zo3[x].pos.y
            + tw[i].range && tw[i].pos.y > zo3[x].pos.y - tw[i].range)
            zo1[x].life -= 2;
        sfClock_restart(ia[i].cl);
    }
}

void cr_atk42(int i, sfRenderWindow *window)
{
    for (int x = 0; x < 50; x++)
        if (tw[i].pos.x < zo2[x].pos.x + tw[i].range && tw[i].pos.x > zo2[x].
        pos.x - tw[i].range && tw[i].pos.y < zo2[x].pos.y + tw[i].range && tw
        [i].pos.y > zo2[x].pos.y - tw[i].range && tw[i].set == 3 &&
        sfClock_getElapsedTime(ia[i].cl).microseconds < tw[i].speed) {
            ia[i].pos[0].x = tw[i].pos.x - 200;
            ia[i].pos[0].y = tw[i].pos.y - 200;
            sfSprite_setPosition(ia[i].sprite, ia[i].pos[0]);
            sfRenderWindow_drawSprite(window, ia[i].sprite, NULL);
        }
}

void cr_atk4z3(int i, sfRenderWindow *window)
{
    for (int x = 0; x < 20; x++)
        if (tw[i].pos.x < zo3[x].pos.x + tw[i].range && tw[i].pos.x > zo3[x].
            pos.x - tw[i].range && tw[i].pos.y < zo3[x].pos.y + tw[i].range &&
            tw[i].pos.y > zo3[x].pos.y - tw[i].range && tw[i].set == 3 &&
            sfClock_getElapsedTime(ia[i].cl).microseconds < tw[i].
            speed) {
                ia[i].pos[0].x = tw[i].pos.x - 200;
                ia[i].pos[0].y = tw[i].pos.y - 200;
                sfSprite_setPosition(ia[i].sprite, ia[i].pos[0]);
                sfRenderWindow_drawSprite(window, ia[i].sprite, NULL);
            }
}

void cr_atkt4(int i, sfRenderWindow *window)
{
    for (int x = 0; x < 200; x++)
        if (tw[i].pos.x < zo1[x].pos.x + tw[i].range && tw[i].pos.x > zo1[x].
            pos.x - tw[i].range && tw[i].pos.y < zo1[x].pos.y + tw[i].range &&
            tw[i].pos.y > zo1[x].pos.y - tw[i].range && tw[i].set == 3 &&
            sfClock_getElapsedTime(ia[i].cl).microseconds < tw[i].
            speed) {
                ia[i].pos[0].x = tw[i].pos.x - 200;
                ia[i].pos[0].y = tw[i].pos.y - 200;
                sfSprite_setPosition(ia[i].sprite, ia[i].pos[0]);
                sfRenderWindow_drawSprite(window, ia[i].sprite, NULL);
            }
    cr_atk42(i, window);
    cr_atk4z3(i, window);
    cr_atk43(i);

}