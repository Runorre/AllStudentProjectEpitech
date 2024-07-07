/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** stop_incantation
*/

#include "../include/server.h"

void stop_incantation(main_data_t *md, linked_client_t *c)
{
    size_t count = 0;
    client_t **l = c->client->player->incantation_list;

    if (l == NULL)
        return;
    while (l[count] != NULL) {
        dprintf(l[count]->fd, "ko\n");
        l[count]->player->is_in_incantation = false;
        count++;
    }
    graph_end_inc(md, c, 0);
    free_incantation(l);
}
