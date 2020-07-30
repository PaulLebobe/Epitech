/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my_puts
*/

#include "my.h"

int my_putchar(char x)
{
    write(1, &x, 1);
}

void my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
}

void my_putarray(char **str)
{
    for (int i = 0; str[i] != NULL; i++)
        for (int e = 0; str[i][e]; e++) {
            if (str[i][e] > '0' && str[i][e] < '9' && e > 29) {
                attron(COLOR_PAIR(str[i][e] - 48));
                refresh();
                printw("%c", '*');
                refresh();
                attroff(COLOR_PAIR(str[i][e] - 48));
                refresh();
            } else {
                printw("%c", str[i][e]);
            }
        }
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        i++;
        if (s1[i] == '\0' || s2[i] == '\0')
            return 0;
    }
    return s1[i] - s2[i];
}

int to_ascii(char c)
{
    int nb = 0;

    while (c != 0) {
    nb++;
    c--;
    }
    return (nb);
}