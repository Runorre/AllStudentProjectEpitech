/*
** EPITECH PROJECT, 2022
** my_params_to_list
** File description:
** params to list enchaind
*/

#include <stdlib.h>
#include "mylist.h"

int my_list_size(linked_list_t const *begin)
{
    struct linked_list *tmp = begin;
    int count = 0;
    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}
