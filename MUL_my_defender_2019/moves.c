/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** move1
*/

#include "my.h"

void mv(void)
{
    for (int i = 0; i < 200; i++) {
        if (zo1[i].path == 0)
            zo1[i].pos = mv1(zo1[i].pos, zo1[i].speed);
        if (zo1[i].path == 1    )
            zo1[i].pos = mv2(zo1[i].pos, zo1[i].speed);
    }
    for (int i = 0; i < 50; i++) {
        if (zo2[i].path == 0)
            zo2[i].pos = mv1(zo2[i].pos, zo2[i].speed);
        if (zo2[i].path == 1)
            zo2[i].pos = mv2(zo2[i].pos, zo2[i].speed);
    }
    for (int i = 0; i < 20; i++) {
        if (zo3[i].path == 0)
            zo3[i].pos = mv1(zo3[i].pos, zo3[i].speed);
        if (zo3[i].path == 1)
            zo3[i].pos = mv2(zo3[i].pos, zo3[i].speed);
    }
}

sfVector2f mv1_2(sfVector2f pos, float speed)
{
    if (pos.x < 630 && pos.x > 475
    && pos.y > 240)
        pos.x -= speed;
    if (pos.x < 500 && pos.x > 460
    && pos.y < 460)
        pos.y += speed;
    if (pos.x > -10000 && pos.x < 480
    && pos.y > 450)
        pos.x -= speed;
    return (pos);
}

sfVector2f mv1(sfVector2f pos, float speed)
{
    if (pos.x > 1300)
        pos.x -= speed;
    if (pos.x > 1250 && pos.x < 1350
    && pos.y > 225 && pos.y < 380)
        pos.y += speed;
    if (pos.x > 1100 && pos.x < 1350
    && pos.y > 360)
        pos.x -= speed;
    if (pos.x < 1120 && pos.x > 1000
    && pos.y > 150)
        pos.y -= speed;
    if (pos.x < 1120 && pos.x > 620
    && pos.y < 170)
        pos.x -= speed;
    if (pos.x < 630 && pos.x > 600
    && pos.y < 250)
        pos.y += speed;
    pos = mv1_2(pos, speed);
    return (pos);
}

sfVector2f mv2(sfVector2f pos, float speed)
{
    if (pos.x > 1750)
        pos.x -= speed;
    if (pos.x > 1710 && pos.x < 1770
    && pos.y > 700 && pos.y < 800)
        pos.y += speed;
    if (pos.x > 1280 && pos.x < 1760
    && pos.y > 780 && pos.y < 850)
        pos.x -= speed;
    if (pos.x > 1250 && pos.x < 1300
    && pos.y > 780 && pos.y < 940)
        pos.y += speed;
    if (pos.x > 1100 && pos.x < 1300
    && pos.y > 900 && pos.y < 960)
        pos.x -= speed;
    if (pos.x > 920 && pos.x < 1130
    && pos.y > 640 && pos.y < 1040)
        pos.y -= speed;
    pos = mv2_2(pos, speed);
    return (pos);
}

sfVector2f mv2_2 (sfVector2f pos, float speed)
{
    if (pos.x > 680 && pos.x < 1105
    && pos.y > 620 && pos.y < 1100)
        pos.x -= speed;
    if (pos.x > 650 && pos.x < 700
    && pos.y > 660 && pos.y < 800)
        pos.y += speed;
    if (pos.x > 250 && pos.x < 700
    && pos.y > 780 && pos.y < 820)
        pos.x -= speed;
    if (pos.x > 230 && pos.x < 270
    && pos.y > 470 && pos.y < 820)
        pos.y -= speed;
    if (pos.x > -10000 && pos.x < 270
    && pos.y > 400 && pos.y < 490)
        pos.x -= speed;
    return (pos);
}