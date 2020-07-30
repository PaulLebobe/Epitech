/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** compare with n
*/

char my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n == 0)
        return 0;
    while (s1[i] == s2[i]) {
        i++;
        if (i == n)
            return 0;
    }
    return 1;
}