/*
** EPITECH PROJECT, 2020
** Navi
** File description:
** Battle
*/

#include "my.h"

int check(char **map, char **map2)
{
    int test = 2;
    int cpt = 0;

    for (int i = 0; map[i] != NULL; i++)
        for (int e = 0; map[i][e]; e++)
            cpt = (map[i][e] == 'x') ? cpt + 1 : cpt;
    if (cpt == 14) {
        final_print(map, map2, 1);
        return (1);
    }
    cpt = 0;
    for (int i = 0; map2[i] != NULL; i++)
        for (int e = 0; map2[i][e]; e++)
            cpt = (map2[i][e] == 'x') ? cpt + 1 : cpt;
    if (cpt == 14) {
        final_print(map, map2, 0);
        return (0);
    }
    return (2);
}

int main2(char **map, char **map2)
{
    mess *p = &io;
    struct sigaction act;
    int ch = 2;

    my_putstr("\nwaiting for enemy connection...\n");
    while (p->status == 0) {
        act.sa_sigaction = &f_pid;
        act.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR1, &act, NULL);
    }
    while (ch == 2) {
        init();
        map2 = game(map, map2);
        ch = check(map, map2);
        init();
        map = (ch == 2) ? game_pass(map, map2) : map;
        ch = (ch == 2) ? check(map, map2) : ch;
    }
    return (ch);
}

int main3(char **map, char **map2, char **av)
{
    mess *p = &io;
    int ch = 2;

    p->pid = my_getnbr(av[1]);
    if (kill(p->pid, SIGUSR1) == -1)
        return (84);
    my_putstr("\nsuccessfully connected\n");
    while (ch == 2) {
        init();
        map = game_pass(map, map2);
        ch = check(map, map2);
        init();
        if (ch == 2) {
            map2 = game(map, map2);
            ch = check(map, map2);
        }
    }
    return (ch);
}

int main(int ac, char **av)
{
    char *buff;
    char **map;
    char **map2;
    pid_t id = getpid();
    int test = file_check(ac, av);

    if (test == 84)
        return (84);
    buff = fill_buff(ac, av, buff);
    map = fill_map(buff, 1);
    map2 = fill_map(buff, 0);
    if (check_buff(buff) == 84)
        return (84);
    my_putstr("my_pid: ");
    my_putnbr(id);
    if (ac == 2)
        return (main2(map, map2));
    if (ac == 3)
        return (main3(map, map2, av));
}

char *my_input(char *buff2, char **map2)
{
    int buff_size = 3;
    int offset = 0;
    int len;
    int temp = 0;

    buff2 = malloc(sizeof(char) * 3);
    while (((len = read(0, buff2 + offset, buff_size - offset))
    > 0) && buff2[0] != '\n' && buff2[1] != '\n')
        offset = offset + len;
    if ((buff2[0] > 'H' || buff2[0] < 'A' || buff2[1] > '8' || buff2[1] < '1'
    || buff2[2] != '\n') || map2[buff2[1] - 47][(buff2[0] - 64) * 2] == 'x' ||
    map2[buff2[1] - 47][(buff2[0] - 64) * 2] == 'o') {
        my_putstr("wrong position\nattack: ");
        buff2 = my_input(buff2, map2);
    }
    buff2[2] = '\0';
    return (buff2);
}