/*
** EPITECH PROJECT, 2020
** defender
** File description:
** main
*/

#include "my.h"

void menu2(sfRenderWindow *window)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue &&
    sfClock_getElapsedTime(io.down).microseconds > 500000) {
        io.text = io.text < 2 ? io.text + 1 : 0;
        sfClock_restart(io.down);
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue &&
    sfClock_getElapsedTime(io.down).microseconds > 500000) {
        io.text = io.text > 0 ? io.text - 1 : 2;
        sfClock_restart(io.down);
    }
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && io.text == 2)
        sfRenderWindow_close(window);
    if (io.text == 0 && sfKeyboard_isKeyPressed(sfKeyReturn)) {

        io.status = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && io.text == 1)
        io.status = 4;
}

void init_menu(void)
{
    for (int i = 0; i < 3; i++) {
        men[i].text = sfText_create();
        men[i].font = sfFont_createFromFile("horrendo.ttf");
        sfText_setFillColor(men[i].text, (sfColor) {255, 255, 255, 255});
        men[i].scale = 3;
        sfText_setFont(men[i].text, men[i].font);
    }
    men[0].texture = sfTexture_createFromFile("welcome.png", NULL);
    men[0].sprite = sfSprite_create();
    sfSprite_setTexture(men[0].sprite, men[0].texture, sfTrue);
    sfSprite_setPosition(men[0].sprite, (sfVector2f) {-1, -1});
    sfText_setString(men[0].text, "Play");
    sfText_setString(men[1].text, "How to play");
    sfText_setString(men[2].text, "Quit");
}

void menu3(sfRenderWindow *window, int i)
{
    if (io.text == i && men[i].scale < 4 && men[i].size == 0) {
        men[i].scale += 0.1;
        men[i].pos -= 2;
    }
    if (men[i].scale >= 4)
        men[i].size = 1;
    if (men[i].size == 1 && men[i].scale > 3.5) {
        men[i].scale -= 0.1;
        men[i].pos += 2;
    }
    if (io.text != i && men[i].scale > 2) {
        men[i].scale -= 0.1;
        men[i].size = 0;
        men[i].pos += 2;
    }
}

void menu(sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, men[0].sprite, NULL);
    menu2(window);
    for (int i = 0; i < 3; i++) {
        menu3(window, i);
        sfText_setPosition(men[i].text, (sfVector2f)
        {80, 50 + 150 * i + men[i].pos});
        sfText_setScale(men[i].text, (sfVector2f) {men[i].scale, men[i].scale});
        sfRenderWindow_drawText(window, men[i].text, NULL);
    }
}