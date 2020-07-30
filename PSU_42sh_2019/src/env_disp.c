/*
** EPITECH PROJECT, 2020
** env_disp.c
** File description:
** c
*/

#include "42sh.h"

void env_disp(char **env)
{
    for (int i = 0; env[i]; i++)
        my_putstring(env[i], 1);
}