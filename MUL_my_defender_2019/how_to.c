/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** how_to
*/

#include "my.h"

void how_to(sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, men[0].sprite, NULL);
    if (htp.temp == 0 && htp.scale < 2.5)
        htp.scale += 0.1;
    if (htp.temp == 0 && htp.scale >= 2.5)
        htp.temp = 1;
    if (htp.temp == 0 && htp.scale > 1.5)
        htp.scale -= 0.1;
    sfText_setScale(htp.text[0], (sfVector2f) {htp.scale + 1, htp.scale + 1});
    sfRenderWindow_drawText(window, htp.text[0], NULL);
    for (int i = 1; i < 10; i++) {
    sfText_setScale(htp.text[i], (sfVector2f) {htp.scale, htp.scale});
    sfRenderWindow_drawText(window, htp.text[i], NULL);
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        io.status = 0;
        init();
    }
}