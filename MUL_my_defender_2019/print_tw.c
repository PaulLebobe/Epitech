/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** print_towe
*/

#include "my.h"

void print_tower(sfRenderWindow *window)
{
    for (int i = 0; i < 12; i++) {
        if (tw[i].set > -1) {
            sfSprite_setTexture(tw[i].sprite, tw[0].text[tw[i].set],
            sfTrue);
            sfRenderWindow_drawSprite(window, tw[i].sprite, NULL);
        }
    }
}