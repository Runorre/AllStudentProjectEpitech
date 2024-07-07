/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ai_fork
*/

#include "../include/server.h"

void forking(main_data_t *md, linked_client_t *client, char *args)
{
    egg_t *egg = malloc(sizeof(egg_t));

    (void)args;
    egg->x = client->client->player->pos->x;
    egg->y = client->client->player->pos->y;
    md->egg_id++;
    egg->id = md->egg_id;
    add_egg_in_list(
        &client->client->team_link->eggs,
        egg, md, &client->client->team_link->last
    );
    client->client->team_link->nbr_max_member++;
    enw_graph(md, client, client->client->team_link->eggs);
}
