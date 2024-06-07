/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-pushswap-angelo.anselmet
** File description:
** finding
*/

#include "my.h"

int indicemin(struct node *list_a, int minus)
{
    struct node *tmp;
    if (list_a == NULL)
        return 0;
    if (list_a->next != NULL)
        tmp = list_a->next;
    else
        return 0;
    int i = 0;
    while (tmp != NULL) {
        if (tmp->value == minus)
            return i;
        tmp = tmp->next;
        i++;
    }
    return 0;
}
