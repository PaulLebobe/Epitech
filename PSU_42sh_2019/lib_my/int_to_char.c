/*
** EPITECH PROJECT, 2019
** int_to_char
** File description:
** c
*/

#include "include_lib/include_lib.h"

char *int_to_char2(int nbr, int size_nbr_and_neg)
{
    char *char_nbr;
    int i = 0;
    int it_zero = 1;

    if (nbr != 0) {
        char_nbr = int_to_char2(nbr / 10, size_nbr_and_neg);
        it_zero = 0;
    } else {
        char_nbr = malloc(sizeof(char) * (size_nbr_and_neg + 1));
        for (i = 0; i < size_nbr_and_neg + 1; i++)
            char_nbr[i] = '\0';
    }
    if (it_zero == 0) {
        for (i = 0; char_nbr[i] != '\0'; i++);
        char_nbr[i] = (char) (nbr % 10) + '0';
    }
    return (char_nbr);
}

int is_neg(int *nbr, int *save)
{
    int size_up = 0;

    if (*nbr < 0) {
        size_up = 1;
        if (*nbr == -2147483648) {
            *nbr += 1;
            *save = 1;
        }
        *nbr *= -1;
    }
    return (size_up);
}

char *int_to_char(int nbr)
{
    char *nbr_string = NULL;
    int save = 0;
    int neg = is_neg(&nbr, &save);
    int size = 0;
    int nbr_save = nbr;

    for (size = 0; nbr > 0; size++)
        nbr /= 10;
    nbr_string = int_to_char2(nbr_save, size + neg);
    if (neg) {
        nbr_string = my_realloc_char_star(nbr_string, 1);
        for (int i = size + 1; i > 0; i--)
            nbr_string[i] = nbr_string[i - 1];
        nbr_string[0] = '-';
        if (save == 1)
            nbr_string[size + 1] = '8';
    }
    return (nbr_string);
}