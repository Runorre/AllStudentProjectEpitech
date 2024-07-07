/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ai_count_player
*/

#include "../include/server.h"

void plv_action(main_data_t *m, client_t *c)
{
    for (linked_client_t *tmp = m->list_g; tmp != NULL; tmp = tmp->next) {
        dprintf(tmp->client->fd, "plv %i %i\n", c->id,
        c->player->level);
    }
}

void pl_inc_pre(linked_client_t *c, client_t **l)
{
    size_t count = 0;

    (void)c;
    while (l[count] != NULL) {
        l[count]->player->incantation_list = l;
        l[count]->player->is_in_incantation = true;
        dprintf(l[count]->fd, "Elevation underway\n");
        count++;
    }
}

void pl_inc_post(main_data_t *m, linked_client_t *c)
{
    size_t count = 0;
    client_t **l = c->client->player->incantation_list;

    (void)m;
    while (l[count] != NULL) {
        l[count]->player->is_in_incantation = false;
        l[count]->player->level++;
        dprintf(l[count]->fd, "Current level: %d\n", l[count]->player->level);
        plv_action(m, l[count]);
        count++;
    }
}

size_t count_same_leve2(main_data_t *m, size_t r, linked_client_t *c)
{
    size_t count = 0;
    int i = 0;
    client_t **l = c->client->player->incantation_list;

    (void)m;
    (void)r;
    if (l == NULL)
        return 0;
    while (l[i] != NULL) {
        if ((l[i]->player->pos->x == c->client->player->pos->x)
            || (l[i]->player->pos->y == c->client->player->pos->y)) {
            count++;
        }
        i++;
    }
    return count;
}
