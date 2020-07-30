/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#include "my.h"

char *my_strdup(char *str)
{
    int len = my_strlen(str);
    int i = -1;
    char *dest;

    if (str == NULL)
        return (NULL);
    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL) {
        my_putstr("ERROR: Out of memory! malloc() failed\n");
        return (NULL);
    }
    while (str[++i])
        dest[i] = str[i];
    dest[i] = '\0';
    return (dest);
}