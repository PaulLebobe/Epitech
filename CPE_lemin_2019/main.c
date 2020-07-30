/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#include "my.h"

int parse_file(void)
{
    int i = 0;
    size_t len = 0;
    ssize_t nread;
    char *buff = NULL;

    elem.file_data = malloc(sizeof(char *) * (1000));
    while (getline(&buff, &len, stdin) != -1) {
        if (buff[0] == '\n')
            break;
        elem.file_data[i] = my_strdup(buff);
        if (f_buff(i) == 84)
            return (84);
        i++;
    }
    elem.file_data[i] = NULL;
    free(buff);
    elem.file_data = rm_nslash(elem.file_data);
}

int f_buff(int i)
{
    int j = 0;
    char **buff = elem.file_data;
    elem.tunnel = 0;
    j = 0;
    while (buff[i][j] && buff[i][j] != '\n') {
        if (buff[i][j] == '-')
            elem.tunnel = 1;
        j++;
    }
    if (f_struct(buff[i]) == 84)
        return (84);
}

int main(int ac, char **av)
{
    char **paths = NULL;

    if (ac !=  1)
        return (84);
    if (parse_file() == 84)
        return (84);
    if (fuck_file() == 84)
        return (84);
    else {
        paths = dijkstra();
        if (my_strcmp(paths[0], elem.exit) == 0)
            return (84);
        print_par();
        do_path(paths);
    }
    return (0);
}