/*
** EPITECH PROJECT, 2019
** change base
** File description:
** change base from base to decimal
*/

#include "my.h"
#include <stdlib.h>

char getcharbase(char *str, char const *base)
{
    char c;

    c = base[my_getnbr(str)];
    return (c);
}

char *removezero(char *str)
{
    if (str[0] == '0')
        str++;
    return str;
}

char *computebase(char *nbr, char const *base, char *calcul)
{
    int baselen = my_strlen(base);
    char *res = my_malloc(my_strlen(nbr) * baselen + 1);

    for (int i = 0; my_strcmp(calcul, "0") != 0; i++) {
        res[i] = getcharbase(divis(nbr, calcul), base);
        nbr = removezero(mod(nbr, calcul));
        calcul = divis(calcul, into_str(baselen));
    }
    return res;
}

char *dectobase(char *nbr, char const *base)
{
    int baselen = my_strlen(base);
    char *res = my_malloc(my_strlen(nbr) * baselen + 1);
    char *calcul = my_malloc(my_strlen(nbr) * baselen + 1);
    int addneg = 0;

    if (nbr[0] == '-' || nbr[0] == '_') {
        nbr++;
        addneg = 1;
    }
    if (nbr[0] == '0')
        nbr++;
    calcul[0] = '1';
    for (int y = 0; my_strcmp(calcul, nbr) <= 0; y++)
        calcul = factinf(into_str(baselen), calcul);
    res = computebase(nbr, base, calcul);
    if (addneg == 1)
        res = my_strcat("-", res);
    return (res);
}
