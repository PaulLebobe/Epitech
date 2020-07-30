/*
** EPITECH PROJECT, 2019
** addition
** File description:
** addition
*/

#include "my.h"
#include <stdlib.h>

char getchar(char prem, char sec, int *keepnbr)
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

char *two_positiv(char *pr, char *sec)
{
    char *res = my_malloc(T(my_strlen(pr), my_strlen(sec)) * 2);
    int i = 0;
    int keepnbr = 0;

    pr = my_revstr(pr);
    sec = my_revstr(sec);
    for (; pr[i] != '\0' && sec[i] != '\0'; i++)
        res[i] = getchar(pr[i], sec[i], &keepnbr);
    if (pr[i] == '\0')
        for (; sec[i] != '\0'; i++)
            res[i] = getchar('0', sec[i], &keepnbr);
    if (sec[i] == '\0')
        for (; pr[i] != '\0'; i++)
            res[i] = getchar(pr[i], '0', &keepnbr);
    if (keepnbr == 1)
        res[i] = '1';
    res = my_revstr(res);
    res[i + 1] = 0;
    return (res);
}

char *isaneg(char *prem, char *sec)
{
    char *res;
    if (prem[0] == '_'){
        if (my_strcmp(prem + 1, sec) > 0) {
            res = one_neg(prem + 1 , sec);
            res = my_strcat("_", res);
        }
        else
            res = one_neg(sec, prem + 1);
    }
    if (sec[0] == '_') {
        if (my_strcmp(sec + 1, prem) > 0) {
            res = one_neg(sec + 1, prem);
            res = my_strcat("_", res);
        }
        else
            res = one_neg(prem, sec + 1);
    }
    return (res);
}

char *aff_res(char *prem, char *sec)
{
    char *res;

    if (prem[0] == '_' && sec[0] == '_') {
        res = two_neg(prem + 1, sec + 1);
        res = my_strcat("_", res);
        return (res);
    }
    if (prem[0] == '_' || sec[0] == '_')
        return (isaneg(prem, sec));
    if (!(prem[0] == '_' && sec[0] == '_')) {
        res = two_positiv(prem, sec);
        return (res);
    }
    return (0);
}
