/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** graphic_event
*/

#include "../include/server.h"

void dead_event_graphic(main_data_t *md, linked_client_t **user)
{
    for (linked_client_t *tmp = md->list_g; tmp != NULL; tmp = tmp->next) {
        dprintf(tmp->client->fd, "pdi %i\n", (*user)->client->id);
    }
}

void player_pos_graph(main_data_t *md, linked_client_t *user)
{
    for (linked_client_t *tmp = md->list_g; tmp != NULL; tmp = tmp->next) {
        dprintf(tmp->client->fd, "ppo %d %d %d %d\n", user->client->id,
        user->client->player->pos->x, user->client->player->pos->y,
        show_orientation(user->client->player->direction));
    }
}

void eject_notif(main_data_t *md, linked_client_t *client, int x, int y)
{
    for (linked_client_t *tmp = md->list_g; tmp != NULL; tmp = tmp->next) {
        dprintf(tmp->client->fd, "pex %i\n", client->client->id);
    }
    update_player_pos(client->client->player, x, y);
}

void egg_graph(main_data_t *md, egg_node_t *e)
{
    for (linked_client_t *tmp = md->list_g; tmp != NULL; tmp = tmp->next) {
        dprintf(tmp->client->fd, "edi %i\n", e->egg->id);
    }
}

void start_inc_graph(main_data_t *md, linked_client_t *c, client_t **l)
{
    for (linked_client_t *tmp = md->list_g; tmp != NULL; tmp = tmp->next) {
        ics(md, c, tmp, l);
    }
}
