/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ai_direction
*/

#include "../include/server.h"

void upper(main_data_t *md, linked_client_t *client, Co_t *co, Off_t *offset)
{
    int x = client->client->player->pos->x;
    int y = client->client->player->pos->y;

    co->x = (x + offset->j + md->arg->width) % md->arg->width;
    co->y = ((y - offset->i) + md->arg->height) % md->arg->height;
}

void right(main_data_t *md, linked_client_t *client, Co_t *co, Off_t *offset)
{
    int x = client->client->player->pos->x;
    int y = client->client->player->pos->y;

    co->x = (x + offset->i + md->arg->width) % md->arg->width;
    co->y = (y + offset->j + md->arg->height) % md->arg->height;
}

void down(main_data_t *md, linked_client_t *client, Co_t *co, Off_t *offset)
{
    int x = client->client->player->pos->x;
    int y = client->client->player->pos->y;

    co->x = ((x - offset->j) + md->arg->width) % md->arg->width;
    co->y = (y + offset->i + md->arg->height) % md->arg->height;
}

void left(main_data_t *md, linked_client_t *client, Co_t *co, Off_t *offset)
{
    int x = client->client->player->pos->x;
    int y = client->client->player->pos->y;

    co->x = ((x - offset->i) + md->arg->width) % md->arg->width;
    co->y = ((y - offset->j) + md->arg->height) % md->arg->height;
}
