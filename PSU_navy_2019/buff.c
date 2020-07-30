/*
** EPITECH PROJECT, 2020
** Navi
** File description:
** Buff
*/

#include "my.h"

int check_buff2(char *buff)
{
    int e = 1;
    int c = 5;
    int d = 6;

    for (int a = 2, b = 3; d < 32; a += 8, b += 8) {
        if (buff[a] != buff[c] && buff[b] != buff[d])
            return (84);
        if (buff[a] == buff[c] && buff[b] - e
        != buff[d] && buff[b] + e != buff[d])
            return (84);
        if (buff[b] == buff[d] && buff[a] - e
        != buff[c] && buff[a] + e != buff[c])
            return (84);
        c += 8;
        d += 8;
        e++;
    }
    return (0);
}

int check_buff(char *buff)
{
    if (buff[32] != '\0')
        return (84);
    for (int i = 0 , e = 50; i < 32; i += 8, e++)
        if (buff[i] != e)
            return (84);
    for (int i = 1, y = 4; y < 32; i += 8, y += 8)
        if (buff[i] != ':' || buff[y] != ':')
            return (84);
    for (int i = 2, y = 5; y < 32; i += 8, y += 8)
        if (buff[i] < 65 || buff[i] > 72 || buff[y] < 65 || buff[y] > 72)
            return (84);
    for (int i = 3, y = 6; y < 32; i += 8, y += 8)
        if (buff[i] < 49 || buff[i] > 56 || buff[y] < 49 || buff[y] > 56)
            return (84);
    for (int i = 7; i < 32; i += 8)
        if (buff[i] != '\n')
            return (84);
    return (check_buff2(buff));
}

void buffer(int nb, char **av, char *buff)
{
    int buff_size = 35;
    int offset = 0;
    int fd = open(av[nb], O_RDONLY);
    int len;

    while ((len = read(fd, buff + offset, buff_size - offset)) > 0)
        offset = offset + len;
    buff[offset] = '\0';
}

char *fill_buff(int ac, char **av, char *buff)
{
    if (ac == 2) {
        buff = malloc(sizeof(char) * 35);
        buffer(1, av, buff);
    }
    if (ac == 3) {
        buff = malloc(sizeof(char) * 35);
        buffer(2, av, buff);
    }
    return (buff);
}