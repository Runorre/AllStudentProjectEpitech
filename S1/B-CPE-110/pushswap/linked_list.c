/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-pushswap-angelo.anselmet
** File description:
** linked_list
*/

#include "my.h"

void addnode(struct node *list, int data)
{
    struct node *new;
    new = malloc(sizeof(*new));
    new->prev = list;
    new->value = data;
    new->next = NULL;
    if (list != NULL)
        list->next = new;
    else
        list = new;
}

struct node *addnode_2(struct node *list, int data)
{
    struct node *new;
    new = malloc(sizeof(*new));
    new->prev = NULL;
    new->value = data;
    new->next = NULL;
    if (list != NULL) {
        list->prev = new;
        new->next = list;
    } else
        list = new;
    return new;
}

struct node *create(char **av, int ac)
{
    struct node *list;
    list = malloc(sizeof(*list));
    list->prev = NULL;
    list->value = my_getnbr(av[1]);
    list->next = NULL;
    struct node *next;
    next = list;
    for (int i = 2; i != ac; i++) {
        addnode(next, my_getnbr(av[i]));
        next = next->next;
    }
    next = NULL;
    return list;
}
