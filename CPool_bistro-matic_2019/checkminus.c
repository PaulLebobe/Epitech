/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** checkminus
*/

#include "my.h"

char *checkminus(char *str)
{
    int op = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' && op == 1)
            str[i] = '_';
        op = (isop(str[i])) ? 1 : 0;
    }
    return (str);
}
