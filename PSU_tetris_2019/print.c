/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** print
*/

#include "my.h"

void p_next(void)
{
    char *ne = "NEXT : \0";

    for (int y = 0; ne[y]; y++)
        elem.map[3][y + opt.col * 2 + 35] = ne[y];
    for (int x = 0; io[elem.nb].piece[x] != NULL; x++)
        for (int e = 0; io[elem.nb].piece[x][e] != '\0'; e++)
            elem.map[5 + x][e + opt.col * 2 + 37] = ' ';
    for (int x = 0; io[elem.next].piece[x] != NULL; x++)
        for (int e = 0; io[elem.next].piece[x][e] != '\0'; e++)
            elem.map[5 + x][e + opt.col * 2 + 37] = io[elem.next].piece[x][e];
}

void p_lines(void)
{
    char *li = "Lines : \0";
    char *lines = into_str(elem.lines);
    int y = 0;
    char *ti = "Timer : \0";
    char *timer = into_str(act.cl / CLOCKS_PER_SEC);
    int z = 0;

    if (elem.lines == 0)
        lines = "0\0";
    for (; li[y]; y++)
        elem.map[7][y + 5] = li[y];
    for (int e = 0; lines[e]; e++)
        elem.map[7][e + y + 5] = lines[e];
    if (act.cl / CLOCKS_PER_SEC == 0)
        timer = "0\0";
    for (; ti[z]; z++)
        elem.map[9][z + 5] = ti[z];
    for (int e = 0; timer[e]; e++)
        elem.map[9][e + z + 5] = timer[e];
}

void p_score(void)
{
    char *sc = "Score : \0";
    char *lv = "Level : \0";
    char *level = into_str(opt.level);
    int y = 0;
    int i = 0;
    char *nb = into_str(elem.score);
    char *name = "TETRIS 2.0\0";

    if (elem.score == 0)
        nb = "0\0";
    for (int x = 0; name[x]; x++)
        elem.map[1][x + 5] = name[x];
    for (; sc[i]; i++)
        elem.map[3][i + 5] = sc[i];
    for (int e = 0; nb[e]; e++)
        elem.map[3][e + i + 5] = nb[e];
    for (; sc[y]; y++)
        elem.map[5][y + 5] = lv[y];
    for (int e = 0; level[e]; e++)
        elem.map[5][e + y + 5] = level[e];
}