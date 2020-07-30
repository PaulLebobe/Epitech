/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** main
*/

#include "my.h"

int my_input4(int temp, int *nb, int max)
{
    temp = (nb[4] == 0) ? 0 : temp;
    if (nb[4] != 0) {
        if (nb[1] > max){
            temp = 0;
            my_putstr("Error: you cannot remove more than ");
            my_putnbr(max);
            my_putstr(" matches per turn\n");
        } else if (temp < nb[1]) {
            temp = 0;
            my_putstr("Error: not enough matches on this line\n");
        }
        if (nb[1] == 0){
            temp = 0;
            my_putstr("Error: you have to remove at least one match\n");
        }
    }
    return (temp);
}

int *my_input3(int *nb, size_t test)
{
    char buff2[32];
    char *b2 = buff2;
    size_t bufsize2 = 32;

        my_putstr("Matches: ");
        test = getline(&b2, &bufsize2, stdin);
        if (test == -1){
            nb[3] = -1;
            return (nb);
        }
        nb[1] = my_getnbr(buff2);
        nb[4] = is_nb(buff2);
    return (nb);
}

int *my_input2(int *nb, size_t test, int lines)
{
    size_t bufsize = 32;
    char buff[32];
    char *b = buff;
    int x = 0;

    while (x == 0) {
        my_putstr("Line: ");
        test = getline(&b, &bufsize, stdin);
        if (test == -1){
            nb[3] = -1;
            return (nb);
        }
        nb[0] = my_getnbr(buff);
        x = is_nb(buff);
        if ((nb[0] > lines || nb[0] < 1) && x == 1) {
            my_putstr("Error: this line is out of range\n");
            x = 0;
        }
    }
    return (nb);
}

void input_print(int *nb)
{
    my_putstr("Player removed ");
    my_putnbr(nb[1]);
    my_putstr(" match(es) from line ");
    my_putnbr(nb[0]);
    my_putchar('\n');
}

int *my_input(int lines, int max, int *nb, char **tree)
{
    size_t test = 0;
    int temp = 0;

    while (temp == 0) {
        nb = my_input2(nb, test, lines);
        if (nb[3] == -1)
            return (nb);
        nb = my_input3(nb, test);
        if (nb[3] == -1)
            return (nb);
        for (int i = my_strlen(tree[nb[0]]); i > 0; i--) {
            if (tree[nb[0]][i] == '|')
            temp++;
        }
        temp = my_input4(temp, nb, max);
    }
    input_print(nb);
    return (nb);
}