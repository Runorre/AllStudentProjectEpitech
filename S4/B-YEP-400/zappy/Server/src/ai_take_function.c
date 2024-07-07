/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ai_take_and_set
*/

#include "../include/server.h"

void increment_material(player_t *player, char *arg)
{
    const char *material_name = strstr(arg, "Take ");

    if (material_name == NULL) {
        return;
    }
    material_name += 5;
    if (strcmp(material_name, "linemate") == 0)
        player->stones->LINEMATE++;
    if (strcmp(material_name, "deraumere") == 0)
        player->stones->DERAUMERE++;
    if (strcmp(material_name, "sibur") == 0)
        player->stones->SIBUR++;
    if (strcmp(material_name, "mendiane") == 0)
        player->stones->MENDIANE++;
    if (strcmp(material_name, "phiras") == 0)
        player->stones->PHIRAS++;
    if (strcmp(material_name, "thystame") == 0)
        player->stones->THYSTAME++;
    if (strcmp(material_name, "food") == 0)
        player->stones->FOOD++;
}

material_t string_to_material(char *arg)
{
    const char *material_name = strstr(arg, "Take ");

    if (material_name == NULL)
        return NOTHING;
    material_name += 5;
    if (strcmp(material_name, "linemate") == 0)
        return LINEMATE;
    if (strcmp(material_name, "deraumere") == 0)
        return DERAUMERE;
    if (strcmp(material_name, "sibur") == 0)
        return SIBUR;
    if (strcmp(material_name, "mendiane") == 0)
        return MENDIANE;
    if (strcmp(material_name, "phiras") == 0)
        return PHIRAS;
    if (strcmp(material_name, "thystame") == 0)
        return THYSTAME;
    if (strcmp(material_name, "food") == 0)
        return FOOD;
    return NOTHING;
}

void take_function(main_data_t *md, linked_client_t *client, char *arg)
{
    int fd = client->client->fd;
    int x = client->client->player->pos->x;
    int y = client->client->player->pos->y;
    material_t material = string_to_material(arg);

    if (material == NOTHING) {
        dprintf(fd, "ko\n");
        return;
    }
    if (md->map[x][y].materials[material] > 0) {
        md->map[x][y].materials[material]--;
        increment_material(client->client->player, arg);
        take_graph(md, client, material);
        dprintf(fd, "ok\n");
    } else
        dprintf(fd, "ko\n");
}
