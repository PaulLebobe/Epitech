/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** isop
*/

int isop(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/' || c == '%')
        return 1;
    if (c == '(' || c == ')')
        return 1;
    return (0);
}
