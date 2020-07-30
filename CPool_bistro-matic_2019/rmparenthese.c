/*
** EPITECH PROJECT, 2019
** rm parenthese
** File description:
** remove
*/

#include <stdlib.h>
#include "my.h"

char *rmparenthese(char *str)
{
    int y = -1;
    char *res = my_malloc(my_strlen(str) + 1);

    for (int i = 0; str[i] != '\0'; i++) {
        res[i] = str[i];
        if (str[i] == '(')
            y = i;
        if (str[i] == ')') {
            res[y] = '\0';
            res = my_strcat(res, facto(str + y + 1));
            i = my_strlen(str) - 1;
        }
    }
    if (y == -1) {
        res = rmdoubleneg(res);
        return (res);
    }
    return (rmparenthese(res));
}

char *facto(char *str)
{
    int i = 0;
    int e;
    char *temp;
    char sign;
    char *nb = my_malloc(my_strlen(str) + 1);
    char *nb2 = my_malloc(my_strlen(str) + 1);

    for (; str[i] != '*' && str[i] != '%' && str[i] != '/'; i++)
        if (str[i] == ')')
            return (sum(str));
    sign = leftnbr(str, nb, &e, &i);
    nb = my_revstr(nb);
    rightnbr(str, nb2, &i);
    temp = calcul(nb, nb2, sign);
    for (int x = 0; temp[x] != '\0'; x++, e++)
        str[e + 1] = temp[x];
    return (facto(str));
}

char *sum(char *str)
{
    int i = 0;
    int e = 0;
    char *temp;
    char sign;
    char *nb = my_malloc(my_strlen(str) + 1);
    char *nb2 = my_malloc(my_strlen(str) + 1);

    for (; str[i] != '+' && str[i] != '-'; i++)
        if (str[i] == ')') {
            str[i] = ' ';
            return (rmdoubleneg(str));
        }
    sign = leftnbr(str, nb, &e, &i);
    nb = my_revstr(nb);
    rightnbr(str, nb2, &i);
    temp = calcul(nb, nb2, sign);
    for (int x = 0; temp[x] != '\0'; x++, e++)
        str[e + 1] = temp[x];
    return (sum(str));
}
