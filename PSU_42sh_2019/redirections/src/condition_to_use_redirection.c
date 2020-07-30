/*
** EPITECH PROJECT, 2020
** redirections
** File description:
** condition_to_use_redirection
*/

#include "../include/redirections.h"

int write_redirection(char *str)
{
    int size = 0;
    char *word = first_word(str, &size);
    char *symb = symbol(str);

    if (symb != NULL && symb[0] == '>') {
        if (word == NULL) {
            write(2, "Missing name for redirect.\n", 27);
            return (-84);
        } else if (symb[1] == '>') {
            return (write_redirection2(word));
        }
        return (write_redirection1(word));
    }
    return (1);
}

int read_redirection(char *str)
{
    int size = 0;
    char *word = first_word(str, &size);
    char *symb = symbol(str);

    if (symb != NULL && symb[0] == '<') {
        if (word == NULL) {
            write(2, "Missing name for redirect.\n", 27);
            return (-84);
        } else if (symb[1] == '<') {
            return (read_redirection2(word));
        }
        return (read_redirection1(word));
    }
    return (0);
}

void redirection(int *fd_0, int *fd_1, int size, char *str)
{
    int size_word = 0;
    char *word = NULL;
    for (int i = 0; i < size; i++) {
        if (*fd_0 == 0)
            *fd_0 = read_redirection(&str[i]);
        if (*fd_1 == 1)
            *fd_1 = write_redirection(&str[i]);
        word = first_word(&str[i], &size_word);
        if (word)
            free(word);
        i += size_word;
    }
}