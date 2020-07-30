/*
** EPITECH PROJECT, 2019
** malloc
** File description:
** my malloc
*/

#include <stdlib.h>

char *my_malloc(int i)
{
    char *res = malloc(sizeof(char) * i);

    for (int y = 0; y < i; y++)
        res[y] = 0;
    return (res);
}

char **my_malloc2(int i)
{
    char **res = malloc(sizeof(char **) * i);

    for (int y = 0; y < i; y++)
        res[y] = 0;
    return (res);
}
