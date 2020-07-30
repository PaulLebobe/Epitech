/*
** EPITECH PROJECT, 2019
** My_Sokoban
** File description:
** Sokoban
*/

#include "my.h"

void my_switch5(char **str, char *buff, int tot, int *cd)
{
    switch (cd[2]) {
        case KEY_LEFT :
            if (str[cd[1]][cd[0] - 1] != '#' && str[cd[1]][cd[0] - 1] != 'X'){
                (str[cd[1]][cd[0]] == 'O') ? printw("O") : printw(" ");
                mvprintw(cd[1], cd[0] - 1, "P");
                move(cd[1], cd[0] - 1);
            }
            if (str[cd[1]][cd[0] - 1] == 'X' && str[cd[1]]
            [cd[0] - 2] != '#' && str[cd[1]][cd[0] - 2] != 'X') {
                cd[3] += (str[cd[1]][cd[0] - 2] == 'O') ? 1 : 0;
                printw(" ");
                mvprintw(cd[1], cd[0] - 1, "P");
                mvprintw(cd[1], cd[0] - 2, "X");
                str[cd[1]][cd[0] - 2] = 'X';
                str[cd[1]][cd[0] - 1] = ' ';
                move(cd[1], cd[0] - 1);
            }
            break;
    }
}

void my_switch4(char **str, char *buff, int tot, int *cd)
{
    switch (cd[2]) {
        case KEY_RIGHT :
            if (str[cd[1]][cd[0] + 1] != '#' && str[cd[1]][cd[0] + 1] != 'X') {
                (str[cd[1]][cd[0]] == 'O') ? printw("O") : printw(" ");
                mvprintw(cd[1], cd[0] + 1, "P");
                move(cd[1], cd[0] + 1);
            } else if (str[cd[1]][cd[0] + 1] == 'X' && str[cd[1]]
            [cd[0] + 2] != '#' && str[cd[1]][cd[0] + 2] != 'X') {
                cd[3] += (str[cd[1]][cd[0] + 2] == 'O') ? 1 : 0;
                printw(" ");
                mvprintw(cd[1], cd[0] + 1, "P");
                mvprintw(cd[1], cd[0] + 2, "X");
                str[cd[1]][cd[0] + 2] = 'X';
                str[cd[1]][cd[0] + 1] = ' ';
                move(cd[1], cd[0] + 1);
            }
            break;
        default:
            my_switch5(str, buff, tot, cd);
    }
}

void my_switch3(char **str, char *buff, int tot, int *cd)
{
    switch (cd[2]) {
        case KEY_DOWN :
            if (str[cd[1] + 1][cd[0]] != '#' && str[cd[1] + 1][cd[0]] != 'X') {
                (str[cd[1]][cd[0]] == 'O') ? printw("O") : printw(" ");
                mvprintw(cd[1] + 1, cd[0], "P");
                move(cd[1] + 1, cd[0]);
            } else if (str[cd[1] + 1][cd[0]] == 'X' && str[cd[1] + 2]
            [cd[0]] != '#' && str[cd[1] + 2][cd[0]] != 'X') {
                cd[3] += (str[cd[1] + 2][cd[0]] == 'O') ? 1: 0;
                printw(" ");
                mvprintw(cd[1] + 1, cd[0], "P");
                mvprintw(cd[1] + 2, cd[0], "X");
                str[cd[1] + 2][cd[0]] = 'X';
                str[cd[1] + 1][cd[0]] = ' ';
                move(cd[1] + 1, cd[0]);
            }
            break;
        default:
            my_switch4(str, buff, tot, cd);
    }
}

void my_switch2(char **str, char *buff, int tot, int *cd)
{
    switch (cd[2]) {
        case KEY_UP :
            if (str[cd[1] - 1][cd[0]] != '#' && str[cd[1] - 1][cd[0]] != 'X') {
                (str[cd[1]][cd[0]] == 'O') ? printw("O") : printw(" ");
                mvprintw(cd[1] - 1, cd[0], "P");
                move(cd[1] - 1, cd[0]);
            }
            if (str[cd[1] - 1][cd[0]] == 'X' && str[cd[1] - 2]
            [cd[0]] != '#' && str[cd[1] - 2][cd[0]] != 'X') {
                cd[3] += (str[cd[1] - 2][cd[0]] == 'O') ? 1 : 0;
                printw(" ");
                mvprintw(cd[1] - 1, cd[0], "P");
                mvprintw(cd[1] - 2, cd[0], "X");
                str[cd[1] - 1][cd[0]] = ' ';
                str[cd[1] - 2][cd[0]] = 'X';
                move(cd[1] - 1, cd[0]);
            }
        default:
            my_switch3(str, buff, tot, cd);
    }
}

void my_switch(char **str, char *buff, int tot, int *cd)
{
    switch (cd[2]) {
        case ' ' :
            init_w(buff, tot);
            endwin();
            exit (0);
            break;
        case KEY_BACKSPACE :
            endwin();
            exit (0);
            break;
        default:
            my_switch2(str, buff, tot, cd);
    }
}