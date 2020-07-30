/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** into_str
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    char temp;

    while (str[i] != '\0')
        i++;
    i--;
    for (int z = 0; z < i; z++) {
        temp = str[i];
        str[i] = str[z];
        str[z] = temp;
        i--;
    }
    return str;
}

char *into_str(int nb)
{
    char *str = malloc(sizeof(char) * 10);

    if (nb == 0)
        return ("0");
    for (int i = 0; nb != 0; i++) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
        str[i + 1] = '\0';
    }
    return (my_revstr(str));
}