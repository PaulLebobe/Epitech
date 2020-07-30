/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** zomb3_init
*/

#include "my.h"

void init_zomb3b(void)
{
    for (int i = 0; i < 20; i++) {
        zo3[i].dead = 0;
        zo3[i].speed = 0.5;
        zo3[i].life = 1200;
        zo3[i].z3 = sfSprite_create();
        sfSprite_setScale(zo3[i].z3, (sfVector2f) {0.6, 0.6});
        zo3[i].cl = sfClock_create();
        if (i < 11)
            zo3[i].pos.x = 5000 + i * 1500;
        else
            zo3[i].pos.x = 5000 + i * 300;
        if (i < 20 && i % 2 != 0)
            zo3[i].pos.y = 260;
        if (i < 20 && i % 2 == 0) {
            zo3[i].pos.y = 710;
            zo3[i].path = 1;
        }
    }
    zo3[19].life = 999999;
}

void init_zomb3(void)
{
    zo3[0].text[0] = sfTexture_createFromFile("zombies/z31.png", NULL);
    zo3[0].text[1] = sfTexture_createFromFile("zombies/z32.png", NULL);
    zo3[0].text[2] = sfTexture_createFromFile("zombies/z33.png", NULL);
    zo3[0].text[3] = sfTexture_createFromFile("zombies/z34.png", NULL);
    zo3[0].text[4] = sfTexture_createFromFile("zombies/z35.png", NULL);
    zo3[0].text[5] = sfTexture_createFromFile("zombies/z36.png", NULL);
    zo3[0].text[6] = sfTexture_createFromFile("zombies/z37.png", NULL);
    zo3[0].text[7] = sfTexture_createFromFile("zombies/z38.png", NULL);
    zo3[0].text[8] = sfTexture_createFromFile("zombies/z39.png", NULL);
    zo3[0].text[9] = sfTexture_createFromFile("zombies/z310.png", NULL);
    zo3[0].text[10] = sfTexture_createFromFile("zombies/z311.png", NULL);
    zo3[0].text[11] = sfTexture_createFromFile("zombies/z312.png", NULL);
    init_zomb3b();
}