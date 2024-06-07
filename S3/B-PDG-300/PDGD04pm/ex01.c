/*
** EPITECH PROJECT, 2024
** Day04PM
** File description:
** ex01
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdio.h>

bool int_list_add_elem_at_back(int_list_t **front_ptr, int elem)
{
    int_list_t *tmp = (*front_ptr);

    if (!(*front_ptr)) {
        (*front_ptr) = malloc(sizeof(int_list_t));
        if (!(*front_ptr))
            return false;
        (*front_ptr)->value = elem;
        (*front_ptr)->next = NULL;
        return true;
    }
    for (int i = 0; tmp->next; i++)
        tmp = tmp->next;
    tmp->next = malloc(sizeof(int_list_t));
    if (!tmp->next)
        return false;
    tmp->next->value = elem;
    tmp->next->next = NULL;
    return true;
}

void int_list_dump(int_list_t *list)
{
    for (int_list_t *tmp = list; tmp; tmp = tmp->next) {
        if (tmp)
            printf("%d\n", tmp->value);
    }
}

unsigned int int_list_get_size(int_list_t *list)
{
    unsigned int len = 0;

    for (int_list_t *tmp = list; tmp; tmp = tmp->next) {
        if (tmp)
            len++;
    }
    return len;
}

bool int_list_is_empty(int_list_t *list)
{
    if (list)
        return false;
    else
        return true;
}

void int_list_clear(int_list_t **front_ptr)
{
    int_list_t *tmp = (*front_ptr)->next;

    while (*front_ptr) {
        free(*front_ptr);
        *front_ptr = tmp;
        if (tmp != NULL)
            tmp = tmp->next;
    }
}
