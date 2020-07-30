/*
** EPITECH PROJECT, 2020
** redirections
** File description:
** read_redirec
*/

#include "../include/redirections.h"

int read_redirection1(char *file)
{
    int fd_file = open(file, O_RDONLY);
    int fd_0 = 0;

    if (fd_file >= 0) {
        fd_0 = dup(0);
        dup2(fd_file, 0);
        close(fd_file);
    } else {
        write(2, file, my_strlen(file));
        write(2, ":  No such file or directory.\n", 30);
    }
    return (fd_0);
}

int read_redirection2bis(char *word_end, int pipefd[])
{
    int i = -1;
    char *line = malloc(sizeof(char));

    write(1, "> ", 2);
    line[0] = '\0';
    do {
        i++;
        my_realloc_char_star(line, 1);
        read (1, &line[i], 1);
    } while (line[i] != '\n');
    if (is_equal(word_end, line) == 0)
        write(pipefd[1], line, my_strlen(line));
    else
        return (1);
    return (0);
}

static void reel_word_end(char *word_end)
{
    int size = my_strlen(word_end);
    char *save_word_end = str_copy(word_end);

    free(word_end);
    word_end = malloc(sizeof(char) * (size + 2));
    word_end[size + 1] = '\0';
    word_end[size] = '\n';
    for (int i = 0; i < size; i++)
        word_end[i] = save_word_end[i];
    free(save_word_end);
}

int read_redirection2(char *word_end)
{
    int fd_0 = 0;
    int pipefd[2];

    pipe(pipefd);
    reel_word_end(word_end);
    while (read_redirection2bis(word_end, pipefd) == 0);
    close(pipefd[1]);
    fd_0 = dup(0);
    dup2(pipefd[0], 0);
    close(pipefd[0]);
    return (fd_0);
}