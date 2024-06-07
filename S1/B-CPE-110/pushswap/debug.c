/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-pushswap-angelo.anselmet
** File description:
** debug
*/

#include "my.h"

void my_put_linkedlist(struct node *list)
{
    for (struct node *tmp = list; tmp; tmp = tmp->next)
        my_printf("%i ", tmp->value);
}
