/*
** EPITECH PROJECT, 2019
** raise p
** File description:
** raise p
*/

int my_power_int(int nb, int p)
{
    long result = 1;
    int resultint = 0;

    if (p == 0)
        result = 1;
    else if (p < 0)
        result = 0;
    else {
        while (p >= 1) {
            result = result * nb;
            p = p - 1;
        }
    }
    if (result >= 2147483647)
        return 0;
    resultint = (int) result;
    return (resultint);
}
