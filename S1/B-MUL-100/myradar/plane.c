/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myradar-angelo.anselmet
** File description:
** struct of plane
*/

#include "my.h"

plane *init_plane(void)
{
    plane *new1 = malloc(sizeof(*new1));
    new1->pos = (sfVector2f) {-1.0, -1.0};
    new1->end = (sfVector2f) {-1.0, -1.0};
    new1->speed = -1;
    new1->starting = -1;
    return new1;
}

int addinfo_p1(plane *tt, int num)
{
    if (tt->pos.x == -1.0) {
        tt->pos.x = (float) num;
        return 0;
    }
    if (tt->pos.y == -1.0) {
        tt->pos.y = (float) num;
        return 0;
    }
    if (tt->end.x == -1.0) {
        tt->end.x = (float) num;
        return 0;
    }
    if (tt->end.y == -1.0) {
        tt->end.y = (float) num;
        return 0;
    }
    return addinfo_p2(tt, num);
}

int checking_plane(int verif, plane *tt)
{
    if (tt->pos.x == -1.0)
        return 84;
    if (tt->pos.y == -1.0)
        return 84;
    if (tt->starting == -1)
        return 84;
    if (tt->speed == -1)
        return 84;
    if (verif == 1)
        return 84;
    return 0;
}

int addnode_plane(ll_plane **current, plane *new)
{
    ll_plane *new2 = malloc(sizeof(*new2));
    new2->obj = new;
    new2->next = (*current);
    (*current) = new2;
    return 0;
}

int create_plane(char *line, ll_plane **current)
{
    plane *new1 = init_plane();
    int checker = 0, verif = 0;
    for (int i = 1; line[i] != '\0'; i++) {
        if (line[i] >= '0' && line[i] <= '9' && checker == 0) {
            verif = addinfo_p1(new1, my_getnbr2(line));
            checker++;
        }
        if (line[i] == ' ') {
            checker = 0;
        }
        line[i] = '*';
    }
    if (checking_plane(verif, new1) == 84) {
        return 84;
    }
    return addnode_plane(current, new1);
}
