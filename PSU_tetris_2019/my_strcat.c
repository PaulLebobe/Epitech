/*
** EPITECH PROJECT, 2019
** my_cat
** File description:
** str cat
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int e = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (; dest[i] != '\0'; i++)
        tmp[i] = dest[i];
    while (src[e] != '\0') {
        tmp[i] = src[e];
        i++;
        e++;
    }
    tmp[i] = '\0';
    return (tmp);
}
