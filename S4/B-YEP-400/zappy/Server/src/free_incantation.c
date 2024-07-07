/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** free_incantation
*/

#include "../include/server.h"

void free_incantation(client_t **list)
{
    client_t **tmp = list;

    if (list == NULL) {
        return;
    }
    for (size_t i = 0; tmp[i] != NULL; i++) {
        tmp[i]->player->is_in_incantation = false;
        tmp[i]->player->incantation_list = NULL;
    }
    free(tmp);
}
