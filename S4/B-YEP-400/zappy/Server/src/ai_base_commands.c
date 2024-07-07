/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ai_commands
*/

#include "../include/server.h"

void print_forward(linked_client_t *client, int x, int y)
{
    client->client->player->pos->x = x;
    client->client->player->pos->y = y;
    write(client->client->fd, "ok\n", 3);
}

void forward_function(main_data_t *md, linked_client_t *client, char *args)
{
    int x = client->client->player->pos->x;
    int y = client->client->player->pos->y;

    (void)args;
    cs_ai(md, client, x, y);
    player_pos_graph(md, client);
}

void right_function(
    main_data_t *md, linked_client_t *client, char *args
)
{
    (void)md;
    (void)args;
    switch (client->client->player->direction) {
        case UP:
            client->client->player->direction = RIGHT;
            break;
        case RIGHT:
            client->client->player->direction = DOWN;
            break;
        case DOWN:
            client->client->player->direction = LEFT;
            break;
        case LEFT:
            client->client->player->direction = UP;
            break;
        default:
            break;
    }
    write(client->client->fd, "ok\n", 3);
    player_pos_graph(md, client);
}

void left_function(
    main_data_t *md, linked_client_t *client, char *args
)
{
    (void)md;
    (void)args;
    switch (client->client->player->direction) {
        case UP:
            client->client->player->direction = LEFT;
            break;
        case RIGHT:
            client->client->player->direction = UP;
            break;
        case DOWN:
            client->client->player->direction = RIGHT;
            break;
        case LEFT:
            client->client->player->direction = DOWN;
            break;
        default:
            break;
    }
    write(client->client->fd, "ok\n", 3);
    player_pos_graph(md, client);
}

void inventory_function(main_data_t *md, linked_client_t *client, char *args)
{
    int fd = client->client->fd;

    (void)md;
    (void)args;
    dprintf(fd, "[ linemate %d, deraumere %d, sibur %d, mendiane %d, "
    "phiras %d, thystame %d, food %d ]\n",
    client->client->player->stones->LINEMATE,
    client->client->player->stones->DERAUMERE,
    client->client->player->stones->SIBUR,
    client->client->player->stones->MENDIANE,
    client->client->player->stones->PHIRAS,
    client->client->player->stones->THYSTAME,
    client->client->player->stones->FOOD);
}
