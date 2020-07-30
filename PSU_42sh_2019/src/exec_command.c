/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec_command
*/

#include "../include/42sh.h"

int command(char **argv, char **env, char *buf)
{
    int i;

    if (is_equal(argv[0], "cd")) {
        cd(argv, buf) == 1 ? : test(argv, env);
        return 0;
    }
    if (is_equal(argv[0], "setenv")) {
        return (0);
    }
    if (is_equal(argv[0], "unsetenv")) {
        return (0);
    }
    return (test(argv, env));
}

void test_pipe(char *symb, int *fd_0, int *fd_1, int pipefd[2][2])
{
    if (symb != NULL && is_equal(symb, "|")) {
        if (pipefd[0][1] != -1 || pipefd[0][0] != -1)
            create_pipe(fd_0, fd_1, pipefd[1]);
        else
            create_pipe(fd_0, fd_1, pipefd[0]);
    }
    if (pipefd[0][1] == -1 && pipefd[0][0] != -1)
        open_pipe0(pipefd[0], fd_0, fd_1);
    if (pipefd[1][1] == -1 && pipefd[1][0] != -1)
        open_pipe0(pipefd[1], fd_0, fd_1);

}

void change_pipe(int *fd_0, int *fd_1, int pipefd[2][2])
{
    if (pipefd[0][0] == -1 && pipefd[0][1] == -1) {
        pipefd[0][0] = pipefd[1][0];
        pipefd[0][1] = pipefd[1][1];
        pipefd[1][0] = -1;
        pipefd[1][1] = -1;
    }
    if (pipefd[0][0] == -1 && pipefd[1][0] == -1)
        exit_redirection(0, fd_0);
    if (pipefd[0][1] == -1 && pipefd[1][1] == -1)
        exit_redirection(1, fd_1);
    if (pipefd[0][1] > -1)
        close_pipe1(pipefd[0], fd_0, fd_1);
    else if (pipefd[0][0] > -1)
        close_pipe0(pipefd[0], fd_0, fd_1);
    if (pipefd[1][1] > -1)
        close_pipe1(pipefd[1], fd_0, fd_1);
    else if (pipefd[1][0] > -1)
        close_pipe0(pipefd[1], fd_0, fd_1);
}

int exec_command(char *str, char **env, char *buf)
{
    int good = test_commande_line(str);
    char *symb = NULL;
    char **argv = NULL;
    char *cond = NULL;
    int size_argv = 0;
    int fd_0 = 0;
    int fd_1 = 1;
    int pipefd[2][2] = {{-1, -1}, {-1, -1}};

    if (good == 84 || str == NULL)
        return (good);
    symb = symbol(str);
    if (symb != NULL && (is_equal(symb, "|") || is_equal(symb, "||") ||
        is_equal(symb, "&&"))) {
        write(2, "Invalid null command.\n", 22);
        free(symb);
        return (84);
    }
    for (int i = 0; str != NULL && str[i] != '\n' && str[i] != '\0';) {
        argv = new_create_argv(&str[i], &size_argv);
        if (argv == NULL)
            return (good);
        i += size_argv;
        symb = symbol(&str[i]);
        if (cond == NULL || (is_equal(cond, "||") && good != 0)
            || (is_equal(cond, "&&") && good == 0)) {
            test_pipe(symb, &fd_0, &fd_1, pipefd);
            redirection(&fd_0, &fd_1, size_argv, &str[i - size_argv]);
            good = command(argv, env, buf);
            change_pipe(&fd_0, &fd_1, pipefd);
        }
        if (symb != NULL && (is_equal(symb, "||") || is_equal(symb, "&&")))
            cond = str_copy(symb);
        if (symb != NULL && is_equal(symb, ";"))
            cond = NULL;
        if (symb != NULL)
            i += my_strlen(symb);
    }
    return (good);
}