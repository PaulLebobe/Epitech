/*
** EPITECH PROJECT, 2020
** puisssance
** File description:
** c
*/

int puissance(int nbr, int const power)
{
    int save_nbr = nbr;

    for (int i = 1; i < power; i++)
        nbr *= save_nbr;
    return (nbr);
}