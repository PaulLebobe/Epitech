/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** symbol
*/

#include "../include/42sh.h"

void create_symbol(char *str, char *symb)
{
    int word = 0;

    for (int i = 0; str != NULL && str[i] != '\0' && str[i] != '\n' &&
        (str[i] == ';' || str[i] == '&' || str[i] == '|' ||
        str[i] == '<' || str[i] == '>' || (str[i] == ' ' && word == 0)); i++) {
        if (str[i] == ';' || str[i] == '&' || str[i] == '|' ||
        str[i] == '<' || str[i] == '>') {
            symb[word] = str[i];
            word++;
        }
    }
}

char *symbol(char *str)
{
    char *symb = NULL;
    int i = 0;
    int word = 0;

    for (i = 0; str != NULL && str[i] != '\0' && str[i] != '\n' &&
        (str[i] == ';' || str[i] == '&' || str[i] == '|' ||
        str[i] == '<' || str[i] == '>' || (str[i] == ' ' && word == 0)); i++) {
        if (str[i] == ';' || str[i] == '&' || str[i] == '|' ||
        str[i] == '<' || str[i] == '>')
            word++;
    }
    if (word == 0)
        return (NULL);
    symb = malloc(sizeof(char) * (word + 1));
    symb[word] = '\0';
    create_symbol(str, symb);
    return (symb);
}