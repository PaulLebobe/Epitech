/*
** EPITECH PROJECT, 2020
** CPE_getnextline_2019
** File description:
** get_next_line
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct square square;

char *get_next_line(int fd);

#ifndef READ_SIZE 
#define READ_SIZE (200)
#endif

#endif /* !GET_NEXT_LINE_H_ */