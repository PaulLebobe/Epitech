/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#include "my.h"

int verif_double_name(void)
{
    int x = -1;
    int j = 0;
    char **tmp = NULL;
    int size = elem.room;
    int match = 0;

    tmp = malloc(sizeof(char *) * (size + 1));
    while (++x < size)
        tmp[x] = my_strdup(io[x].name);
    for (int i = 0; i < size; i++, match = 0, j = 0) {
        for (j = 0; tmp[j] != NULL; j++)
            if (my_strcmp(io[i].name, tmp[j]) == 0)
                match++;
        if (match > 1)
            return (84);
    }
    return (0);
}

int my_norm_tools(int i, char **tab)
{
    if (my_norm_1(i, tab) == 84)
        return (84);
    if (my_norm_2(i, tab) == 84)
        return (84);
    return (0);
}

int fuck_file(void)
{
    int i = 0;
    char **tab;

    tab = elem.file_data;
    for (i = 0; tab[i] != NULL; i++) {
        if (my_norm_tools(i, tab) == 84)
            return (84);
    }
    return (0);
}