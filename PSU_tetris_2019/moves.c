/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** moves
*/

#include "my.h"

void moves2(int cd, int test)
{
    if (cd == opt.right && elem.y > 0) {
        for (int y = 0; io[elem.nb].piece[y] != NULL; y++)
            for (int x = 0; io[elem.nb].piece[y][x]; x++)
                if (elem.map[y + elem.y][x + elem.x] > '0' && elem.map[y +
                elem.y][x + elem.x] < '9' && io[elem.nb].piece[y][x] > '0'
                && io[elem.nb].piece[y][x] < '9' && (elem.map[y + elem.y][x +
                elem.x + 2] == '|' || (elem.map[y + elem.y][x + elem.x + 2] >
                '0' && elem.map[y + elem.y][x + elem.x + 2] < '9' && (x / 2 ==
                io[elem.nb].wight - 1 || io[elem.nb].piece[y][x + 2] == ' '))))
                test = 1;
        if (test == 0) {
            erase_p();
            elem.x += 2;
            w_map();
        }
    }
    if (cd == 3 || cd == 4) {
        endwin();
        exit(0);
    }
}

void moves3(int cd, int test)
{
    if (cd == opt.drop && elem.y > 0) {
        for (int y = 0; io[elem.nb].piece[y] != NULL; y++)
            for (int x = 0; io[elem.nb].piece[y][x]; x++)
                if (elem.map[y + elem.y][x + elem.x] > '0' && elem.map[y +
                elem.y][x + elem.x] < '9' && io[elem.nb].piece[y][x] > '0'
                && io[elem.nb].piece[y][x] < '9' && (elem.map[y + elem.y][x +
                elem.x + 1] == '|' || (elem.map[y + elem.y][x + elem.x + 1] >
                '0' && elem.map[y + elem.y][x + elem.x + 1] < '9' && (x == 0
                || io[elem.nb].piece[y + 1][x] == ' '))))
                    test = 1;
        if (test == 0) {
            erase_p();
            elem.y++;
            w_map();
        }
    }
    if (cd == opt.pause)
        while (getch() != opt.pause);
}

void moves(int cd)
{
    int test = 0;

    if (cd == opt.left && elem.y > 0) {
        for (int y = 0; io[elem.nb].piece[y] != NULL; y++)
            for (int x = 0; io[elem.nb].piece[y][x]; x++)
                if (elem.map[y + elem.y][x + elem.x] > '0' && elem.map[y +
                elem.y][x + elem.x] < '9' && io[elem.nb].piece[y][x] > '0'
                && io[elem.nb].piece[y][x] < '9' && (elem.map[y + elem.y][x +
                elem.x - 2] == '|' || (elem.map[y + elem.y][x + elem.x - 2] >
                '0' && elem.map[y + elem.y][x + elem.x - 2] < '9' && (x == 0
                || io[elem.nb].piece[y][x - 2] == ' '))))
                    test = 1;
        if (test == 0) {
            erase_p();
            elem.x -= 2;
            w_map();
        }
    }
    moves2(cd, test);
    moves3(cd, test);
}