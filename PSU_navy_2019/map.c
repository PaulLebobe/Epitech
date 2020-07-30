/*
** EPITECH PROJECT, 2020
** Navi
** File description:
** map
*/

#include "my.h"

char **fill_map(char *buff, int nb)
{
    char **map = malloc(sizeof(char *) * 18);

    map[0] = " |A B C D E F G H\n";
    map[1] = "-+---------------\n";
    for (int i = 1; i < 9; i++) {
        map[i + 1] = malloc(sizeof(char) * 20);
        map[i + 1][0] = i + 48;
        map[i + 1][1] = '|';
        map[i + 1][18] = '\n';
        for (int e = 2; e < 18; e++)
            map[i + 1][e] = (e % 2 == 0) ? '.' : ' ';
    }
    map = (nb == 1) ? fill_map2(map, buff) : map;
    return (map);
}

char **fill_map2(char **map, char *buff)
{
    char pos[4][4];

    for (int x = 0; x < 4; x++) {
        pos[x][0] = buff[2 + x * 8] - 63;
        pos[x][1] = buff[3 + x * 8] - 47;
        pos[x][2] = buff[5 + x * 8] - 63;
        pos[x][3] = buff[6 + x * 8] - 47;
    }
    for (int x = 0; x < 4; x++) {
        if (pos[x][0] == pos[x][2])
            for (int e = pos[x][1]; e <= pos[x][3]; e++)
                map[e][pos[x][0] * 2 - 2] = x + 50;
        if (pos[x][1] == pos[x][3])
            for (int e = pos[x][0] * 2 - 2; e <= pos[x][2] * 2 - 2; e += 2)
                map[pos[x][1]][e] = x + 50;
    }
    return (map);
}