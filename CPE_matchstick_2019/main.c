/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** main
*/

#include "my.h"

char **make_t(int lines)
{
    int base = lines * 2 - 1;
    char **tree = malloc(sizeof(char *) * (lines + 3));

    for (int i = 0; i != lines + 2; i++)
        tree[i] = malloc(sizeof(char) * base + 3);
    for (int i = 0; i != base + 2; i++){
        tree[0][i] = '*';
        tree[lines + 1][i] = '*';
        tree[0][i + 1] = '\n';
        tree[lines + 1][i + 1] = '\n';
    }
    for (int i = 1; i <= lines; i++) {
        tree[i][0] = '*';
        tree[i][base + 1] = '*';
        tree[i][base + 2] = '\n';
        for (int e = 1; e <= base; e++)
            tree[i][e] = (e < (base + 2) / 2 - i + 1 ||
            e > (base + 2) / 2 + i - 1) ? ' ' : '|';
    }
    return (tree);
}

void tree_print(char **tree)
{
    for (int i = 0; tree[i]; i++)
        my_putstr(tree[i]);
}

int is_nb(char *buff)
{
    int x = 1;

    for (int i = 0; buff[i]; i++)
        if ((buff[i] < '0' || buff[i] > '9') && buff[i] != '\n') {
            my_putstr("Error: invalid input (positive number expected)\n");
            x = 0;
            break;
        }
    return (x);
}

int main(int ac, char **av)
{
    int lines;
    int max;
    int nb[4];
    char **tree;

    if (ac != 3)
        return (84);
    lines = my_getnbr(av[1]);
    max = my_getnbr(av[2]);
    for (int i = 0; av[1][i]; i++)
        if (av[1][i] < '0' || av[1][i] > '9' || lines < 2 || lines > 99)
            return (84);
    for (int i = 0; av[2][i]; i++)
        if (av[2][i] < '0' && av[1][i] > '9' || max == 0)
            return (84);
    tree = make_t(lines);
    return (game(tree, lines, max, nb));
}