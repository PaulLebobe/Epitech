/*
** EPITECH PROJECT, 2020
** is_equal str1 = str2?
** File description:
** c
*/

#include "include_lib/include_lib.h"

int is_equal(char *str1, char *str2)
{
    int i = 0;

    for (i = 0; str1[i] && str2[i]; i++) {
        if (str1[i] != str2[i])
            return (0);
    }
    if (str1[i] == '\0' && str2[i] == '\0')
        return (1);
    return (0);
}

int test_cass(char carac1, char carac2)
{
    if (carac1 == carac2)
        return (1);
    if (carac1 >= 'a' && carac1 <= 'z') {
        if (carac1 - 'a' + 'A' == carac2)
            return (1);
    }
    if (carac1 >= 'A' && carac1 <= 'Z') {
        if (carac1 - 'A' + 'a' == carac2)
            return (1);
    }
    return (0);
}

int is_equal_no_cass(char *str1, char *str2)
{
    int i = 0;

    for (i = 0; str1[i] && str2[i]; i++) {
        if (test_cass(str1[i], str2[i]) == 0)
            return (0);
    }
    if (str1[i] == '\0' && str2[i] == '\0')
        return (1);
    return (0);
}