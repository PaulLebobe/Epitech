/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** eval_expr
*/

#include "my.h"

char *eval_expr(char *str, char *base, char *op)
{
    str = removespace(str);
    str = changeop(str, op);
    str = basetodecimal(str, base);
    str = rmparenthese(str);
    str = priority(str);
    str = add_sub(str);
    str = lastneg(str);
    if (my_strcmp(base, "0123456789") != 0)
        str = dectobase(removespace(str), base);
    return (str);
}
