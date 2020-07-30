/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** check
*/

#include "my.h"

void w_map(void)
{
    for (int y = 0; io[elem.nb].piece[y] != NULL; y++)
        for (int x = 0; io[elem.nb].piece[y][x]; x++)
            if (io[elem.nb].piece[y][x] > '0' && io[elem.nb].piece[y][x] < '9')
                elem.map[y + elem.y][x + elem.x] = io[elem.nb].piece[y][x];
}

void check_stop(void)
{
    for (int y = 0; io[elem.nb].piece[y] != NULL; y++)
        for (int x = 0; io[elem.nb].piece[y][x]; x++)
            if (io[elem.nb].piece[y][x] > '0' && io[elem.nb].piece[y][x] <= '9'
            && elem.map[y + elem.y + 1][x + elem.x] > '0' && elem.map[y + elem.y
            + 1][x + elem.x] < '9' && (y == io[elem.nb].height - 1 || (io[elem.
            nb].piece[y + 1][x] < '0' || io[elem.nb].piece[y + 1][x] > '9')))
                act.new = 0;
}

void check_line(void)
{
    int tot;

    for (int i = 1; i <= opt.row; i++) {
        tot = 0;
        for (int e = 31; e < 30 + 2 * opt.col; e++)
            if (elem.map[i][e] > '0' && elem.map[i][e] < '9')
                tot++;
        if (tot == opt.col - 1) {
            elem.score += 10;
            elem.lines += 1;
            if (elem.lines % 10 == 0)
                opt.level++;
            for (; i > 1; i--)
                for (int e = 31; e < 30 + 2 * opt.col; e++)
                    elem.map[i][e] = elem.map[i - 1][e];
        }
    }
}

char *into_str(int nb)
{
    int temp = nb;
    int i = 0;
    int e = 0;
    char *result;
    int exp;

    for (i; temp != 0; i++)
        temp = temp / 10;
    result = malloc(sizeof(char) * (i + 2));
    for (;i != 0; e++, i--) {
        exp = 1;
        for (int j = i; j != 1; j--) {
            exp = exp * 10;
        }
        result[e] = (nb / exp) + 48;
        result[e + 1] = '\0';
        nb = nb - (nb / exp) * exp;
    }
    return result;
}