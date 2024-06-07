/*
** EPITECH PROJECT, 2023
** generator
** File description:
** order66
*/

#include "my.h"

void order66(list *file)
{
    if (file == NULL) {
        free(file)
        return 0;
    }
    for (list *tmp = file; tmp; tmp = tmp->next) {
        if (tmp->prev == NULL)
            free(tmp->prev);
    }
    free(file);
    return 0;
}
