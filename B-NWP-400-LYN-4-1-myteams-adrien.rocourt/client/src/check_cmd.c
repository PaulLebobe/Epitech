/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_cmd
*/

#include "my.h"

void check_cmd_second(char **cmd)
{

}

void check_cmd(char *tmp)
{
    char **cmd = my_str_to_word_array(tmp, "$");

    if (!strcmp(cmd[0], "/login"))
        client_event_logged_in(cmd[2], cmd[1]);
    if (!strcmp(cmd[0], "/logout"))
        client_event_logged_out(cmd[2], cmd[1]);
    if (!strcmp(cmd[0], "Already_connected"))
        client_error_already_exist();
    if (!strcmp(cmd[0], "/users"))
        client_print_users(cmd[1], cmd[2], atoi(cmd[3]));
    if (!strcmp(cmd[0], "/send"))
        client_event_private_message_received(cmd[1], cmd[2]);
    if (!strcmp(cmd[0], "wrong_uuid"))
        client_error_unknown_user(cmd[1]);
}

