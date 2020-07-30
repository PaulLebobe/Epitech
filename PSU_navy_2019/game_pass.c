/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** game2
*/

#include "my.h"

void game_pass2(void)
{
    mess *p = &io;

    while (p->status == 0) {
        signal(SIGUSR1, &hdl);
        signal(SIGUSR2, &hdstop);
    }
    while (p->status == 1) {
        signal(SIGUSR1, &hdl2);
        signal(SIGUSR2, &hdstop);
    }
}

char **game_pass(char **map, char **map2)
{
    char *buff2 = malloc(sizeof(char) * 3);
    int hit = 0;
    mess *p = &io;

    p->cd = 0;
    p->cd2 = 0;
    if (p->pass == 0) {
        my_putstr("\nmy positions:\n");
        my_putarray(map);
        my_putstr("\nenemy's positions:\n");
        my_putarray(map2);
    }
    p->pass = (p->pass == 0) ? 1 : 0;
    my_putstr("\nwaiting for enemy's attack...\n");
    game_pass2();
    return (map = touch(map));
}