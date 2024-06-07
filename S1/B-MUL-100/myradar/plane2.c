/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myradar-angelo.anselmet
** File description:
** plane2
*/

#include "my.h"

int addinfo_p2(plane *tt, int num)
{
    if (tt->speed == -1) {
        tt->speed = (float) num;
        return 0;
    }
    if (tt->starting == -1) {
        tt->starting = (float) num;
        tt->show = 1;
        tt->safe = 0;
        return 0;
    }
    return 1;
}
