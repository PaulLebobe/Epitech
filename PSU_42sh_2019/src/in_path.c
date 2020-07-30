/*
** EPITECH PROJECT, 2020
** in var path
** File description:
** c
*/

#include "42sh.h"

char *path2(char *argv, char *path, char *file)
{
    char *real_path = string1_and_string2(path, "/");
    char *pf = "\0";

    pf = string1_and_string2(real_path, file);
    free(path);
    free(argv);
    free(real_path);
    argv = str_copy(pf);
    free(pf);
    return (argv);
}

void path_argv(char **argv, char **env, int *exec_failure)
{
    int i = -1;
    int col = 5;
    int size_path = 0;
    char *file = str_copy(argv[0]);
    char *path = "\0";

    do {
        i++;
        for (i; env[i] && my_strcmp2(env[i], "PATH=") == 0; i++);
    } while (env[i] && env[i][0] != 'P');
    do {
        for (size_path = 0; env[i][col + size_path]
            && env[i][col + size_path] != ':'; size_path++);
        path = str_adopte(&env[i][col], size_path);
        argv[0] = path2(argv[0], path, file);
        col += size_path + 1;
        exec(argv, env, exec_failure);
    } while (env[i] && env[i][col] && *exec_failure != 0);
    free(argv[0]);
    argv[0] = str_copy(file);
}