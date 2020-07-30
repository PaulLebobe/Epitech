/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_over
*/

#include "my.h"

void init_over2(void)
{
    sfText_setFont(over.text[0], htp.font);
    over.loc[0] = (sfVector2f) {400, 200};
    over.loc[1] = (sfVector2f) {700, 450};
    over.loc[2] = (sfVector2f) {700, 650};
    over.texture = sfTexture_createFromFile("desolation.jpg", NULL);
    over.sprite = sfSprite_create();
    sfSprite_setTexture(over.sprite, over.texture, sfTrue);
    sfText_setString(over.text[0], "Damn you're so bad...");
    sfText_setString(over.text[1], "Try again");
    sfText_setString(over.text[2], "Abandon");
}

void init_over(void)
{
    over.font = sfFont_createFromFile("horrendo.ttf");
    over.temp = 0;
    for (int i = 0; i < 3; i++) {
        over.text[i] = sfText_create();
        sfText_setFont(over.text[i], over.font);
        sfText_setFillColor(over.text[i], (sfColor) {200, 25, 25, 255});
        over.size[i] = (sfVector2f) {0, 0};
    }
    over.cl = sfClock_create();
    over.size[0] = (sfVector2f) {1, 1};
    init_over2();
}