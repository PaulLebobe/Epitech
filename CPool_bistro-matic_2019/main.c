/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** calcul
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

static char  *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX);
        exit(84);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR);
        exit(84);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR);
        exit(84);
    }
    expr[size] = 0;
    return (expr);
}

void check_nbr(char **av, char *expr)
{
    int temp;

    for (int i = 0; expr[i] != '\0'; i++) {
        temp = 0;
        for (int e = 0; av[1][e] != '\0'; e++) {
            if (av[1][e] == expr[i])
                temp = 1;
        }
        for (int e = 0; av[2][e] != '\0'; e++) {
            if (av[2][e] == expr[i])
                temp = 1;
        }
        if (expr[i] == ' ')
            temp = 1;
        if (temp == 0) {
            my_putstr(SYNTAX);
            exit(84);
        }
    }
}

void check_base(char **av, char *expr)
{
    for (int i = 0; av[1][i] != '\0'; i++) {
        for (int e = 0; av[2][e] != '\0'; e++) {
            if (av[1][i] == av[2][e]) {
                my_putstr(SYNTAX);
                exit(84);
            }
        }
    }
    for (int i = 0; expr[i] != '\0'; i++) {
        if ((expr[i] == av[2][2] || expr[i] == av[2][3] || expr[i] == av[2][4]
        || expr[i] == av[2][5] || expr[i] == av[2][6]) && (expr[i + 1] == av[
        2][4] || expr[i + 1] == av[2][5] || expr[i + 1] == av[2][6])) {
            my_putstr(SYNTAX);
            exit(84);
        }
    }
}

void check_parentheses(char **av, char *expr)
{
    int nb1 = 0;
    int nb2 = 0;
    int temp = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == av[2][0]) {
            nb1 += 1;
            temp = 1;
        }
        if (expr[i] == av[2][1]) {
            nb2 += 1;
            temp = 2;
        }
    }
    if (nb1 != nb2 || temp == 1) {
        my_putstr(SYNTAX);
        exit(84);
    }
}

int main(int ac, char **av)
{
    unsigned int size = my_getnbr(av[3]);
    char *expr;

    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        return (84);
    }
    if (error(av) == 1) {
        my_putstr(SYNTAX);
        return (84);
    }
    expr = get_expr(size);
    check_parentheses(av, expr);
    check_base(av, expr);
    check_nbr(av, expr);
    my_putstr(eval_expr(expr, av[1], av[2]));
    return (0);
}
