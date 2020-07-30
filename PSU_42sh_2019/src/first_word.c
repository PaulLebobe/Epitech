/*
** EPITECH PROJECT, 2020
** redirections
** File description:
** first_word
*/

#include "../include/42sh.h"

char quote_change(int *quote, char carac, char quote_type)
{
    if (*quote == 0 && (carac == '\'' || carac == '"')) {
        *quote = 1;
        return (carac);
    }
    if (*quote == 1 && carac == quote_type) {
        *quote = 0;
        return ('\0');
    }
    return (quote_type);
}

static int size_first_word(char *str, int quote, char quote_type, int *size)
{
    int size_word = 0;
    int old_quote = quote;

    for (*size = 0; str != NULL && str[*size] != '\0' && str[*size] != '\n' &&
        ((str[*size] != ';' && str[*size] != '&' && str[*size] != '|'
        && str[*size] != '<' && str[*size] != '>' && str[*size] != ' ')
        || quote == 1); *size += 1) {
        old_quote = quote;
        quote_type = quote_change(&quote, str[*size], quote_type);
        if (str[*size] == '\\' && quote == 0)
            *size += 1;
        if (old_quote == quote && str[*size] != '\0' && str[*size] != '\n')
            size_word++;
    }
    if (quote == 0)
        return (size_word);
    write (2, "Unmatched '", 11);
    write (2, &quote_type, 1);
    write (2, "'.\n", 3);
    return (0);
}

static void create_first_word(char *str, int quote, int quote_type, char *word)
{
    int old_quote = quote;
    int size_word = 0;

    for (int i = 0; str != NULL && str[i] != '\0' && str[i] != '\n' &&
        (( str[i] != ';' && str[i] != '&' && str[i] != '|' && str[i] != '<' &&
        str[i] != '>' && str[i] != ' ') || quote == 1); i++) {
        old_quote = quote;
        quote_type = quote_change(&quote, str[i], quote_type);
        if (str[i] == '\\' && quote == 0)
            i++;
        if (old_quote == quote && str[i] != '\0' && str[i] != '\n') {
            word[size_word] = str[i];
            size_word++;
        }
    }
}

char *first_word(char *str, int *size)
{
    int quote = 0;
    char quote_type = '\0';
    int size_word = 0;
    char *word = NULL;
    int i = 0;

    *size = 0;
    for (i = 0; (str != NULL && str[i] != '\0' && str[i] != '\n') &&
        (str[i] == ';' || str[i] == '&' || str[i] == '|' || str[i] == '<'
        || str[i] == '>' || str[i] == ' ') && quote == 0; i++) {
        quote_type = quote_change(&quote, str[i], quote_type);
    }
    size_word = size_first_word(&str[i], quote, quote_type, size);
    if (size_word == 0)
        return (NULL);
    *size += i - 1;
    word = malloc(sizeof(char) * size_word + 1);
    word[size_word] = '\0';
    create_first_word(&str[i], quote, quote_type, word);
    return (word);
}