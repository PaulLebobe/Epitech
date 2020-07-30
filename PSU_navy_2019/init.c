/*
** EPITECH PROJECT, 2020
** Navi
** File description:
** Init
*/

#include "my.h"

void f_pid(int sig, siginfo_t *siginfo, void *context)
{
    mess *p = &io;
    p->pid = siginfo->si_pid;
    my_putstr("\nenemy connected\n");
    p->status = 1;
}

void init(void)
{
    mess *p = &io;

    p->status = 0;
    p->cd = 0;
    p->cd2 = 0;
}

int file_check(int ac, char **av)
{
    FILE *fd;

    if (ac != 2 && ac != 3)
        return (84);
    if (ac == 2)
        fd = fopen(av[1], "r");
    if (ac == 3)
        fd = fopen(av[2], "r");
    if (ac == 3)
        for (int i = 0; av[1][i]; i++)
            if (av[1][i] > '9' || av[1][i] < '0')
                return (84);
    if (fd == NULL)
        return (84);
    return (0);
}