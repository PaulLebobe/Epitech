/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** game_over
*/

#include "my.h"

void game_over2(sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, over.sprite, NULL);
    for (int i = 2; i < 4; i++) {
        sfText_setFillColor(us.piece[i], (sfColor) {200, 25, 25, 255});
        sfRenderWindow_drawText(window, us.piece[i], NULL);
    }
    if (over.scale < 3 && over.temp == 0) {
        over.scale += 0.1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue &&
    sfClock_getElapsedTime(over.cl).microseconds > 500000) {
        over.bouton = (over.bouton == 0) ? 1 : 0;
        sfClock_restart(over.cl);
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue &&
    sfClock_getElapsedTime(over.cl).microseconds > 500000) {
        over.bouton = (over.bouton == 0) ? 1 : 0;
        sfClock_restart(over.cl);
    }
}

void game_over3(sfRenderWindow *window)
{
    if (over.bouton == 0 && over.size[1].x < 1) {
        over.size[1].x += 0.1;
        over.size[1].y += 0.1;
        over.pos[1] -= 1;
    }
    if (over.bouton == 1 && over.size[2].x < 1) {
        over.size[2].x += 0.1;
        over.size[2].y += 0.1;
        over.pos[2] -= 1;
    }
    if (over.bouton == 1 && over.size[1].x > 0) {
        over.size[1].x -= 0.1;
        over.size[1].y -= 0.1;
        over.pos[1] += 1;
    }
    if (over.bouton == 0 && over.size[2].x > 0) {
        over.size[2].x -= 0.1;
        over.size[2].y -= 0.1;
        over.pos[2] += 1;
    }
}

void game_over(sfRenderWindow *window)
{
    game_over2(window);
    game_over3(window);
    if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue && over.bouton == 0 &&
    sfClock_getElapsedTime(over.cl).microseconds > 500000) {
        init();
        us.score = 0;
        io.status = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue && over.bouton == 1 &&
    sfClock_getElapsedTime(over.cl).microseconds > 500000) {
        sfRenderWindow_close(window);
    }
    for (int i = 0; i < 3; i++) {
        sfText_setPosition(over.text[i], (sfVector2f) {over.loc[i].x + over.
        pos[i], over.loc[i].y + over.pos[i]});
        sfText_setScale(over.text[i], (sfVector2f) {over.size[i].x +over.scale,
        over.size[i].y + over.scale});
        sfRenderWindow_drawText(window, over.text[i], NULL);
    }
}