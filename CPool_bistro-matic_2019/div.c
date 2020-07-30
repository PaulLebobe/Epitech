/*
** EPITECH PROJECT, 2019
** div
** File description:
** div
*/

#include "my.h"
#include <stdlib.h>

void checkerror(char *divid)
{
        if (my_strcmp(divid, "0") == 0) {
        my_putstr(SYNTAX);
        exit(84);
    }
}

char *removestartzero(char *res)
{
    for (int y = 0; res[y] != 0; y++) {
        if (res[y] == '0')
            res++;
        else
            return (res);
    }
    return res;
}

char *divis(char *str, char *divid)
{
    char *res = my_malloc(my_strlen(str) + my_strlen(divid) + 1);
    char *rescalc = my_malloc(my_strlen(str) * my_strlen(divid) + 1);
    char **bin = my_malloc2(my_strlen(str) + my_strlen(divid) + 4);
    int i;

    checkerror(divid);
    bin[0] = "1";
    for (i = 1; my_strcmp(factinf(factinf(bin[i - 1], divid), "2"), str) <= 0;
    i++)
        bin[i] = factinf("2", bin[i - 1]);
    res[0] = '0';
    rescalc[0] = '0';
    for (int y = i - 1; y >= 0; y -= 1) {
        if (my_strcmp(two_positiv(factinf(bin[y], divid), rescalc), str) <= 0) {
            res = two_positiv(bin[y], res);
            rescalc = two_positiv(rescalc, factinf(bin[y], divid));
        }
    }
    return (removestartzero(res));
}
