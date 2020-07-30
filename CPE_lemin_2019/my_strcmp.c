/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compare_sup_if
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i;
    i = 0;
    if (s1 == NULL || s2 == NULL)
        return (84);
    if (my_strlen(s1) != my_strlen(s2))
        return (84);
    while (s1[i]) {
        if (s1[i] != s2[i])
            return (84);
        i++;
    }
    return (0);
}