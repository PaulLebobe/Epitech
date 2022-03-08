/*
** EPITECH PROJECT, 2021
** B-NWP-400-LYN-4-1-myteams-adrien.rocourt
** File description:
** init_client
*/

#include "my.h"

int create_server(int port, char *ip)
{
    int sock;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return 0;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return 0;
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return 0;
    }
    return sock;
}

int receive_msg(unsigned char *buffer, int sock)
{
    int len;
    char *tmp;

    if ((len = recv(sock, buffer, 1024, 0)) < 0)
        return 0;
    else if (len == 0) {
        printf("Connection closed by the remote end\n\r");
        return 0;
    }
    buffer[len] = 0;
    fflush(0);
    check_cmd(buffer);
    return 1;
}

int send_msg(unsigned char *buffer, int sock)
{
    int len;

    len = read(0, buffer, 1024);
    if (send(sock, buffer, len, 0) < 0)
        return 0;
    return 1;
}

void init_client(char *ip, int port)
{
    int sock = create_server(port, ip);
    unsigned char buffer[1025];

    if (!sock)
        return;
    while (1) {
        fd_set fds;
        FD_ZERO(&fds);
        if (sock != 0)
            FD_SET(sock, &fds);
        FD_SET(0, &fds);
        if (select(sock + 1, &fds, (fd_set *) 0, (fd_set *) 0, NULL) < 0)
            return;
        if (sock != 0 && FD_ISSET(sock, &fds)) {
            if (!receive_msg(buffer, sock))
                return;
        } else if (FD_ISSET(0, &fds))
            if (!send_msg(buffer, sock))
                return;
    }
}