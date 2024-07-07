/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ai_fork
*/

#include "../include/server.h"

size_t count_same_level(
    main_data_t *m, size_t r, linked_client_t *c, client_t **l
)
{
    size_t count = 0;
    linked_client_t *tmp = m->net->server_client;

    while ((tmp != NULL) && (count < r)) {
        if ((tmp->client->type == CLIENT)
            && (tmp->client->player->level == c->client->player->level)
            && (tmp->client->player->pos->x == c->client->player->pos->x)
            && (tmp->client->player->pos->y == c->client->player->pos->y)
            && (!tmp->client->player->is_in_incantation)
            && (count < r)) {
            l[count] = tmp->client;
            count++;
        }
        tmp = tmp->next;
    }
    l[count] = NULL;
    return count;
}

void add_egg_in_list(
    egg_node_t **eggs, egg_t *egg, main_data_t *md, egg_node_t **last
)
{
    egg_node_t *new = malloc(sizeof(egg_node_t));
    egg_node_t *tmp = *last;

    (void)md;
    new->egg = egg;
    new->next = NULL;
    if (!*eggs) {
        *eggs = new;
        *last = *eggs;
        return;
    }
    tmp->next = new;
    *last = new;
}

void fork_function(main_data_t *md, linked_client_t *client, char *args)
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
    dprintf(client->client->fd, "ok\n");
    enw_graph(md, client, client->client->team_link->eggs);
}
