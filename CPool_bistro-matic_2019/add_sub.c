/*
** EPITECH PROJECT, 2019
** add_sub
** File description:
** addition substraction
*/

#include <stdlib.h>
#include "my.h"

char *add_sub(char *str)
{
    int i = 0;
    int e = 0;
    char *temp;
    char sign;
    char *nb = my_malloc(my_strlen(str) + 1);
    char *nb2 = my_malloc(my_strlen(str) + 1);

    for (; str[i] != '-' && str[i] != '+'; i++)
        if (str[i] == '\0')
            return (str);
    sign = leftnbr(str, nb, &e, &i);
    nb = my_revstr(nb);
    rightnbr(str, nb2, &i);
    temp = calcul(nb, nb2, sign);
    for (int x = 0; temp[x] != '\0'; x++, e++)
        str[e + 1] = temp[x];
    return (add_sub(str));
}
