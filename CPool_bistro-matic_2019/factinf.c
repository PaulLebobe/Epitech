/*
** EPITECH PROJECT, 2019
** fact inf
** File description:
** infinite factoriel
*/

#include "my.h"
#include <stdlib.h>

char *getcharfact(char *prem, char sec, int *keepnbr, int y)
{
    int num;
    char *res = my_malloc(my_strlen(prem) + 2);
    int i;

    for (int z = 0; z < y; z++)
        res[z] = '0';
    for (i = 0; prem[i] != '\0'; i++) {
        num = (prem[i] - 48) * (sec - 48) + *keepnbr;
        *keepnbr = 0;
        while (num >= 10) {
            num -= 10;
            *keepnbr += 1;
        }
        res[i + y] = num + 48;
    }
    if (*keepnbr > 0) {
        res[i + y] = *keepnbr + 48;
        *keepnbr = 0;
    }
    return (res);
}

char *factinf(char *pr, char *sec)
{
    char **res = my_malloc2(my_strlen(pr) + my_strlen(sec) * 1);
    int i = 0;
    int keepnbr = 0;

    pr = my_revstr(pr);
    sec = my_revstr(sec);
    for (i = 0; sec[i] != '\0'; i++) {
        res[i] = getcharfact(pr, sec[i], &keepnbr, i);
        res[i] = my_revstr(res[i]);
    }
    if (i == 1)
        res[1] = 0;
    for (int y = 1; y < i; y++)
        res[0] = two_positiv(res[0], res[y]);
    return (res[0]);
}

char *inffact(char *fact, char *mult)
{
    int negtime = ((fact[0] == '_') ^ (mult[0] == '_')) ? 1 : 0;
    char *t = my_malloc(my_strlen(fact) + my_strlen(mult) + 1);

    fact = (fact[0] == '_') ? fact + 1 : fact;
    mult = (mult[0] == '_') ? mult + 1 : mult;
    t = factinf(fact, mult);
    if (negtime == 1)
        t = my_strcat("_", t);
    return (t);
}
