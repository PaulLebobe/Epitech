/*
** EPITECH PROJECT, 2019
** My_Sokoban
** File description:
** Sokoban
*/

#include "my.h"

int error(char *buff)
{
    int nc = 0;
    int ne = 0;
    int p = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] != ' ' && buff[i] != '#' && buff[i] != 'P' && buff[i] !=
        'O' && buff[i] != 'X' && buff[i] != '\n')
            exit (84);
        if (buff[i] == 'P')
            p++;
        if (buff[i] == 'X')
            nc++;
        if (buff[i] == 'O')
            ne++;
    }
    if (p != 1 || ne != nc || ne == 0)
        exit (84);
    return (ne);
}

int main(int ac, char **av)
{
    long buff_size = f_size(av[1]);
    char buff[f_size(av[1])];
    int offset = 0;
    int fd = open(av[1], O_RDONLY);
    int len;
    int tot;

    while ((len = read(fd, buff + offset, buff_size - offset)) > 0)
        offset = offset + len;
    buff[offset] = '\0';
    if (ac != 2 || len < 0)
        exit (84);
    tot = error(buff);
    init_w(buff, tot);
    return (0);
}