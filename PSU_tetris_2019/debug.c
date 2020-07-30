/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** debug
*/

#include "my.h"

void debug_erase(void)
{
    move(0, 0);
    for (int i = 0; i < 200; i++) {
        printw("%s", "                                                       ");
        printw("%s", "                                                       ");
        printw("%c", '\n');
    }
    move(0, 0);
}

void debug2(void)
{
    printw("%s", opt.next);
    printw("\nLevel :  ");
    printw("%i", opt.level);
    printw("\nSize :  ");
    printw("%i%c%i", opt.row, '*', opt.col - 1);
    printw("%s%i", "\nTerminos :  ", elem.max);
    for (int i = 0; i < elem.max; i++) {
        printw("%s%s%s%i%c%i%s%i%s", "\nTetriminos :  Name ", io[i].path + 11,
        " :  Size ", io[i].wight, '*', io[i].height, " :  Color ", io[i].color,
        " :");
        for (int x = 0; io[i].piece[x]; x++) {
            printw("%c", '\n');
            for (int w = 0; io[i].piece[x][w]; w++)
                (io[i].piece[x][w] > '0' && io[i].piece[x][w] < '9')
                ? printw("%c", '*') : printw("%c", ' ');
        }
    }
    printw("%s", "\nPress any key to start Tetris");
}

void debug(void)
{
    printw("***DEBUG MODE***\n");
    printw("Key Left :  ");
    printw("%c", opt.left);
    printw("\nKey Right :  ");
    printw("%c", opt.right);
    printw("\nKey Turn :  ");
    printw("%c", opt.turn);
    printw("\nKey Drop :  ");
    printw("%c", opt.drop);
    printw("\nKey Quit :  ");
    printw("%c", opt.quit);
    printw("\nKey Pause :  ");
    printw("%c", opt.pause);
    printw("\nNext :  ");
    debug2();
    getch();
    debug_erase();
}