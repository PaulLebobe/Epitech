/*
** EPITECH PROJECT, 2020
** defender
** File description:
** main
*/

#include "my.h"

void game_pause2(sfVector2i pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && pos.y > 370 &&
    pos.y < 470 && pos.x > 760 && pos.x < 1225) {
        init();
        io.status = 1;
    }
}

void game_pause(sfRenderWindow *window)
{
    start *p = &io;
    sfVector2i pos = sfMouse_getPosition(window);

    sfSprite_setPosition(p->sprite_p, (sfVector2f) {0, 0});
    sfRenderWindow_drawSprite(window, p->sprite_p, NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && pos.y >
    790 && pos.y < 975 && pos.x > 775 && pos.x < 1220)
        sfRenderWindow_close(window);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && pos.y > 525 &&
    pos.y < 625 && pos.x > 760 && pos.x < 1225)
        p->status = 1;
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && pos.y > 690 &&
    pos.y < 780 && pos.x > 760 && pos.x < 1225) {
        p->status = 0;
        init();
    }
    game_pause2(pos);
}

void begin(sfRenderWindow *window)
{
    if (us.life <= 0 && io.status != 3) {
        io.status = 3;
    }
    if (io.status == 0)
        menu(window);
    if (io.status == 1 || io.status == 2)
        game(window);
    if (io.status == 3)
        game_over(window);
    if (io.status == 4)
        how_to(window);
}

void sc_window(sfRenderWindow *window, sfClock *clock)
{
    sfEvent event;

    io.down = sfClock_create();
    io.cl = sfClock_create();
    init_menu();
    init();
    while (sfRenderWindow_isOpen(window)) {
        sfClock_restart(clock);
        sfRenderWindow_setFramerateLimit(window, 60);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue && io.status == 1)
            io.status = 2;
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        begin(window);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
    sfRenderWindow_destroy(window);
}

void main(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfClock *clock = sfClock_create();

    video_mode.width = 1920;
    video_mode.height = 1080;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "MyWindow",
    sfDefaultStyle, NULL);
    init_sound();
    sc_window(window, clock);
}