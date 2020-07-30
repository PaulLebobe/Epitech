/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** life_check
*/

#include "my.h"

void life_check2(void)
{
    for (int i = 0; i < 200; i++) {
        if (zo1[i].life <= 0 && zo1[i].dead == 0) {
            zo1[i].dead = 1;
            us.score += 2;
            us.money += 2;
            zo1[i].path = -1;
            zo1[i].pos =
            (sfVector2f) {9999, 9999};
            att_check();
        }
        if (zo1[i].pos.x < -20 && zo1[i].hit == 0) {
        us.life -= 1;
        zo1[i].hit = 1;
        sfSound_play(over.sound[1]);
        }
    }
}

void life_check3(void)
{
    for (int i = 0; i < 20; i++) {
        if (zo3[i].life <= 0 && zo3[i].dead == 0) {
            zo3[i].dead = 1;
            us.score += 20;
            us.money += 8;
            zo3[i].path = -1;
            zo3[i].pos =
            (sfVector2f) {9999, 9999};
            att_check();
        }
        if (zo3[i].pos.x < -20 && zo3[i].hit == 0) {
            us.life -= 5;
            zo3[i].hit = 1;
            sfSound_play(over.sound[1]);
        }
    }
}

void life_check(void)
{
    for (int i = 0; i < 50; i++) {
        if (zo2[i].life <= 0 && zo2[i].dead == 0) {
            zo2[i].dead = 1;
            us.score += 5;
            us.money += 4;
            zo2[i].path = -1;
            zo2[i].pos =
            (sfVector2f) {9999, 9999};
            att_check();
        }
        if (zo2[i].pos.x < -20 && zo2[i].hit == 0) {
            us.life -= 2;
            zo2[i].hit = 1;
            sfSound_play(over.sound[1]);
        }
    }
    life_check2();
    life_check3();
}