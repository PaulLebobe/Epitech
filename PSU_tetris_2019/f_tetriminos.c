/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** f_tetriminos
*/

#include "my.h"

void to_array(void)
{
    int e = 0;

    io[io[0].fill].piece = malloc(sizeof(char *) * (io[io[0].fill].height + 1));
    for (int i = 0; i < io[io[0].fill].height; i++) {
        io[io[0].fill].piece[i] = malloc(sizeof(char) *
        (io[io[0].fill].wight + 1));
        for (int x = 0; io[io[0].fill].tmp[e] != '\n' && io[io[0].fill].tmp[e] != '\0'; x += 2) {
            io[io[0].fill].piece[i][x] = io[io[0].fill].tmp[e];
            if (io[io[0].fill].tmp[e] == '*')
                io[io[0].fill].piece[i][x] = io[io[0].fill].color + 48;
            io[io[0].fill].piece[i][x + 1] = ' ';
            e++;
        }
        e++;
    }
}

int fill_struct(char *buff)
{
    if (buff[0] < 48 || buff[0] > 57 || buff[1] != ' ' || buff[3] != ' ' ||
    buff[2] < 48 || buff[2] > 57 || buff[4] < 48 || buff[4] > 57 || buff[5]
    != '\n')
        io[io[0].fill].error = 1;
    else {
        io[io[0].fill].wight = buff[0] - 48;
        io[io[0].fill].height = buff[2] - 48;
        io[io[0].fill].color = buff[4] - 48;
    }
    io[io[0].fill].tmp = buff + 6;
    for (int i = 0; io[io[0].fill].tmp[i]; i++)
        if (io[io[0].fill].tmp[i] != ' ' || io[io[0].fill].tmp[i] !=
        '*' || io[io[0].fill].tmp[i] != '\n')
            io[io[0].fill].error = 1;
    to_array();
    io[0].fill++;
}

void f_buff(char *path)
{
    int buff_size = f_size(path);
    int offset = 0;
    int fd = open(path, O_RDONLY);
    int len;
    char *buff = malloc(sizeof(char) * (buff_size + 1));

    if (fd == - 1 || f_size(path) < 6)
        io[io[0].fill].error = 1;
    else {
        while ((len = read(fd, buff + offset, buff_size - offset)) > 0)
            offset = offset + len;
        buff[offset] = '\0';
    }
    fill_struct(buff);
}

int fill_tetriminos(void)
{
    DIR *rep = opendir("tetriminos");
    char *tmp = "tetriminos/";
    struct dirent *buff;

    while ((buff = readdir(rep))) {
        if (my_strcmp(buff->d_name, ".") != 0 &&
        my_strcmp(buff->d_name, "..") != 0) {
            io[elem.nb].path = malloc(sizeof(char) * 100);
            io[elem.nb].path = my_strcat(tmp, buff->d_name);
            elem.nb++;
        }
    }
    for (int i = 0; i < elem.nb; i++)
        f_buff(io[i].path);
    elem.max = elem.nb;
}