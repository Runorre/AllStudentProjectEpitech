/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ai_verif_incan
*/

#include "../include/server.h"

bool verif_incan(main_data_t *md, linked_client_t *c, char *arg)
{
    size_t required_players = get_required_players(c->client->player->level);
    bool all_conditions = true;
    bool verif = true;
    client_t **list_c = calloc(required_players + 1, sizeof(client_t *));

    (void)arg;
    if (count_same_level(md, required_players, c, list_c)
    < required_players)
        all_conditions = false;
    if (!has_required_materials(md, c))
        all_conditions = false;
    if (all_conditions) {
        pl_inc_pre(c, list_c);
        start_inc_graph(md, c, list_c);
        verif = false;
    } else {
        free_incantation(list_c);
        dprintf(c->client->fd, "ko\n");
    }
    return verif;
}
