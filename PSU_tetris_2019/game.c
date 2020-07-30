/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game
*/

#include "my.h"

void erase_p(void)
{
    for (int y = 0; io[elem.nb].piece[y] != NULL; y++)
        for (int x = 0; io[elem.nb].piece[y][x]; x++)
            elem.map[y + elem.y][x + elem.x] = (io[elem.nb]
            .piece[y][x] > '0' && io[elem.nb]
            .piece[y][x] <= '9') ? ' ' :
            elem.map[y + elem.y][x + elem.x];
}

void new_fall(void)
{
    check_stop();
    if (elem.y + io[elem.nb].height >= opt.row) {
        act.new = 0;
    }
    if (act.new == 0) {
        check_over();
        check_line();
        elem.nb = (elem.start == 0) ? -1 : elem.nb;
        elem.start = 1;
        act.new = 1;
        elem.y = 0;
        elem.nb = elem.next;
        elem.next = rand_inter(0, elem.max);
        io[elem.nb + 1].piece == NULL ? 0 : elem.nb + 1;
        elem.x = opt.col + 30 - io[elem.nb].wight;
        elem.x += (elem.x % 2 == 0) ? 0 : 1;
    }
}

void fallin(void)
{
    new_fall();
    if (act.cl * 1000 / CLOCKS_PER_SEC > act.temp * 1000
    / CLOCKS_PER_SEC + 500 - (45 * opt.level)) {
        if (elem.y != 0)
            erase_p();
        elem.y++;
        w_map();
        act.temp = act.cl;
    }
}

void game2(void)
{
    initscr();
    cbreak();
    refresh();
    curs_set(FALSE);
    start_color();
    init_pair(1, COLOR_GREEN, 0);
    init_pair(2, COLOR_RED, 0);
    init_pair(3, COLOR_BLUE, 0);
    init_pair(4, COLOR_YELLOW, 0);
    init_pair(5, COLOR_CYAN, 0);
    init_pair(6, COLOR_BLUE, 0);
    init_pair(7, COLOR_MAGENTA, 0);
    init_pair(8, COLOR_WHITE, 0);
    init_pair(9, COLOR_GREEN, 0);
}

void game(void)
{
    int cd;

    game2();
    if (opt.dbg == 1)
        debug();
    while (1) {
        p_score();
        p_lines();
        p_next();
        act.cl = clock();
        fallin();
        raw();
        move(0, 0);
        my_putarray(elem.map);
        nodelay(stdscr, TRUE);
        cd = getch();
        keypad(stdscr, true);
        noecho();
        moves(cd);
    }
}