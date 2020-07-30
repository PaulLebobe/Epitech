/*
** EPITECH PROJECT, 2019
** m putstr
** File description:
** display string
*/

#include "my.h"

int my_putstr(char *str)
{
    int print = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!(print == 0 && str[i] == '0')) {
            if (str[i] == '_' || str[i] == '-')
                my_putchar('-');
            else {
                print = 1;
                my_putchar(str[i]);
            }
        }
    }
    if (print == 0)
        my_putchar('0');
    return (0);
}
