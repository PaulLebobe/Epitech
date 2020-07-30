/*
** EPITECH PROJECT, 2020
** create_argv
** File description:
** c
*/

#include "42sh.h"

int quote_val(int quote)
{
    if (quote)
        quote = 0;
    else if (quote  == 0)
        quote = 1;
    return (quote);
}

void create_argv2(char **dep, int *star, char *str, int *i)
{
    int car = 0;
    int quote = 0;

    for (i; (str[*i] != ' ' || quote == 1) &&
        str[*i] && str[*i] != '\n'; *i += 1) {
        if (str[*i] == '"') {
            quote = quote_val(quote);
        } else {
            dep[*star] = my_realloc_char_star(dep[*star], car + 1);
            dep[*star][car] = str[*i];
            car++;
        }
        dep[*star][car] = '\0';
    }
    if (str[*i])
        *i += 1;
    *star += 1;
}

char **create_argv(char *str)
{
    int i = 0;
    char **dep;
    int star = 0;
    int quote = 0;

    for (i = 0; str[i]; i++) {
        if (str[i] == ' ' && quote == 0)
            star++;
        if (str[i] == '"')
            quote = quote_val(quote);
    }
    i = 0;
    dep = malloc(sizeof(char *) * (star + 2));
    star = 0;
    while (str[i] && str[i] != '\n') {
        dep[star] = malloc(sizeof(char) * 2);
        create_argv2(dep, &star, str, &i);
    }
    dep[star] = NULL;
    return (dep);
}