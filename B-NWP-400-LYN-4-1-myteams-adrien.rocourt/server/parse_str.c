/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** parse_str
*/

#include "my.h"

char *parse_str_login(char *str)
{
    char *str_final = malloc(sizeof(char) *strlen(str));
    int j = 0;
    int len = strlen(str);

    for (int i = 1; i <= len - 3; i++) {
        str_final[j] = str[i];
        j++;
    }
    str_final[j] = "\0";
    return str_final;
}