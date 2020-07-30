/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#include "my.h"

int my_tab_size(char **str)
{
    int i = 0;

    while (str[i] != NULL)
        i = i + 1;
    return (i);
}

char **my_reverse_tab(char **tab)
{
    int i = -1;
    int size = my_tab_size(tab);
    int y = size - 1;
    char **array;

    array = malloc(sizeof(char *) * (size + 1));
    while (++i < size) {
        array[y] = tab[i];
        y--;
    }
    return (array);
}

char *malloc_str(char *str, char *str2)
{
    int i = -1;
    int y = -1;
    int size1 = my_strlen(str);
    int size2 = my_strlen(str2);
    int t_size = size1 + size2;
    char *dest = malloc(sizeof(char *) * (t_size + 1));

    while (++i < size1)
        dest[i] = str[i];
    while (i < t_size) {
        dest[i] = str2[++y];
        i++;
    }
    return (dest);
}

char **rm_nslash(char **tab)
{
    int i = 0;
    int j = 0;

    while (tab[i] != NULL) {
        while (tab[i][j] != '\0') {
            if (tab[i][j] == '\n')
                tab[i][j] = '\0';
            j++;
        }
        i++;
        j = 0;
    }
    return (tab);
}

