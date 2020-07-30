/*
** EPITECH PROJECT, 2019
** bistr-matic
** File description:
** error.c
*/

#include "my.h"

int error(char **av)
{
    if (my_strlen(av[1]) < 2)
        return (1);
    for (int i = 0; av[1][i] != '\0'; i++)
        for (int e = 0; av[1][e] != '\0'; e++) {
            if (e == i)
                e++;
            if (av[1][e] == av[1][i])
                return (1);
        }
    for (int i = 0; av[2][i] != '\0'; i++)
        for (int e = 0; av[2][e] != '\0'; e++) {
            if (e == i)
                e++;
            if (av[2][e] == av[2][i])
                return (1);
        }
    if (my_strlen(av[2]) != 7)
        return (1);
    return (0);
}
