/*
** EPITECH PROJECT, 2019
** removespace
** File description:
** remove space for a string
*/

#include <stdlib.h>
#include "my.h"

char *removespace(char *str)
{
    char *temp = my_malloc(my_strlen(str) + 1);
    int y = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            temp[y] = str[i];
            y++;
        }
    }
    temp[y] = '\0';
    return (temp);
}
