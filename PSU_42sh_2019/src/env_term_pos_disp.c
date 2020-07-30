/*
** EPITECH PROJECT, 2020
** env
** File description:
** c
*/

#include "42sh.h"

void env_term_pos_disp(char **env)
{
    int pos = 0;
    int in_str = 0;

    for (pos = 0; env[pos] != NULL && my_strcmp(env[pos], "PWD") == 0; pos++);
    for (in_str = 0; env[pos][in_str] != '=' && env[pos][in_str]; in_str++);
    for (in_str++; env[pos][in_str]; in_str++)
        write(1, &env[pos][in_str], 1);
}