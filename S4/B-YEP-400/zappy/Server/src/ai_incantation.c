/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ai.incantation
*/

#include "../include/server.h"

static const material_t level_materials[8][11] = {
    {0},
    {LINEMATE, 0},
    {LINEMATE, DERAUMERE, SIBUR, 0},
    {LINEMATE, LINEMATE, SIBUR, PHIRAS, PHIRAS, 0},
    {LINEMATE, DERAUMERE, SIBUR, SIBUR, PHIRAS, 0},
    {LINEMATE, DERAUMERE, DERAUMERE, SIBUR, MENDIANE, MENDIANE, MENDIANE},
    {LINEMATE, DERAUMERE, DERAUMERE, SIBUR, SIBUR, SIBUR, PHIRAS},
    {LINEMATE, LINEMATE, DERAUMERE, DERAUMERE, SIBUR, SIBUR,
        MENDIANE, MENDIANE, PHIRAS, PHIRAS, THYSTAME}
};

size_t get_required_players(int level)
{
    switch (level) {
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 6;
        case 7:
            return 6;
        default:
            return 0;
    }
}

bool has_required_materials(main_data_t *main_data, linked_client_t *client)
{
    int x = client->client->player->pos->x;
    int y = client->client->player->pos->y;
    map_t map = main_data->map[x][y];
    const material_t *required_mat =
        level_materials[client->client->player->level];
    int material_counts[7] = {0};

    for (int i = 0; required_mat[i] != 0; i++) {
        material_counts[required_mat[i]]++;
    }
    for (int i = 0; i < 7; i++) {
        if (map.materials[i] < material_counts[i]) {
            return false;
        }
    }
    return true;
}

void make_incantation(main_data_t *md, linked_client_t *c)
{
    int x = c->client->player->pos->x;
    int y = c->client->player->pos->y;
    const material_t *required_mat = level_materials[c->client->player->level];

    for (int i = 0; required_mat[i] != 0; i++) {
        md->map[x][y].materials[required_mat[i]]--;
    }
    pl_inc_post(md, c);
}

void print_incantation_list(linked_client_t *c)
{
    if (c->client->player->incantation_list != NULL) {
        for (int i = 0; c->client->player->incantation_list[i] != NULL; i++) {
            dprintf(c->client->player->incantation_list[i]->fd, "ko\n");
        }
    }
}

void incantation_function(main_data_t *md, linked_client_t *c, char *arg)
{
    size_t required_players = get_required_players(c->client->player->level);
    bool all_conditions = true;

    (void)arg;
    if (count_same_leve2(md, required_players, c) < required_players)
        all_conditions = false;
    if (!has_required_materials(md, c))
        all_conditions = false;
    if (all_conditions) {
        graph_end_inc(md, c, 1);
        make_incantation(md, c);
    } else {
        graph_end_inc(md, c, 0);
        print_incantation_list(c);
    }
    free_incantation(c->client->player->incantation_list);
}
