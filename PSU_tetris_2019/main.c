/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** main
*/

#include "my.h"

long f_size(const char *filename)
{
    struct stat s;

    if (stat(filename, &s) != 0)
        exit(84);
    return s.st_size;
}

void mk_map(void)
{
    elem.map = malloc(sizeof(char *) * (opt.row + 20));
    for (int i = 0; i < opt.row + 1; i++) {
        elem.map[i] = malloc(sizeof(char) * (opt.col * 2 + 80));
        for (int e = 0; e < 60 + 2 * opt.col; e++) {
            if (e < 30)
                elem.map[i][e] = ' ';
            if ((i == 0 || i == opt.row) && (e == 30 || e == 30 + 2 * opt.col))
                elem.map[i][e] = '+';
            if ((i == 0 || i == opt.row) && e > 30 && e < 30 + 2 * opt.col)
                elem.map[i][e] = '-';
            if (i > 0 && i < opt.row && (e == 30 || e == 30 + 2 * opt.col))
                elem.map[i][e] = '|';
            if (i > 0 && i < opt.row && e > 30 && e != 30 + 2 * opt.col &&
            e < 60 + 2 * opt.col)
                elem.map[i][e] = ' ';
            if (e == e < 59 + 2 * opt.col)
                    elem.map[i][e] = '\n';
        }
    }
}

void argums2(int ac, char **av, char ch)
{
    if (ch == 'L')
        opt.level = my_getnbr(optarg);
    if (ch == 'l')
        opt.left = to_ascii(optarg[0]);
    if (ch == 'r')
        opt.right = to_ascii(optarg[0]);
    if (ch == 't')
        opt.turn = to_ascii(optarg[0]);
    if (ch == 'd')
        opt.drop = to_ascii(optarg[0]);
    if (ch == 'q')
        opt.quit = to_ascii(optarg[0]);
    if (ch == 'p')
        opt.pause = to_ascii(optarg[0]);
    if (ch == 'w')
        opt.next = "No";
    if (ch == 'm')
        resize(optarg);
}

void argums(int ac, char **av)
{
    char ch;
    int option_index = 0;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-' && av[i][1] == 'D' && av[i][2] == '\0')
            opt.dbg = 1;
        if (my_strcmp(av[i], "--debug") == 0)
            opt.dbg = 1;
    }
    while ((ch = getopt_long(ac, av, "L:l:r:t:d:q:p:w:m",
    long_options, &option_index)) != -1) {
        argums2(ac, av, ch);
    }
}

int main(int ac, char **av)
{
    init();
    if (ac != 1 && av[1][0] != '-')
        return (84);
    argums(ac, av);
    if (fill_tetriminos() == 84)
        return (84);
    elem.nb = 0;
    opt.col++;
    mk_map();
    elem.next = rand_inter(0, elem.max);
    game();
}