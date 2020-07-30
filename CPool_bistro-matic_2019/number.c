/*
** EPITECH PROJECT, 2019
** number
** File description:
** number
*/

#include <stdlib.h>
#include "my.h"

int number(char *str)
{
    int y = 0;
    char *temp = my_malloc(my_strlen(str) + 1);

    if (!((str[0] >= '0' && str[0] <= '9') || str[0] == '-' || str[0] == ' '))
        return (0);
    for (int i = 0; (str[i] >= '0' && str[i] <= '9') ||
    str[i] == '-' || str[i] == ' '; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            temp[y] = str[i];
            y++;
        }
        if (str[i] == '-' && y == 0){
            temp[0] = '-';
            y++;
        }
    }
    return (my_getnbr(temp));
}
