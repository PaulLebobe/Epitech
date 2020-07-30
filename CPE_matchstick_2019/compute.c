/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** main
*/

#include "my.h"

void comput_print(int *nb)
{
    my_putstr("\nAI's turn...\nAI removed ");
    my_putnbr(nb[1]);
    my_putstr(" match(es) from line ");
    my_putnbr(nb[0]);
    my_putchar('\n');
}

int *compute3(int *tot, char **tree, int e)
{
    for (int w = 0; tree[e][w]; w++) {
        if (tree[e][w] == '|') {
            tot[0]++;
            if (tot[1] != e) {
                tot[1] = e;
                tot[2]++;
            }
        }
    }
    return (tot);
}

int *compute4(char **tree, int *tot, int *nb)
{
    int l1 = 0;
    int tl1 = 0;
    int l2 = 0;
    int tl2 = 0;

    for (int e = 0; tree[e]; e++)
        for (int x = 0; tree[e][x]; x++) {
            if (tree[e][x] == '|' && (l1 == 0 || l1 == e)) {
                tl1++;
                l1 = e;
            }   else if (tree[e][x] == '|' && (l2 == 0 || l2 == e)) {
                tl2++;
                l2 = e;
            }
        }
    nb[0] = (tl1 == 1) ? l2 : nb[0];
    nb[1] = (tl1 == 1) ? tl2 : nb[1];
    nb[0] = (tl2 == 1) ? l1 : nb[0];
    nb[1] = (tl2 == 1) ? tl1 : nb[1];
    return (nb);
}

int *comput2(int *nb, int max, char **tree)
{
    int *tot = malloc(sizeof(int) * 10);

    for (int e = 0; tree[e]; e++)
        tot = compute3(tot, tree, e);
    if (tot[2] == 1 && tot[0] < max + 2 && tot[0] > 1)
        nb[1] = tot[0] - 1;
    if (tot[2] == 2 && tot[0] < max + 2)
        nb = compute4(tree, tot, nb);
    return (nb);
}

int *comput(int lines, int max, int *nb, char **tree)
{
    int x = 0;
    int temp;

    while (x == 0){
        nb[0] = rand_inter(1, lines + 1);
        nb[1] = rand_inter(1, max);
        nb = comput2(nb, max, tree);
        temp = 0;
        for (int i = my_strlen(tree[nb[0]]); i > 0; i--) {
            if (tree[nb[0]][i] == '|')
            temp++;
        }
        if (temp >= nb[1])
            x = 1;
    }
    comput_print(nb);
    return (nb);
}