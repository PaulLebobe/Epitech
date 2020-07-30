/*
** EPITECH PROJECT, 2020
** exit_test
** File description:
** c
*/

#include "42sh.h"

int test(char **argv, char **envpaht)
{
    int exec_failure = 1;
    int w = 0;

    if (is_equal(argv[0], "exit") && exec_failure) {
        my_putstring("exit", 1);
        if (argv[1] != NULL)
            exit(84);
        exit(0);
    } else {
        if (exec(argv, envpaht, &exec_failure) != 0) {
            path_argv(argv, envpaht, &exec_failure);
        }
    }
    return (exec_failure);
}