/*
** EPITECH PROJECT, 2019
** change operator
** File description:
** change operator bistro
*/

char *changeop(char *str, char *operator)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == operator[0])
            str[i] = '(';
        if (str[i] == operator[1])
            str[i] = ')';
        if (str[i] == operator[2])
            str[i] = '+';
        if (str[i] == operator[3])
            str[i] = '-';
        if (str[i] == operator[4])
            str[i] = '*';
        if (str[i] == operator[5])
            str[i] = '/';
        if (str[i] == operator[6])
            str[i] = '%';
    }
    return (str);
}
