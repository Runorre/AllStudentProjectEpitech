/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** player
*/

#include "../include/server.h"

player_t *allocate_player(egg_node_t *egg_node)
{
    player_t *player = malloc(sizeof(player_t));
    int random_direction = rand() % 4;

    player->pos = malloc(sizeof(pos_t));
    player->pos->x = egg_node->egg->x;
    player->pos->y = egg_node->egg->y;
    player->level = 1;
    player->life = 0;
    player->direction = (direction_t)random_direction;
    player->is_in_incantation = false;
    player->stones = malloc(sizeof(inventory_t));
    player->incantation_list = NULL;
    player->stones->LINEMATE = 0;
    player->stones->DERAUMERE = 0;
    player->stones->SIBUR = 0;
    player->stones->MENDIANE = 0;
    player->stones->PHIRAS = 0;
    player->stones->THYSTAME = 0;
    player->stones->FOOD = 10;
    return player;
}

int add_in_user_in_list(linked_client_t **list, client_t **client)
{
    linked_client_t *tmp = NULL;
    linked_client_t *new = malloc(sizeof(linked_client_t));

    new->client = (*client);
    new->next = NULL;
    if (!*list) {
        *list = new;
        return 0;
    }
    for (tmp = *list; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new;
    return 0;
}

int player_at_position2(int x, int y, int *count, linked_client_t *tmp)
{
    if ((tmp->client->type == CLIENT) && (tmp->client->player->pos->x == x)
        && (tmp->client->player->pos->y == y)) {
        (*count)++;
        if ((*count) == 6) {
            return (*count);
        }
    }
    return -1;
}

int player_at_position(main_data_t *md, int x, int y)
{
    int count = 0;
    linked_client_t *tmp = md->net->server_client;

    if (md == NULL) {
        return count;
    }
    while (tmp != NULL) {
        if (player_at_position2(x, y, &count, tmp) == 6) {
            return count;
        }
        tmp = tmp->next;
    }
    return count;
}
