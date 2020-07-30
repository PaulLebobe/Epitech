/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** new_create_argv
*/

#include "../include/42sh.h"

static int end_test(int *end, char *symb, int *size, int next_size)
{
    if (symb != NULL && (is_equal(symb, ";") || is_equal(symb, "&&") ||
        is_equal(symb, "|") || is_equal(symb, "||"))) {
        *end = 1;
        *size -= next_size;
        return (1);
    }
    return (0);
}

int size_argc(int *size_argv, char *str)
{
    char *symb = NULL;
    char *word = NULL;
    int end = 0;
    int argc = 0;
    int size_word = 0;

    for (*size_argv = 0, argc = 0; str != NULL && str[*size_argv] != '\n' &&
        str[*size_argv] != '\0' && end == 0; argc++, *size_argv += 1) {
        symb = symbol(&str[*size_argv]);
        word = first_word(&str[*size_argv], &size_word);
        if (is_equal(symb, ">") || is_equal(symb, ">>") ||
            is_equal(symb, "<") || is_equal(symb, "<<"))
            argc--;
        argc -= end_test(&end, symb, size_argv, size_word);
        *size_argv += size_word;
        free(word);
        free(symb);
    }
    return (argc);
}

void write_argv(char *str, char **argv)
{
    int argc = 0;
    char *symb = NULL;
    char *word = NULL;
    int end = 0;
    int size_word = 0;

    for (int size = 0; str != NULL && str[size] != '\n' && str[size]
        != '\0' && end == 0; size += 1) {
        symb = symbol(&str[size]);
        word = first_word(&str[size], &size_word);
        if (symb == NULL) {
            argv[argc] = str_copy(word);
            argc++;
        }
        size += size_word;
        end_test(&end, symb, &size, size_word);
        free(symb);
        free(word);
    }
}

char **new_create_argv(char *str, int *size_argv)
{
    char **argv = NULL;
    int argc = 0;
    char *symb = NULL;
    char *word = NULL;
    int size_word = 0;
    int end = 0;

    argc = size_argc(size_argv, str);
    if (argc == 0)
        return (NULL);
    argv = malloc(sizeof(char *) * (argc + 1));
    argv[argc] = NULL;
    write_argv(str, argv);
    return (argv);
}