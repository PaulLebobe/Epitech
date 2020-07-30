/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#include "my.h"

char **str_to_word_tab(char *buff, char c)
{
    char **str;
    int i = 0;
    int j = 0;

    for (; buff && buff[j]; j++)
    if (buff[j] == c)
            i++;
    str = malloc(sizeof(char *) * (i + 4));
    for (i = 0; buff && *buff; i++) {
        for (j = 0; buff[j] && buff[j] != c; j++);
        str[i] = malloc(sizeof(char) * (j + 1));
        for (j = 0; *buff && *buff != c; buff++)
            str[i][j++] = *buff;
        str[i][j] = '\0';
        buff = *buff ? buff + 1 : buff;
    }
    str[i] = NULL;
    return (str);
}