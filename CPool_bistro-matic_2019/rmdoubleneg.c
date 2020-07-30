/*
** EPITECH PROJECT, 2019
** rm double neg
** File description:
** remove __ sign
*/

char *rmdoubleneg(char *str)
{
    char lastchar = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == '_' || str[i] == '-') && str[i] == lastchar) {
            str[i] = ' ';
            str[i - 1] = ' ';
        }
        lastchar = str[i];
    }
    return (str);
}
