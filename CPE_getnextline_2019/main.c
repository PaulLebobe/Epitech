/*
** EPITECH PROJECT, 2019
** Getnextline
** File description:
** change line
*/

#include "get_next_line.h"

int my_putchar(char x)
{
    write(1, &x, 1);
}

int my_putstr (char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar (str[i]);
        i = i + 1;
    }
    return (0);
}

int main (int ac, char **av)
{
    char *str ;
    int fd = open(av[1], O_RDONLY);

    str = get_next_line(fd);
    str = get_next_line(fd);
    my_putstr(str);
}