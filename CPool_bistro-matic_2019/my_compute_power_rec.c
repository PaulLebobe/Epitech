/*
** EPITECH PROJECT, 2019
** raise p
** File description:
** raise p
*/

#include "my.h"
#include <stdlib.h>

char *my_power(char *nb, char *p)
{
    char *result = my_malloc(my_strlen(nb) * my_strlen(p) * 2);

    if (my_strcmp(p, "0") < 0)
        result[0] = '0';
    else if (my_strcmp(p, "0") == 0)
        result[0] = '1';
    else
        result = factinf(nb, my_power(nb, sub(p, "1", 0)));
    return (result);
}
