/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myradar-angelo.anselmet
** File description:
** struct
*/

#include "my.h"

struct tower *init_tower(void)
{
    struct tower *new1 = malloc(sizeof(*new1));
    new1->pos = (sfVector2f) {-1.0, -1.0};
    new1->rad = -1;
    return new1;
}

int addinfo(struct tower *tt, int num)
{
    if (tt->pos.x == -1.0) {
        tt->pos.x = (float) num;
        return 0;
    }
    if (tt->pos.y == -1.0) {
        tt->pos.y = (float) num;
        return 0;
    }
    if (tt->rad == -1) {
        tt->rad = (float) num;
        tt->poss.x = (1080.0 * (tt->rad / 100.0));
        tt->poss.y = (1080.0 * (tt->rad / 100.0));
        return 0;
    }
    return 1;
}

int checking_tower(int verif, struct tower *tt)
{
    if (tt->pos.x == -1.0) {
        return 84;
    }
    if (tt->pos.y == -1.0) {
        return 84;
    }
    if (tt->rad == -1) {
        return 84;
    }
    if (verif == 1)
        return 84;
    return 0;
}

int addnode_tower(struct ll_tower **current, struct tower *new)
{
    struct ll_tower *new2 = malloc(sizeof(*new2));
    new2->obj = new;
    new2->next = (*current);
    (*current) = new2;
    return 0;
}

int create_tower(char *line, struct ll_tower **current)
{
    struct tower *new1 = init_tower();
    int checker = 0, verif = 0;
    for (int i = 1; line[i] != '\0' && line[i] != '\n'; i++) {
        if (line[i] >= '0' && line[i] <= '9' && checker == 0) {
            verif = addinfo(new1, my_getnbr2(line));
            checker++;
        }
        if (line[i] == ' ') {
            checker = 0;
        }
        line[i] = '*';
    }
    if (checking_tower(verif, new1) == 84)
        return 84;
    return addnode_tower(current, new1);
}
