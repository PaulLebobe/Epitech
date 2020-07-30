/*
** EPITECH PROJECT, 2020
** my_add_str.c
** File description:
** add str to str
*/

#include "my.h"

char **my_add_str(char **str1, char *str2)
{
    int i = -1;
    int size;
    char **dest = NULL;

    if (str1 == NULL) {
        str1 = malloc(sizeof(char *) * 2);
        str1[0] = my_strdup(str2);
        str1[1] = NULL;
        return (str1);
    }
    size = my_tab_size(str1);
    dest = (char **) malloc(sizeof(char *) * (size + 2));
    dest[size + 1] = NULL;
    while (++i < size)
        dest[i] = str1[i];
    dest[i] = my_strdup(str2);
    return (dest);
}