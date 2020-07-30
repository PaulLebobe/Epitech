/*
** EPITECH PROJECT, 2020
** Defender
** File description:
** tower
*/

#include "my.h"

void b_tower3(sfRenderWindow *window, sfVector2i pos, int i)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && pos.x > tw[i]
    .pos.x - 25 && pos.x < tw[i].pos.x + 40 && pos.y > tw[i].pos.y +
    50 && pos.y < tw[i].pos.y + 200 && us.money > 99) {
        tw[i].set = 1;
        us.money -= 100;
        tw[i].range = 500;
        tw[i].speed = 3000000;
        ia[i].dgt = 60;
        sfSprite_setTexture(ia[i].sprite, ia[0].text[1], sfTrue);
    }
    tw[i].on = (pos.x > tw[i].pos.x - 110 && pos.x < tw[i].pos.x + 200 && pos.y
    > tw[i].pos.y + 40 && pos.y < tw[i].pos.y
    + 200 && tw[i].set == -1) ? 1 : 0;
}

void b_tower25(sfVector2i pos, int i)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && pos.x > tw[i]
    .pos.x + 50 && pos.x < tw[i].pos.x + 115 && pos.y > tw[i].pos.y +
    50 && pos.y < tw[i].pos.y + 200 && us.money > 119) {
        tw[i].set = 2;
        us.money -= 120;
        tw[i].speed = 1000000;
        tw[i].range = 300;
        ia[i].dgt = 5;
        sfSprite_setTexture(ia[i].sprite, ia[0].text[2], sfTrue);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && pos.x > tw[i]
    .pos.x + 125 && pos.x < tw[i].pos.x + 200 && pos.y > tw[i].pos.y +
    50 && pos.y < tw[i].pos.y + 200 && us.money > 139) {
        tw[i].set = 3;
        us.money -= 140;
        tw[i].speed = 200000;
        tw[i].range = 300;
        ia[i].dgt = 15;
        sfSprite_setTexture(ia[i].sprite, ia[0].text[3], sfTrue);
    }
}

void b_tower2(sfRenderWindow *window, sfVector2i pos, int i)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && pos.x > tw[i]
    .pos.x - 110 && pos.x < tw[i].pos.x - 35 && pos.y > tw[i].pos.y +
    50 && pos.y < tw[i].pos.y + 200 && us.money > 79) {
        tw[i].set = 0;
        tw[i].range = 300;
        us.money -= 80;
        tw[i].speed = 500000;
        ia[i].dgt = 10;
        sfSprite_setTexture(ia[i].sprite, ia[0].text[0], sfTrue);
    }
    b_tower25(pos, i);
    b_tower3(window, pos, i);
}

void b_tower(sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPosition(window);
    for (int i = 0; i < 12; i++) {
        if (pos.x > tw[i].pos.x && pos.x < tw[i].pos.x + 90 && pos.y >
        tw[i].pos.y && pos.y < tw[i].pos.y + 60 && tw[i].set == -1)
            tw[i].on = 1;
        if (tw[i].on == 1) {
            sfSprite_setPosition(tw[i].shop, (sfVector2f) {tw[i].pos.x
            - 110, tw[i].pos.y + 30});
            sfRenderWindow_drawSprite(window, tw[i].shop, NULL);
            b_tower2(window, pos, i);
        }
    }
}