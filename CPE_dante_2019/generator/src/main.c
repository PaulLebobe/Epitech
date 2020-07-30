/*
** EPITECH PROJECT, 2020
** src
** File description:
** main
*/

#include "../include/generate.h"

int check(int argc, char **argv)
{
    for (int i = 0; argv[1][i]; i++)
        if (argv[1][i] < '0' || argv[1][i] > '9')
            return (84);
    for (int i = 0; argv[2][i]; i++)
        if (argv[2][i] < '0' || argv[2][i] > '9')
            return (84);
    if (argc == 4)
        if (is_equal_no_cass(argv[3], "perfect") != 1)
            return (84);
    return (0);
}

char **create_laby(int x, int y)
{
    char **laby = malloc(sizeof(char *) * (y + 1));

    laby[y] = NULL;
    for (int i = 0; i < y; i++) {
        laby[i] = malloc(sizeof(char) * (x + 1));
        for (int wall = 0; wall < x; wall++)
            laby[i][wall] = 'X';
        laby[i][x] = '\0';
    }
    laby[0][0] = '*';
    return (laby);
}

void display_laby(char **laby)
{
    for (int i = 0; laby[i] != NULL; i++) {
        if (laby[i + 1] != NULL)
            printf("%s\n", laby[i]);
        else
            printf("%s", laby[i]);
    }
}

int main(int argc, char **argv)
{
    char **laby = NULL;
    int y = 0;
    int x = 0;

    srand(time(NULL));
    if (argc < 3 || argc > 4)
        return (84);
    if (check(argc, argv) == 84)
        return (84);
    y = atoi(argv[2]);
    x = atoi(argv[1]);
    laby = create_laby(x, y);
    dig_rec(laby);
    if (argc == 3)
        imperfect(laby);
    display_laby(laby);
}