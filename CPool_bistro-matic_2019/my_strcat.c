/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenates two string
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int destlengh = 0;
    int i;
    char *tp = my_malloc(my_strlen(dest) + my_strlen(src) + 2);

    for (i = 0; dest[i] != '\0'; i++) {
        destlengh++;
        tp[i] = dest[i];
    }
    for (i = 0; src[i] != '\0'; i++)
        tp[destlengh + i] = src[i];
    tp[destlengh + i] = '\0';
    return (tp);
}
