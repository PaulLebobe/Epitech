/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** algo
*/

#include "my.h"

int is_num(char *str)
{
    int i;
    i = 0;

    while (str[i]) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
            return (0);
        ++i;
    }
    return (1);
}

int is_str_nb(char c)
{
    int i;
    i = 0;
    
    if ((c >= 'a' && c<= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int is_exist(char *str, char c)
{
    int i = -1;
    int j = 0;

    if (!*str || str == NULL)
        return (0);
    while (str[++i] != '\0') {
        if (str[i] == c)
            j++;
    }
    return (j);
}

char *room_name(char *str, char *str2, char *s)
{
    char *res1 = my_strdup(str);
    char *res2 = my_strdup(str2);

    if (my_strcmp(res1, s) == 0)
        return (res2);
    else
        return (res1);
}