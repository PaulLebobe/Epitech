/*
** EPITECH PROJECT, 2019
** rev str
** File description:
** reverse string
*/

#include <stdlib.h>
#include "my.h"

char *my_revstr(char *str)
{
    int lengh;
    char *temp = my_malloc(my_strlen(str) + 2);

    for (int i = 0; str[i] != '\0'; i++)
        lengh = i;
    for (int i = 0; i <= lengh; i++){
        temp[i] = str[lengh - i];
    }
    return temp;
}
