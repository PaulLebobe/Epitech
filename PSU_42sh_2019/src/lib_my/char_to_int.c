/*
** EPITECH PROJECT, 2020
** char_to_int
** File description:
** char_to_int
*/

#include "include_lib.h"

int char_to_int(char *str)
{
    int value = 0;

    for (int i = 0; (str[i] >= '0' && str[i] <= '9')
        || (i == 0 && str[i] == '-'); i++) {
        value *= 10;
        value += str[i] - '0';
    }
    if (str[0] == '-')
        value *= -1;
    return (value);
}

int char_to_int_progress(char *str, int *progress)
{
    int value = 0;
    int i = 0;

    for (i = 0; (str[i] >= '0' && str[i] <= '9')
        || (i == 0 && str[i] == '-'); i++) {
        value *= 10;
        value += str[i] - '0';
    }
    if (str[0] == '-')
        value *= -1;
    *progress += i;
    return (value);
}