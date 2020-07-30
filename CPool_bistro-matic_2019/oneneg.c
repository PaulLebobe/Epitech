/*
** EPITECH PROJECT, 2019
** one neg
** File description:
** one neg
*/

#include <stdlib.h>
#include "my.h"

char getchar_oneneg(char prem, char sec, int *keepnbr)
{
    int num;
    char res;

    if (*keepnbr == 1) {
        sec += 1;
        *keepnbr = 0;
    }
    if (prem < sec) {
        num = (10 + prem) - sec;
        *keepnbr = 1;
    } else
        num = prem - sec;
    res = num + 48;
    return (res);
}

char *one_neg(char *pr, char *sec)
{
    char *res = my_malloc(T(my_strlen(pr), my_strlen(sec)) + 2);
    int i = my_strlen(pr);
    int maxsec = my_strlen(sec);
    int keepnbr = 0;

    pr = my_revstr(pr);
    sec = my_revstr(sec);
    for (int y = 0; y < i ; y++) {
        if (y < maxsec)
            res[y] = getchar_oneneg(pr[y], sec[y], &keepnbr);
        else
            res[y] = getchar_oneneg(pr[y], '0', &keepnbr);
    }
    res = my_revstr(res);
    return (res);
}
