/*
** EPITECH PROJECT, 2020
** navy
** File description:
** game
*/

#include "my.h"

int atk(char *buff)
{
    mess *p = &io;

    p->cd = 0;
    p->cd2 = 0;
    for (char cd = '@'; cd < buff[0]; cd++) {
        usleep(100);
        kill(p->pid, SIGUSR1);
        usleep(100);
    }
    kill(p->pid, SIGUSR2);
    for (char cd = '0'; cd < buff[1]; cd++) {
        usleep(100);
        kill(p->pid, SIGUSR1);
        usleep(100);
    }
    kill(p->pid, SIGUSR2);
}

char **game2(char **map2, char *buff2)
{
    mess *p = &io;

    while (p->status == 0) {
        signal(SIGUSR2, &hdl4);
        signal(SIGUSR1, &hdl3);
    }
    if (p->status == 3) {
        my_putstr("hit\n");
        map2[(buff2[1] - 47)][(buff2[0] - 64) * 2] = 'x';
    }
    if (p->status == 4) {
        my_putstr("missed\n");
        map2[(buff2[1] - 47)][(buff2[0] - 64) * 2] = 'o';
    }
    return (map2);
}

char **game(char **map, char **map2)
{
    char *buff2 = malloc(sizeof(char) * 3);
    int hit = 0;
    mess *p = &io;

    if (p->pass == 0) {
        my_putstr("\nmy positions:\n");
        my_putarray(map);
        my_putstr("\nenemy's positions:\n");
        my_putarray(map2);
    }
    p->pass = (p->pass == 0) ? 1 : 0;
    my_putstr("\nattack: ");
    hit = atk(buff2 = my_input(buff2, map2));
    my_putchar(buff2[0]);
    my_putchar(buff2[1]);
    my_putstr(": ");
    map2 = game2(map2, buff2);
    return (map2);
}

char **touch(char **map)
{
    mess *p = &io;

    my_putchar('@' + p->cd);
    my_putchar('0' + p->cd2);
    usleep(100);
    if (map[p->cd2 + 1][p->cd * 2] != '.' && map[p->cd2 + 1][p->cd * 2]
    != 'o') {
        map[p->cd2 + 1][p->cd * 2] = 'x';
        my_putstr(": hit\n");
        kill(p->pid, SIGUSR1);
    }   else {
        map[p->cd2 + 1][p->cd * 2] = 'o';
        my_putstr(": missed\n");
        kill(p->pid, SIGUSR2);
    }
    return (map);
}