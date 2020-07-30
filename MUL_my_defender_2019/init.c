/*
** EPITECH PROJECT, 2020
** Defender
** File description:
** init
*/

#include "my.h"

void init(void)
{
    io.texture = sfTexture_createFromFile("map.jpg", NULL);
    io.texture_p = sfTexture_createFromFile("pause.png", NULL);
    io.sprite = sfSprite_create();
    io.sprite_p = sfSprite_create();
    init_tw();
    initz1();
    init_zomb3();
    us.score = 0;
}

void init_tw(void)
{
    tw[0].text[0] = sfTexture_createFromFile("archer.png", NULL);
    tw[0].text[1] = sfTexture_createFromFile("arcane.png", NULL);
    tw[0].text[3] = sfTexture_createFromFile("elec.png", NULL);
    tw[0].text[2] = sfTexture_createFromFile("poison.png", NULL);
    tw[0].pos = (sfVector2f) {120, 590};
    tw[1].pos = (sfVector2f) {320, 375};
    tw[2].pos = (sfVector2f) {530, 560};
    tw[3].pos = (sfVector2f) {530, 710};
    tw[4].pos = (sfVector2f) {570, 360};
    tw[5].pos = (sfVector2f) {845, 585};
    tw[6].pos = (sfVector2f) {975, 250};
    tw[7].pos = (sfVector2f) {1200, 265};
    tw[8].pos = (sfVector2f) {1210, 475};
    tw[9].pos = (sfVector2f) {1200, 715};
    tw[10].pos = (sfVector2f) {1415, 370};
    tw[11].pos = (sfVector2f) {1540, 725};
    init_tw2();
}

void init_tw2(void)
{
    for (int i = 0; i < 12; i++) {
        tw[i].sprite = sfSprite_create();
        sfSprite_setPosition(tw[i].sprite, (sfVector2f) {tw[i].pos.x - 7,
        tw[i].pos.y - 120});
        tw[i].set = -1;
        tw[i].cl = sfClock_create();
        tw[i].shoptext = sfTexture_createFromFile("shop.png", NULL);
        tw[i].shop = sfSprite_create();
        sfSprite_setTexture(tw[i].shop, tw[i].shoptext, sfTrue);
    }
    init_user();
}

void init_user(void)
{
    us.font = sfFont_createFromFile("horrendo.ttf");
    us.money = 300;
    us.life = 5;
    us.text = sfTexture_createFromFile("heart.png", NULL);
    for (int i = 0; i < 4; i++) {
        us.piece[i] = sfText_create();
        sfText_setFont(us.piece[i], us.font);
        sfText_setScale(us.piece[i], (sfVector2f) {2, 2});
        sfText_setFillColor(us.piece[i], sfWhite);
    }
    sfText_setString(us.piece[1], "$");
    sfText_setString(us.piece[2], "Score :");
    sfSprite_setPosition(us.piece[0], (sfVector2f) {50, 20});
    sfSprite_setPosition(us.piece[2], (sfVector2f) {750, 20});
    sfSprite_setPosition(us.piece[3], (sfVector2f) {970, 20});
    init_user2();
}

void init_user2(void)
{
    for (int i = 0; i < 5; i++) {
    us.heart[i] = sfSprite_create();
    sfSprite_setTexture(us.heart[i], us.text, sfTrue);
    }
    sfSprite_setPosition(us.heart[4], (sfVector2f) {1470, 0});
    sfSprite_setPosition(us.heart[3], (sfVector2f) {1560, 0});
    sfSprite_setPosition(us.heart[2], (sfVector2f) {1650, 0});
    sfSprite_setPosition(us.heart[1], (sfVector2f) {1740, 0});
    sfSprite_setPosition(us.heart[0], (sfVector2f) {1830, 0});
}