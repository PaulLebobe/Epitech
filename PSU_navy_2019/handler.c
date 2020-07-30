/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** handler
*/

#include "my.h"

void hdl(int sig)
{
    mess *p = &io;

    p->cd++;
}

void hdl2(int sig)
{
    mess *p = &io;

    p->cd2++;
}

void hdl3(int sig)
{
    mess *p = &io;

    p->status = 3;
}

void hdl4(int sig)
{
    mess *p = &io;

    p->status = 4;
}

void hdstop(int sig)
{
    mess *p = &io;

    p->status = (p->status == 0) ? 1 : 0;
}