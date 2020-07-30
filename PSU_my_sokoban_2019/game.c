/*
** EPITECH PROJECT, 2019
** My_Sokoban
** File description:
** Sokoban
*/

#include "my.h"

void block(char **str, int tot)
{
    int nb = 0;

    for (int i = 0; str[i] != NULL; i++) {
        for (int e = 0; str[i][e] != '\n'; e++)
            if (str[i][e] == 'X' && ((str[i - 1][e] == '#' && (str[i][e - 1]
            == '#' || str[i][e + 1] == '#')) || (str[i + 1][e] == '#' &&
            (str[i][e - 1] == '#' || str[i][e + 1] == '#')))) {
                nb++;
            }
    }
    if (nb == tot) {
        endwin();
        exit (1);
    }
}

void game(char **str, int *cd, int tot, char *buff)
{
    int ex = 0;

    cd[3] = 0;
    move (cd[1], cd[0]);
    while (1) {
        raw();
        keypad(stdscr, true);
        noecho();
        cd[2] = getch();
        cd[0] = getcurx(stdscr);
        cd[1] = getcury(stdscr);
        my_switch(str, buff, tot, cd);
        refresh();
        block(str, tot);
        if (cd[3] == tot) {
            endwin();
            exit(0);
        }
    }
}