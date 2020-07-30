/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init
*/

#include "my.h"

void init(void)
{
    opt.level = 1;
    opt.left = KEY_LEFT;
    opt.right = KEY_RIGHT;
    opt.turn = KEY_UP;
    opt.drop = KEY_DOWN;
    opt.quit = 113;
    opt.pause = 112;
    opt.row = 20;
    opt.col = 10;
    act.cl = clock();
    elem.score = 0;
    elem.lines = 0;
    opt.next = "Yes";
}