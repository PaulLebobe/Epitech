/*
** EPITECH PROJECT, 2019
** change base
** File description:
** change base
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int getcharvalue(char nbr, char const *base)
{
    for (int i = 0; base[i] != '\0'; i++)
        if (nbr == base[i])
            return (i);
    return (0);
}

char *removechar(char *str)
{
    for (int i = 0; str[i] != 0; i++)
        if (!((str[i] >= '0' && str[i] <= '9') || isop(str[i])))
            str[i] = ' ';
    return (str);
}

char *getdecimalnbr(char *nbr, char const *base)
{
    char *tabres[my_strlen(nbr) + 1];
    int nbrlen = my_strlen(nbr);
    int baselen = my_strlen(base);
    char *res = my_malloc(baselen * nbrlen);
    char *calc = my_malloc(baselen * nbrlen);
    int y = 0;

    calc[0] = '1';
    res[0] = '0';
    nbr =  my_revstr(nbr);
    for (int i = 0; nbr[i] != '\0'; i++, y++) {
        tabres[y] = factinf(calc, into_str(getcharvalue(nbr[i], base)));
        calc = factinf(calc, into_str(baselen));
    }
    for (int i = 0; i != y; i++)
        res = two_positiv(res, tabres[i]);
    return res;
}

char *basetodecimal(char *str, char const *base)
{
    int y = 0;
    char *nbr = my_malloc(my_strlen(str) + 1);
    char *res = my_malloc(my_strlen(str) + 1);

    for (int i = 0; i <= my_strlen(str); i++) {
        if ((isop(str[i]) || str[i] == '\0') && nbr[0] != 0) {
            nbr = getdecimalnbr(nbr, base);
            res = my_strcat(res, nbr);
            nbr = my_malloc(my_strlen(str) + 1);
            y = 0;
        }
        if (isop(str[i]))
            res[my_strlen(res)] = str[i];
        if (!isop(str[i])) {
            nbr[y] = str[i];
            y++;
        }
        res = removechar(res);
    }
        return (res);
}
