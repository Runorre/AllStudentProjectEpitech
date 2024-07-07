/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** egg
*/

#include "../include/server.h"

void add_egg_to_end(egg_node_t *new, egg_node_t **last)
{
    egg_node_t *tmp = *last;

    tmp->next = new;
    *last = new;
}

void remove_head_egg(egg_node_t **eggs)
{
    egg_node_t *next_egg = NULL;
    egg_node_t *current = NULL;

    next_egg = (*eggs)->next;
    (*eggs)->next = NULL;
    current = *eggs;
    *eggs = next_egg;
    free(current);
}

bool egg_in_team(team_t *team, int x, int y)
{
    egg_node_t *current = team->eggs;

    while (current != NULL) {
        if ((current->egg->x == x) && (current->egg->y == y)) {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool egg_at_position(main_data_t *md, int x, int y)
{
    linked_team_t *tmp = md->list_t;

    while (tmp != NULL) {
        if (egg_in_team(tmp->team_s, x, y))
            return true;
        tmp = tmp->next;
    }
    return false;
}

void destroy_egg_if_exists(team_t *team, linked_client_t *c, main_data_t *md)
{
    egg_node_t **current = &team->eggs;
    egg_node_t *next = NULL;

    while (*current != NULL) {
        if (((*current)->egg->x == c->client->player->pos->x)
        && ((*current)->egg->y == c->client->player->pos->y)) {
            egg_graph(md, (*current));
            next = (*current)->next;
            free((*current)->egg);
            free(*current);
            *current = next;
            team->nbr_max_member--;
        } else {
            current = &(*current)->next;
        }
    }
}
