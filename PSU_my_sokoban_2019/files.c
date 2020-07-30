/*
** EPITECH PROJECT, 2019
** My_Sokoban
** File description:
** Sokoban
*/

#include "my.h"

long f_size(const char *filename)
{
    struct stat s;

    if (stat(filename, &s) != 0)
        exit(84);
    return s.st_size;
}

char **to_char(char *buff, int lines, int cols)
{
    int i = 0;
    int e = 0;
    char **buff2 = malloc(sizeof(char *) * lines);

    for (; buff[i] != '\0'; i++) {
        buff2[e] = malloc(sizeof(char) * cols + 1);
        for (int x = 0; buff[i] != '\n'; x++) {
            buff2[e][x] = buff[i];
            i++;
            buff2[e][x + 1] = '\n';
        }
        e++;
        buff2[e] = NULL;
    }
    return (buff2);
}

void find_p(char **str, int *x, int *y)
{
    for (int i = 0; str[i]; i++) {
        for (int e = 0; str[i][e] != '\0'; e++)
            if (str[i][e] == 'P') {
                *y = i;
                *x = e;
            }
    }
}

void init_w2(char *buff, int *lines, int *cols)
{
    int cols2 = 1;

    for (int i = 0; buff[i] != '\0'; i++) {
    for (i; buff[i] != '\n'; i++)
        cols2 = cols2 + 1;
    if (cols2 > *cols)
        *cols = cols2;
    cols2 = 1;
    }
    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i] == '\n')
            *lines += 1;
}

void init_w(char *buff, int tot)
{
    int lines = 0;
    int cols = 1;
    int move;
    int x;
    int y;
    char **str;
    int cd[4];

    init_w2(buff, &lines, &cols);
    str = to_char(buff, lines, cols);
    find_p(str, &x, &y);
    cd[0] = x;
    cd[1] = y;
    initscr();
    cbreak();
    mvprintw(0, 0, buff);
    refresh();
    curs_set(FALSE);
    game(str, cd, tot, buff);
}