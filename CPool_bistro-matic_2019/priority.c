/*
** EPITECH PROJECT, 2019
** priority
** File description:
** calc factor
*/

#include "my.h"
#include <stdlib.h>

char leftnbr(char *str, char *nb, int *e, int *i)
{
    char sign;

    sign = str[*i];
    str[*i] = ' ';
    *e = *i - 1;
    *i += 1;
    for (int x = 0; (str[*e] > 47 && str[*e] < 58)
    || str[*e] == ' ' || str[*e] == '_'; x++) {
        nb[x] = str[*e];
        str[*e] = ' ';
        *e -= 1;
        if (*e < 0)
            return (sign);
    }
    return (sign);
}

void rightnbr(char *str, char *nb2, int *i)
{
    for (int x = 0;  (str[*i] > 47 && str[*i] < 58) ||
    str[*i] == ' ' || str[*i] == '_'; x++) {
        nb2[x] = str[*i];
        str[*i] = ' ';
        *i += 1;
    }
}

char *priority(char *str)
{
    int i = 0;
    int e;
    char * temp;
    char sign;
    char *nb = my_malloc(my_strlen(str) + 2);
    char *nb2 = my_malloc(my_strlen(str) + 2);

    for (; str[i] != '*' && str[i] != '%' && str[i] != '/'; i++)
        if (str[i] == '\0')
            return (str);
    sign = leftnbr(str, nb, &e, &i);
    nb = my_revstr(nb);
    rightnbr(str, nb2, &i);
    temp = calcul(nb, nb2, sign);
    for (int x = 0; temp[x] != '\0'; x++, e++)
        str[e + 1] = temp[x];
    str = rmdoubleneg(str);
    return (priority(str));
}
