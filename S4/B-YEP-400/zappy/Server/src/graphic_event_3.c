/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** graphic_event_3
*/

#include "../include/server.h"

void set_graph(main_data_t *md, linked_client_t *c, material_t mat)
{
    for (linked_client_t *tmp = md->list_g; tmp != NULL; tmp = tmp->next) {
        dprintf(tmp->client->fd, "pdr %i %i\n", c->client->id, (int)mat);
        pin_event(tmp->client->fd, c);
    }
}

void enw_graph(main_data_t *md, linked_client_t *c, egg_node_t *egg)
{
    egg_node_t *tmpe = egg;

    for (; tmpe->next != NULL; tmpe = tmpe->next);
    for (linked_client_t *tmp = md->list_g; tmp != NULL; tmp = tmp->next) {
        dprintf(tmp->client->fd, "enw %i %i %i %i\n", tmpe->egg->id,
        c->client->id, tmpe->egg->x, tmpe->egg->y);
    }
}

void all_player_pos(main_data_t *md)
{
    for (linked_team_t *t = md->list_t; t != NULL; t = t->next) {
        for (linked_client_t *tmp = t->team_s->list; tmp != NULL;
        tmp = tmp->next) {
            player_pos_graph(md, tmp);
        }
    }
}

void ics(main_data_t *m, linked_client_t *c, linked_client_t *t, client_t **l)
{
    char *str = NULL;
    char *old_str = NULL;

    asprintf(&str, "pic %i %i %i %i", c->client->player->pos->x,
    c->client->player->pos->y, c->client->player->level + 1, c->client->id);
    write_all_inc_g(&str, m, c, l);
    old_str = str;
    asprintf(&str, "%s\n", old_str);
    free(old_str);
    write(t->client->fd, str, strlen(str));
    free(str);
}
