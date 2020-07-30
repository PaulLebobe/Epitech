/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init2
*/

#include "my.h"

void initz1(void)
{
    zo1[0].text[0] = sfTexture_createFromFile("zombies/1z1.png", NULL);
    zo1[0].text[1] = sfTexture_createFromFile("zombies/1z2.png", NULL);
    zo1[0].text[2] = sfTexture_createFromFile("zombies/1z3.png", NULL);
    zo1[0].text[3] = sfTexture_createFromFile("zombies/1z4.png", NULL);
    zo1[0].text[4] = sfTexture_createFromFile("zombies/1z5.png", NULL);
    zo1[0].text[5] = sfTexture_createFromFile("zombies/1z6.png", NULL);
    zo1[0].text[6] = sfTexture_createFromFile("zombies/1z7.png", NULL);
    zo1[0].text[7] = sfTexture_createFromFile("zombies/1z8.png", NULL);
    zo1[0].text[8] = sfTexture_createFromFile("zombies/1z9.png", NULL);
    zo1[0].text[9] = sfTexture_createFromFile("zombies/1z10.png", NULL);
    zo1[0].text[10] = sfTexture_createFromFile("zombies/1z11.png", NULL);
    zo1[0].text[11] = sfTexture_createFromFile("zombies/1z12.png", NULL);
    zo1[0].text[12] = sfTexture_createFromFile("zombies/1z13.png", NULL);
    zo1[0].text[13] = sfTexture_createFromFile("zombies/1z14.png", NULL);
    zo1[0].text[14] = sfTexture_createFromFile("zombies/1z15.png", NULL);
    zo1[0].text[15] = sfTexture_createFromFile("zombies/1z16.png", NULL);
    initz2();
}

void initz2(void)
{
    for (int i = 0; i < 200; i++) {
        zo1[i].speed = 1;
        zo1[i].life = 50;
        zo1[i].dead = 0;
        zo1[i].z1 = sfSprite_create();
        zo1[i].cl = sfClock_create();
        if (i < 30)
            zo1[i].pos.x = 2000 + i * 100;
        if (i > 29 && i < 70)
            zo1[i].pos.x = 2000 + i * 150;
        if (i > 69)
            zo1[i].pos.x = 2000 + i * 100;
        initz2b(i);
    }
    initz3();
}

void initz2b(int i)
{
    if (i < 30) {
        zo1[i].pos.y = 260;
        zo1[i].path = 0;
    }
    if (i > 29 && i < 70 && i % 2 != 0)
        zo1[i].pos.y = 260;
    if (i > 29 && i < 70 && i % 2 == 0) {
        zo1[i].pos.y = 710;
        zo1[i].path = 1;
    }
    if (i > 69) {
        zo1[i].pos.y = 260;
        zo1[i].path = 0;
    }
}

void initz3b(void)
{
    for (int i = 0; i < 50; i++) {
        zo2[i].dead = 0;
        zo2[i].speed = 0.6;
        zo2[i].life = 250;
        zo2[i].z2 = sfSprite_create();
        zo2[i].cl = sfClock_create();
        if (i < 25)
            zo2[i].pos.x = 3000 + i * 300;
        else
            zo2[i].pos.x = 3000 + i * 150;
        if (i % 2 != 0)
            zo2[i].pos.y = 260;
        if (i % 2 == 0) {
            zo2[i].pos.y = 710;
            zo2[i].path = 1;
        }
    }
}

void initz3(void)
{
    zo2[0].text[0] = sfTexture_createFromFile("zombies/4z1.png", NULL);
    zo2[0].text[1] = sfTexture_createFromFile("zombies/4z2.png", NULL);
    zo2[0].text[2] = sfTexture_createFromFile("zombies/4z3.png", NULL);
    zo2[0].text[3] = sfTexture_createFromFile("zombies/4z4.png", NULL);
    zo2[0].text[4] = sfTexture_createFromFile("zombies/4z5.png", NULL);
    zo2[0].text[5] = sfTexture_createFromFile("zombies/4z6.png", NULL);
    zo2[0].text[6] = sfTexture_createFromFile("zombies/4z7.png", NULL);
    zo2[0].text[7] = sfTexture_createFromFile("zombies/4z8.png", NULL);
    initz3b();
    init_atk();
}