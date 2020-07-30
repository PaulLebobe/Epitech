/*
** EPITECH PROJECT, 2019
** last neg
** File description:
** remove _ at the end of calc
*/

#include "my.h"
#include <stdlib.h>

char *lastneg(char *str)
{
    int i = 1;
    int e = 0;
    char *temp;
    char *nb = my_malloc(my_strlen(str) + 2);
    char *nb2 = my_malloc(my_strlen(str) + 2);

    for (; str[i] != '_'; i++)
        if (str[i] == '\0')
            return (removespace(str));
    leftnbr(str, nb, &e, &i);
    nb = my_revstr(nb);
    rightnbr(str, nb2, &i);
    temp = calcul(nb, nb2, '-');
    for (int x = 0; temp[x] != '\0'; x++, e++)
        str[e + 1] = temp[x];
    str[e + 1] = 0;
    return (add_sub(str));
}
