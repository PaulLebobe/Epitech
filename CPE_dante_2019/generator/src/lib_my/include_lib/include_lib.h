/*
** EPITECH PROJECT, 2020
** include_lib
** File description:
** h
*/

#ifndef INCLUDE_LIB_H
#define INCLUDE_LIB_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

#define READ_SIZE (200)

/* my_realloc.c */
char *my_realloc_char_star(char *, int const);

/* int_to_char.c */
char *int_to_char(int);

/* my_putstring.c */
int my_putstring(char *, int);

/* is_equal.c */
int is_equal(char *, char *);
int test_cass(char, char);
int is_equal_no_cass(char *, char *);

/* two_string_in_one.c */
char *string1_and_string2(char const *, char *);

/* puissance.c */
int puissance(int, int const);

/* get_next_line.c */
char *get_next_line(int fd);

/* my_strlen.c */
int my_strlen(char *);

/* my_strlen_2d.c */
int my_strlen_2d(char **);

/* char_to_int.c */
int char_to_int(char *);
int char_to_int_progress(char *, int *);

#endif /* !INCLUDE_LIB_H */