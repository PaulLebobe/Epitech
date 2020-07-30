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
    int neg = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '_') {
            nb = nb + str[i] - 48;
            nb = nb * 10;
        }
        if (str[i] == '_')
            neg = 1;
        i++;
    }
    nb = nb / 10;
    nb = (neg == 1) ? -nb : nb;
    return (nb);
}
