/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ai_base_commande_cs
*/

#include "../include/server.h"

void cs_ai(main_data_t *md, linked_client_t *client, int x, int y)
{
    switch (client->client->player->direction) {
        case UP:
            y = (y == 0) ? (md->arg->height - 1) : (y - 1);
            break;
        case RIGHT:
            x = (x == (md->arg->width - 1)) ? 0 : (x + 1);
            break;
        case DOWN:
            y = (y == (md->arg->height - 1)) ? 0 : (y + 1);
            break;
        case LEFT:
            x = (x == 0) ? (md->arg->width - 1) : (x - 1);
            break;
        default:
            break;
    }
    print_forward(client, x, y);
}
