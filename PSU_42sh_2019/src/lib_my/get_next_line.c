/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** c
*/

#include "include_lib/include_lib.h"

char *my_realloc(char *buf, int const size)
{
    int i = 0;
    char *save = malloc(sizeof(char) * (size + 1));

    for (i = 0; buf[i] != '\0'; i++)
        save[i] = buf[i];
    save[i] = '\0';
    free(buf);
    buf = malloc(sizeof(char) * (size + 1));
    for (i = 0; save[i] != '\0'; i++)
        buf[i] = save[i];
    buf[i] = '\0';
    free(save);
    return (buf);
}

char *line_value(char *all, int loop)
{
    char *push;
    int nbr_loop = 0;
    int pos[3] = {0};

    for (nbr_loop = 0; nbr_loop <= loop && all[pos[2]] != '\0'; nbr_loop++) {
        for (pos[0] = 0; all[pos[2]] != '\n' && all[pos[2]] != '\0'; pos[0]++)
            pos[2]++;
        pos[2]++;
        if (all[pos[2]] == '\0' && nbr_loop < loop)
            return (NULL);
    }
    if (all[pos[2]] == '\0' && nbr_loop < loop)
        return (NULL);
    pos[0]++;
    push = malloc(sizeof(char) * pos[0] + 1);
    for (pos[1] = 0; all[pos[2] - pos[0] + pos[1]] != '\n' &&
        all[pos[2] - pos[0] + pos[1]] != '\0'; pos[1]++)
        push[pos[1]] = all[pos[2] - pos[0] + pos[1]];
    push[pos[1]] = '\0';
    return (push);
}

char *reading(char *all, int fd)
{
    char *buf = malloc(sizeof(char) * (READ_SIZE + 1));
    int i = 0;
    int error = 0;

    all = malloc(sizeof(char) * (READ_SIZE + 1));
    for (int init_buf = 0; init_buf <= READ_SIZE; init_buf++)
        buf[init_buf] = '\0';
    error = read(fd, buf, READ_SIZE);
    for (int sz = READ_SIZE; error != 0 && error != -1; sz += READ_SIZE) {
        all = my_realloc_char_star(all, sz);
        for (i = 0; buf[i] != '\0'; i++)
            all[i + sz - READ_SIZE] = buf[i];
        all[i + sz - READ_SIZE] = '\0';
        for (i = 0; buf[i] != '\0'; i++)
            buf[i] = '\0';
        error = read(fd, buf, READ_SIZE);
    }
    free(buf);
    return (all);
}

char *get_next_line(int fd)
{
    static int loop = 0;
    static char *all;
    char *line;

    if (loop == 0)
        all = reading(all, fd);
    line = line_value(all, loop);
    loop += 1;
    if (line == NULL) {
        free(all);
        loop = 0;
    }
    return (line);
}