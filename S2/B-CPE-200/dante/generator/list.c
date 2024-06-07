/*
** EPITECH PROJECT, 2023
** generator
** File description:
** list
*/

#include "my.h"

list *addnode(list *current, int x, int y)
{
    list *new = malloc(sizeof(list));
    new->prev = NULL;
    new->x = x;
    new->y = y;
    new->next = NULL;
    if (current) {
        current->prev = new;
        new->next = current;
    }
    return new;
}
