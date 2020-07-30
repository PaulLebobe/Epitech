/*
** EPITECH PROJECT, 2020
** Defender
** File description:
** game
*/

#include "my.h"

void en1(sfRenderWindow *window)
{
    en2(window);
    for (int i = 0; i < 200; i++) {
        if (sfClock_getElapsedTime(zo1[i].cl).microseconds > 100000) {
            zo1[i].temp = (zo1[i].temp < 15) ? zo1[i].temp + 1 : 0;
            if (zo1[i].poison == 1)
                zo1[i].life -= 2;
            sfClock_restart(zo1[i].cl);
        }
        sfSprite_setPosition(zo1[i].z1, zo1[i].pos);
        sfSprite_setTexture(zo1[i].z1, zo1[0].text[zo1[i].temp], sfTrue);
        sfRenderWindow_drawSprite(window, zo1[i].z1, NULL);
    }
}

void en2(sfRenderWindow *window)
{
    for (int i = 0; i < 50; i++) {
        if (sfClock_getElapsedTime(zo2[i].cl).microseconds > 200000) {
            zo2[i].temp = (zo2[i].temp < 7) ? zo2[i].temp + 1 : 1;
            if (zo2[i].poison == 1)
                zo2[i].life -= 3;
            sfClock_restart(zo2[i].cl);
        }
        sfSprite_setPosition(zo2[i].z2, (sfVector2f)
        {zo2[i].pos.x - 10, zo2[i].pos.y - 50});
        sfSprite_setTexture(zo2[i].z2, zo2[0].text[zo2[i].temp], sfTrue);
        sfRenderWindow_drawSprite(window, zo2[i].z2, NULL);
    }
}

void user_p(sfRenderWindow *window)
{
    for (int i = 0; i < us.life; i++)
        sfRenderWindow_drawSprite(window, us.heart[i], NULL);
    sfText_setString(us.piece[0], into_str(us.money));
    sfText_setString(us.piece[3], into_str(us.score));
    if (us.money > 99)
        sfSprite_setPosition(us.piece[1], (sfVector2f) {200, 20});
    if (us.money < 100)
        sfSprite_setPosition(us.piece[1], (sfVector2f) {150, 20});
    if (us.money < 10)
        sfSprite_setPosition(us.piece[1], (sfVector2f) {100, 20});
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawText(window, us.piece[i], NULL);
}

void game(sfRenderWindow *window)
{
    sfSprite *tower;
    start *p = &io;
    sfVector2i pos;

    sfSprite_setTexture(p->sprite, p->texture, sfTrue);
    sfSprite_setTexture(p->sprite_p, p->texture_p, sfTrue);
    sfRenderWindow_drawSprite(window, p->sprite, NULL);
    user_p(window);
    if (p->status == 1) {
        life_check();
        cr_atk(window);
        mv();
        en1(window);
        print_tower(window);
        en3(window);
        b_tower(window);
        attack(window);
    } else {
        game_pause(window);
        print_tower(window);
    }
}