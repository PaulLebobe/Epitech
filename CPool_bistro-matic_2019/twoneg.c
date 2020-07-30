/*
** EPITECH PROJECT, 2019
** two neg
** File description:
** two neg
*/

#include <stdlib.h>
#include "my.h"

char getchar_twoneg(char prem, char sec, int *keepnbr)
{
    int num = (prem - 48) + (sec - 48);
    char res;

    if (*keepnbr == 1) {
        num += 1;
        *keepnbr = 0;
    }
    if (num >= 10) {
        num -= 10;
        *keepnbr = 1;
    }
    res = num + 48;
    return (res);
}

char *two_neg(char *pr, char *sec)
{
    char *res = my_malloc(T(my_strlen(pr), my_strlen(sec)) + 2);
    int i = 0;
    int keepnbr = 0;

    pr = my_revstr(pr);
    sec = my_revstr(sec);
    for (; pr[i] != '\0' && sec[i] != '\0'; i++)
        res[i] = getchar_twoneg(pr[i], sec[i], &keepnbr);
    if (pr[i] == '\0')
        for (; sec[i] != '\0'; i++)
            res[i] = getchar_twoneg('0', sec[i], &keepnbr);
    if (sec[i] == '\0')
        for (; pr[i] != '\0'; i++)
            res[i] = getchar_twoneg(pr[i], '0', &keepnbr);
    if (keepnbr == 1)
        res[i] = '1';
    return (my_revstr(res));
}
