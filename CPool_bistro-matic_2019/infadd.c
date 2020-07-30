/*
** EPITECH PROJECT, 2019
** infiniadd
** File description:
** infadd
*/

#include <stdlib.h>
#include "my.h"

char *calcul(char *prem, char *sec, char op)
{
    prem = removespace(prem);
    sec = removespace(sec);
    if (op == '+')
        return aff_res(prem, sec);
    if (op == '*')
        return inffact(prem, sec);
    if (op == '/')
        return divis(prem, sec);
    if (op == '%')
        return mod(prem, sec);
    if (op == '-') {
        if ((sec[0] == '_') | (prem[0] == '_'))
            return (sec[0] == '_') ? aff_res(prem, sec + 1) :
                aff_res(prem, my_strcat("_", sec));
        if (my_strcmp(prem, sec) > 0)
            return sub(prem, sec, 0);
        else
            return sub(sec, prem, 1);
    }
    return 0;
}
