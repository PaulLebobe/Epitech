/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** main
*/

#include "my.h"

char **cr_temp(char **buff)
{
    char **temp = malloc(sizeof(char *) * io.lign + 3);

    for (int i = 0; i < io.lign + 1; i++)
        temp[i] = malloc(sizeof(char) * io.col + 3);
    for (int i = 0; i < io.lign + 1; i++)
        for (int e = 0; buff[i][e]; e++)
            temp[i][e] = buff[i][e];
    return (temp);
}

char **resolution(char **buff, int x, int y)
{
    char **temp = cr_temp(buff);

    buff[y][x] = 'o';
    if (x == io.col - 1 && y == io.lign)
        io.find = 1;
    if (x != io.col - 1 && buff[y][x + 1] == '*' && io.find == 0)
        buff = resolution(buff, x + 1, y);
    if (y != io.lign && buff[y + 1][x] == '*' && io.find == 0)
        buff = resolution(buff, x, y + 1);
    if (x != 0 && buff[y][x - 1] == '*' && io.find == 0)
        buff = resolution(buff, x - 1, y);
    if (y != 0 && buff[y - 1][x] == '*' && io.find == 0)
        buff = resolution(buff, x, y - 1);
    if (io.find == 1)
        return (buff);
    else
        return (temp);
}

void error(char **buff)
{
    for (int i = 0; i < io.lign + 1; i++)
        for (int e = 0; buff[i][e]; e++)
            if ((buff[i][e] != '*' && buff[i][e] != 'X') || e > io.col ||
            (buff[i][e] == '\n' && e < io.col))
                exit (84);
}

int main(int ac, char **av)
{
    char **buff;

    if (ac != 2)
        return (84);
    buff = buffer(av);
    error(buff);
    buff = resolution(buff, 0, 0);
    if (io.find == 1)
        my_putarray(buff);
    else
        my_putstr("no solution found\n");
}