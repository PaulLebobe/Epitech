/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** main
*/

#include "my.h"

char **modif(int *nb, char **tree)
{
    int temp = 0;

    for (int i = my_strlen(tree[nb[0]]); i > 0 && temp < nb[1]; i--){
        if (tree[nb[0]][i] == '|') {
            tree[nb[0]][i] = ' ';
            temp++;
        }
    }
    return (tree);
}

int game3(char **tree, int turn)
{
    tree_print(tree);
    if (turn == 0) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    else {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
}

int game2(char **tree, int*nb, int i)
{
        for (int e = 1; tree[e]; e++)
            for (int x = 1; tree[e][x]; x++)
                i = (tree[e][x] == '|') ? i + 1 : i;
        return (i);
}

int game(char **tree, int lines, int max, int *nb)
{
    int i = 1;
    int turn = 0;

    while (i > 0) {
        i = 0;
        tree_print(tree);
        if (turn == 0) {
            my_putstr("\nYour turn:\n");
            nb = my_input(lines, max, nb, tree);
            if (nb[3] == -1)
                return (0);
            turn = 1;
        }   else {
            nb = comput(lines, max, nb, tree);
            turn = 0;
        }
        tree = modif(nb, tree);
        i = game2(tree, nb, i);
    }
    game3(tree, turn);
}