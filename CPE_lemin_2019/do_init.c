/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#include "my.h"

int f_struct3(char *name, char *buff)
{
    if (elem.ent == 1) {
            elem.entr = name;
            io[elem.room - 1].nb = elem.nb_ant;
            elem.st = elem.room - 1;
            elem.ent = 2;
    }
    if (elem.ext == 1) {
        elem.exit = name;
        elem.ext = 2;
        elem.ex = elem.room - 1;
        io[elem.room - 1].end = 1;
    }
    if (my_strcmp(buff, "##start\n") == 0 && elem.ent == 2  ||
    my_strcmp(buff, "##end\n") == 0 && elem.ext == 2)
        return (84);
    elem.ent = (my_strcmp(buff, "##start\n") == 0) ? 1 : elem.ent;
    elem.ext = (my_strcmp(buff, "##end\n") == 0) ? 1 : elem.ext;
}

int f_struct2(char *name, char *buff)
{
    char *str = malloc(sizeof(char) * 1000);
    char *str2 = malloc(sizeof(char) * 1000);
    int e = 0, x = 0, test = 0;

    if (elem.tunnel == 1 && buff[0] != '#'  && buff[0] != ' ') {
        for (; buff[e] != '-'; e++)
            str[e] = buff[e];
        e++;
        for (int i = 0; buff[e] && buff[e] != '\n'; e++, i++)
            str2[i] = buff[e];
        tu[elem.nb_tu].room = str;
        tu[elem.nb_tu].room2 = str2;
        elem.nb_tu++;
        for (int i = 0; io[i].name != NULL; i++)
            test += (my_strcmp(io[i].name, tu[elem.nb_tu - 1].room) == 0 ||
            my_strcmp(io[i].name, tu[elem.nb_tu - 1].room2) == 0) ? 1 : 0;
        if (test != 2)
            return (84);
    }
    return (f_struct3(name, buff));
}

void f_struct1b(char *buff, char *name, int temp, int w)
{
    io[elem.room].name = name;
    io[elem.room].x = my_getnbr(buff + w + 1);
    io[elem.room].visited = 0;
    io[elem.room].min = -1;
    io[elem.room].prev = NULL;
    temp = io[elem.room].x;
    for (; temp > 10; temp = temp / 10)
        w++;
    io[elem.room].y = my_getnbr(buff + w + 3);
    elem.room++;
}

int f_struct1(char *buff)
{
    char *name = malloc(sizeof(char *) * (1000));
    int w = 0;
    int temp;

    if (elem.tunnel == 0 && buff[0] != '#' && elem.nb_ant != 0) {
        for (; buff[w] != ' '; w++)
            name[w] = buff[w];
        for (int i = w; buff[i] != '\n' && buff[i] != '#'; i++)
            if ((is_str_nb(buff[i]) == 0) && buff[i] != ' ') {
                my_putstr("error\n");
                return (84);
            }
        for (int j = 0; io[j].name != NULL; j++) {
            if (my_strcmp(io[j].name, name) == 0) {
                my_putstr("EXIST NAME\n");
                return (84);
            }
        }
        f_struct1b(buff, name, temp, w);
    }
    return (f_struct2(name, buff));
}

int f_struct(char *buff)
{
    if (elem.nb_ant == 0) {
        if (buff[0] != '#') {
            for (int i = 0; buff[i] != '\n' && buff[i] != '#'; i++) {
                if (buff[i] < '0' || buff[i] > '9') {
                    my_putstr("INVALID ANTS NB\n");
                    return (84);
                }
            }
            elem.nb_ant = my_getnbr(buff);
        }
    } else
        return (f_struct1(buff));
}
