/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams-adrien.rocourt
** File description:
** main
*/

#include "my.h"

void help(void)
{
    printf("USAGE: ./myteams_cli ip port\n\tip\tis");
    printf(" the server ip adress on which the server socket listens\n\t");
    printf("port\t is the port number on which the server socket listens\n");
    exit(0);
}

int main(int ac, char **av)
{
    if (ac == 2 && (strcmp(av[1], "-help") == 0))
        help();
    init_client(av[1], atoi(av[2]));
    return 0;
}