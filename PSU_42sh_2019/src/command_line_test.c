/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** command_line_test
*/

#include "../include/42sh.h"

int test_symb2(char *symb, char *word,
int *write_redirection, int *read_redirection)
{
    if (word == NULL && is_equal(symb, ";") == 0) {
        write(2, "Invalid null command.\n", 22);
        free(symb);
        return (84);
    }
    if (symb != NULL && (is_equal(symb, "|") || is_equal(symb, "||") ||
        is_equal(symb, "&&") || is_equal(symb, ";"))) {
        *read_redirection = 0;
        *write_redirection =  0;
        free (symb);
        symb = NULL;
    }
    if (symb != NULL) {
        write(2, "Invalid null command.\n", 22);
        free(symb);
        return (84);
    }
    return (0);
}

int test_symb(char *symb, char *word,
int *write_redirection, int *read_redirection)
{
    if (symb != NULL && (is_equal(symb, ">") || is_equal(symb, ">>"))) {
        if (word == NULL) {
            write(2, "Missing name for redirect.\n", 27);
            return (84);
        }
        *write_redirection += 1;
        free(symb);
        symb = NULL;
    }
    if (symb != NULL && (is_equal(symb, "<") || is_equal(symb, "<<"))) {
        if (word == NULL) {
            write(2, "Missing name for redirect.\n", 27);
            return (84);
        }
        *read_redirection += 1;
        free(symb);
        symb = NULL;
    }
    return (test_symb2(symb, word, write_redirection, read_redirection));
}

int moretest(char *str, char *word,
int *write_redirection, int *read_redirection)
{
    if (*read_redirection > 1 || *write_redirection > 1) {
        write (2, "Ambiguous output redirect.\n", 27);
        return (84);
    }
    return (0);
}

int test_commande_line(char *str)
{
    int i = 0;
    int write_redirection = 0;
    int read_redirection = 0;
    int size_word = 0;
    char *word = NULL;
    char *symb = NULL;

    for (i = 0; str != NULL && str[i] != '\0' && str[i] != '\n'; i++) {
        symb = symbol(&str[i]);
        word = first_word(&str[i], &size_word);
        if (test_symb(symb, word, &write_redirection, &read_redirection) != 0 ||
            moretest(&str[i], word, &write_redirection, &read_redirection) != 0)
            return (84);
        if (size_word > 0 && word == NULL)
            return (84);
        i += size_word;
        if (word != NULL)
            free(word);
    }
    return (0);
}