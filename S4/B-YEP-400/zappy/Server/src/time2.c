/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** time2
*/

#include "../include/server.h"

void pins_event(main_data_t *md, linked_client_t **user)
{
    for (linked_client_t *tmp = md->list_g; tmp != NULL; tmp = tmp->next) {
        pin_event(tmp->client->fd, (*user));
    }
}

void check_stop_incantation(main_data_t *md, linked_client_t **user)
{
    if ((*user)->client->player->is_in_incantation)
        stop_incantation(md, (*user));
}
