/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams-adrien.rocourt
** File description:
** linkedList
*/

#include "my.h"

int linkedLenght (t_client *client)
{
    int res = 1;

    if (!client)
        return 0;
    while (client->next) {
        res++;
        client = client->next;
    }
    return res;
}