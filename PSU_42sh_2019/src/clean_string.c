/*
** EPITECH PROJECT, 2020
** clean_str
** File description:
** c
*/

#include "../include/42sh.h"

static int new_str_space(char *str)
{
    int nbr_space = 0;
    int size = 0;
    int quote = 0;
    char quote_type = '\0';
    char *save_str = str_copy(str);

    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
        quote_change(&quote, str[i], quote_type);
        if ((save_str[i] == ' ' || save_str[i] == '\t') && quote == 0) {
            if (nbr_space >= 1)
                size--;
            nbr_space++;
        } else
            nbr_space = 0;
        if (str[i] == '\\')
            i++;
    }
    free(str);
    str = malloc(sizeof(char) * (my_strlen(save_str) + size));
    return (my_strlen(save_str) + size);
}

static void clean_space(char *str, char *save_str)
{
    int nbr_space = 0;
    int pos_str = 0;
    int quote = 0;
    char quote_type = '\0';
    int size = new_str_space(str);

    for (int i = 0; save_str[i] != '\0'; i++) {
        quote_change(&quote, save_str[i], quote_type);
        if ((save_str[i] == ' ' || save_str[i] == '\t') && quote == 0) {
            if (nbr_space >= 1)
                pos_str--;
            nbr_space++;
        } else
            nbr_space = 0;
        str[i + pos_str] = save_str[i];
        if (save_str[i] == '\\')
            i++;
        str[i + pos_str] = save_str[i];
    }
    str[size] = '\0';
}

static void new_str(char *str, char *save_str)
{
    int size = 0;
    int quote = 0;
    char quote_type = '\0';
    char last = '\0';

    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
        quote_change(&quote, str[i], quote_type);
        if ((str[i] == ';' || str[i] == '|'  || str[i] == '&')
            && quote == 0 && last != str[i] && last != '\\')
            size++;
        last = str[i];
    }
    free(str);
    str = malloc(sizeof(char) * (size + my_strlen(save_str)));
    str[size + my_strlen(save_str) - 1] = '\0';
    str[size + my_strlen(save_str) - 2] = '\n';
}

static void clean_string2(char *str)
{
    char *save_str = str_copy(str);
    int pos_str = 0;
    int quote = 0;
    char quote_type = '\0';
    char last = '\0';

    new_str(str, save_str);
    for (int i = 0; save_str[i] != '\n' && save_str[i] != '\0'; i++) {
        quote_change(&quote, save_str[i], quote_type);
        if ((save_str[i] == ';' || save_str[i] == '|'  || save_str[i] == '&')
            && quote == 0 && last != save_str[i] && last != '\\') {
                str[pos_str + i] = ' ';
            pos_str++;
        }
        str[pos_str + i] = save_str[i];
        last = save_str[i];
    }
}

char *clean_string(char *str)
{
    int size = 0;
    char *str_save = NULL;

    clean_string2(str);
    str_save = str_copy(str);
    clean_space(str, str_save);
    free(str_save);
    str_save = str_copy(str);
    size = my_strlen(str) - 1;
    for (size; str[size] == '\n' || str[size] == ' '; size--);
    free(str);
    str = str_ncopy(str_save, size + 1);
    str[size + 1] = '\0';
    return (str);
}