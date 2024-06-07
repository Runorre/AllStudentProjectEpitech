/*
** EPITECH PROJECT, 2022
** my_params_to_list
** File description:
** params to list enchaind
*/

#include <stdlib.h>
#include "mylist.h"

int my_put_in_list(struct linked_list **list, char *data)
{
    struct linked_list *suite;
    suite = malloc(sizeof(*suite));
    suite->data = data;
    suite->next = *list;
    *list = suite;
    return 0;
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    struct linked_list *list;
    list = NULL;
    for (int i = 0; i != ac; i++) {
        my_put_in_list(&list, av[i]);
    }
    return list;
}
