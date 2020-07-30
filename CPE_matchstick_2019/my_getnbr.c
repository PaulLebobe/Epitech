/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** print_nbr
*/

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