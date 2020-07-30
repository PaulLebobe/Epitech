/*
** EPITECH PROJECT, 2020
** two_string_in_one
** File description:
** c
*/

#include "include_lib/include_lib.h"

char *string1_and_string2(char const *string1, char *string2)
{
    int size = 0;
    char *string1_string2;

    for (size = 0; string2[size] != '\0'; size++);
    for (int i = 0; string1[i] != '\0'; i++)
        size++;
    string1_string2 = malloc(sizeof(char) * (size + 1));
    for (size = 0; string1[size] != '\0'; size++) {
        string1_string2[size] = string1[size];
        string1_string2[size + 1] = '\0';
    }
    for (int i = 0; string2[i] != '\0'; i++) {
        string1_string2[size] = string2[i];
        size++;
    }
    string1_string2[size] = '\0';
    return (string1_string2);
}