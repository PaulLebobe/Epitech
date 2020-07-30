/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#include "my.h"

void display_r(int r, char *n, int space)
{
    write(1, " ", space ? 1 : 0);
    my_putchar('P');
    my_putnbr(r);
    my_putchar('-');
    my_putstr(n);
}

void display_tools(path **paths, int endr)
{
    int space = 0;

    for (int i = endr; i >= 0; i--) {
        if (paths[i]->tunnel) {
            if (i != endr) {
                display_r(paths[i]->size, paths[i + 1]->room, space);
                paths[i + 1]->size = paths[i]->size;
                space = 1;
            }
            paths[i]->size++;
            if (i != endr)
                paths[i + 1]->tunnel++;
            paths[i]->tunnel--;
        }
    }
    paths[endr]->tunnel++;
    my_putchar('\n');
}

int do_path(char **tab)
{
    struct path **paths;
    int size = my_strlen(tab[0]);
    char **str = str_to_word_tab(tab[0], '-');
    int endr = 0;

    paths = malloc(sizeof(path *) * (size) + 1);
    for (int i = 0; str[i] != NULL; i++) {
        paths[i] = malloc(sizeof(struct path));
        paths[i]->room = my_strdup(str[i]);
        paths[i]->tunnel = 0;
        paths[i]->size = (i == 0 ? 1 : 0);
    }
    endr = rooms_val(paths, endr);
    while (paths[endr]->tunnel != elem.nb_ant + 1)
        display_tools(paths, endr);
    return (0);
}