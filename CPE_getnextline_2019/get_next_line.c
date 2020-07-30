/*
** EPITECH PROJECT, 2019
** Getnextline
** File description:
** change line
*/

#include "get_next_line.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;
    int sign = 1;

    while (1) {
        if ((str[i] < '0' && str[i] != '-') || str[i] > '9')
            break;
        if (str[i] == '-') {
            sign = -sign;
            i = i + 1;
        }
        while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0') {
            nb = nb + str[i] - 48;
            nb = nb * 10;
            i = i + 1;
        }
    }
    nb = nb / 10;
    nb = nb * sign;
    return nb;
}

char *my_add(int fd, char *temp, char **str3)
{
    int i = 1;
    int offset = 0;
    int nb = 0;
    char *str2 = malloc(sizeof(char) * READ_SIZE);
    char *str = malloc(sizeof(char) * READ_SIZE);

    while (read(fd, str2, READ_SIZE)) {
        i += READ_SIZE;
        temp = str;
        str = malloc(sizeof(char) * i);
        for (int x = 0; temp[x]; x++)
            str[x] = temp[x];
        nb = 0;
        for (int e = my_strlen(str); str2[nb]; e++){
            str[e] = str2[nb];
            nb++;
        }
        *str3 = malloc(sizeof(char) * i);
    }
    return (str);
}

char *get_next_line(int fd)
{
    int len;
    char *temp;
    static char *str;
    char *str3;
    int w = 0;
    static int size = 0;
    int z = 0;

    if (READ_SIZE < 1)
        return (84);
    if (size == 0)
        str = my_add(fd, temp, &str3);
    if (str[size] == NULL)
        return (NULL);
    for (int w = size; str[w] != '\n' && str[w] != '\0'; w++) {
        str3[z] = str[w];
        z++;
        size = w + 2;
        str3[z] = '\0';
    }
    return (str3);
}