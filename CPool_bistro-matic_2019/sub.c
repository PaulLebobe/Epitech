/*
** EPITECH PROJECT, 2019
** sub
** File description:
** substraction
*/

#include <stdlib.h>
#include "my.h"

void loop2(char *str, int *i, char nb, char *result)
{
    while (str[*i] != '\0') {
        result[*i] = str[*i] - nb;
        if (result[*i] < 48) {
            result[*i] = result[*i] + 10;
            nb = 1;
        }
        else
            nb = 0;
        *i += 1;
    }
    return;
}

char *sub(char *str, char *str2, int neg)
{
    int i = 0;
    char nb = 0;
    char *result = my_malloc(my_strlen(str) + 1);

    str = my_revstr(str);
    str2 = my_revstr(str2);
    while (str[i] != '\0' && str2[i] != '\0') {
        result[i] = str[i] - str2[i] + 48 - nb;
        if (result[i] < 48) {
            result[i] = result[i] + 10;
            nb = 1;
        }
        else
            nb = 0;
        i++;
    }
    loop2(str, &i, nb, result);
    if (neg == 1)
        result[i] = '_';
    return (my_revstr(result));
}
