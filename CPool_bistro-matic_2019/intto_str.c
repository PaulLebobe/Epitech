/*
** EPITECH PROJECT, 2019
** intostr
** File description:
** into str
*/

#include <stdlib.h>
#include "my.h"

void fillres(int *i, int *e, char *result, int *nb)
{
    int exp;

    while (*i != 0) {
        exp = 1;
        for (int j = *i; j != 1; j--) {
            exp = exp * 10;
        }
        result[*e] = ABS((*nb / exp)) + 48;
        *nb = *nb - (*nb / exp) * exp;
        *e += 1;
        *i -= 1;
    }
}

char *into_str(int nb)
{
    int temp = nb;
    int i = 0;
    int e = 0;
    char *result;

    if (nb == 0)
        return ("0");
    for (; temp != 0; i++)
        temp = temp / 10;
    result = my_malloc(i + 2);
    if (nb < 0) {
        e = 1;
        result[0] = '_';
    }
    fillres(&i, &e, result, &nb);
    return (result);
}
