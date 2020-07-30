/*
** EPITECH PROJECT, 2019
** str leng
** File description:
** count str leng
*/

int my_strlen(char *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++)
        res++;
    return res;
}
