/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** graphical_player
*/

#include "../include/server.h"

int show_orientation(direction_t orientation)
{
    switch (orientation) {
        case UP:
            return 3;
        case RIGHT:
            return 2;
        case DOWN:
            return 1;
        case LEFT:
            return 4;
        default:
            return 0;
    }
    return 0;
}

linked_client_t *find_client_by_id(
    linked_client_t *client_list, long client_id
)
{
    linked_client_t *current = client_list;

    while (current != NULL) {
        if (current->client->id == client_id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void ppo_function(main_data_t *md, linked_client_t *client_list, char *args)
{
    int fd = client_list->client->fd;
    char *endptr = NULL;
    long client_id = strtol(args + 4, &endptr, 10);
    const linked_client_t *client = NULL;

    (void)md;
    if (*endptr != '\0') {
        return;
    }
    client = find_client_by_id(client_list, client_id);
    if ((client != NULL) && (client->client != NULL)
        && (client->client->player != NULL)) {
        dprintf(fd, "ppo %ld %d %d %d\n", client_id,
        client->client->player->pos->x, client->client->player->pos->y,
        show_orientation(client->client->player->direction));
    } else {
        dprintf(fd, "ko\n");
    }
}

void plv_function(main_data_t *md, linked_client_t *client_list, char *args)
{
    int fd = client_list->client->fd;
    char *endptr = NULL;
    long client_id = strtol(args + 4, &endptr, 10);
    const linked_client_t *client = NULL;

    (void)md;
    if (*endptr != '\0') {
        return;
    }
    client = find_client_by_id(client_list, client_id);
    if ((client != NULL) && (client->client != NULL)
        && (client->client->player != NULL)) {
        dprintf(fd, "plv %ld %d\n", client_id,
        client->client->player->level);
    } else {
        dprintf(fd, "ko\n");
    }
}

void pin(int fd, const linked_client_t *p)
{
    dprintf(fd, "pin %d %d %d %d %d %d %d %d %d %d\n", p->client->id,
            p->client->player->pos->x, p->client->player->pos->y,
            p->client->player->stones->FOOD,
            p->client->player->stones->LINEMATE,
            p->client->player->stones->DERAUMERE,
            p->client->player->stones->SIBUR,
            p->client->player->stones->MENDIANE,
            p->client->player->stones->PHIRAS,
            p->client->player->stones->THYSTAME);
}
