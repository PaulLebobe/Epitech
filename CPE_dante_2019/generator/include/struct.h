/*
** EPITECH PROJECT, 2020
** CPEs2
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct road_d {
    int pos_x;
    int pos_y;
    void *next;
    void *last;
} road_t;

#endif /* !STRUCT_H_ */