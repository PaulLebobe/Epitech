/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** count equal first char
*/

#include "my.h"
#include <stdlib.h>

char *check_zero(char *str)
{
    int read = 0;
    int y = 0;
    char *temp = my_malloc(my_strlen(str) + 1);

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] != '0' && str[i + 1] == '\0' && read == 0)
            read = 2;
        read = (str[i] != '0') ? 1 : 0;
    }
    if (read == 2)
        return "0";
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '0' || read == 1) {
            read = 1;
            temp[y] = str[i];
            y++;
        }
    }
    return (temp);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    s1 = (s1[0] == '_') ? s1 + 1 : s1;
    s2 = (s2[0] == '_') ? s2 + 1 : s2;
    s1 = removespace(s1);
    s2 = removespace(s2);
    s1 = check_zero(s1);
    s2 = check_zero(s2);
    if (my_strlen(s1) < my_strlen(s2))
        return -1;
    if (my_strlen(s1) > my_strlen(s2))
        return 1;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    return (s1[i] - s2[i]);
}
