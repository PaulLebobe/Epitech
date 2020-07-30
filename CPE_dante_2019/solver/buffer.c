/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** buffer
*/

#include "my.h"

char **to_array(char *str)
{
    char **buff;
    int j = 0;

    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++)
        io.col++;
    for (int i = 0, tmp = 0; str[i]; i++) {
        if (str[i] == '\n' && io.col != tmp)
            exit(84);
        tmp = str[i] != '\n' ? tmp + 1 : 0;
    }
    for (int i = 0; str[i]; i++)
        io.lign = (str[i] == '\n') ?  io.lign += 1 : io.lign;
    buff = malloc(sizeof(char *) * (io.lign + 3));
    for (int i = 0; i < io.lign + 3; i++)
        buff[i] = malloc(sizeof(char) * (io.col + 1));
    for (int i = 0; i < io.lign + 1; i++, j++)
        for (int x = 0; str[j] != '\n' && str[j] != '\0'; j++, x++)
            buff[i][x] = str[j];
    return (buff);
}

long f_size(const char *filename)
{
    struct stat s;

    if (stat(filename, &s) != 0)
        exit(84);
    return (s.st_size);
}

char **buffer(char **av)
{
    int buff_size = f_size(av[1]);
    char *str = malloc(sizeof(char) * f_size(av[1]));
    int offset = 0;
    int fd = open(av[1], O_RDONLY);
    int len = 0;

    if (fd == -1)
        exit (84);
    while ((len = read(fd, str + offset, buff_size - offset)) > 0)
        offset = offset + len;
    str[offset] = '\0';
    return (to_array(str));
}