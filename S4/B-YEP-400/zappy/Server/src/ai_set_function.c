/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ai_set_function
*/

#include "../include/server.h"

material_t set_to_material(char *arg)
{
    const char *material_name = strstr(arg, "Set ");

    if (material_name == NULL)
        return NOTHING;
    material_name += 4;
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

void decrement_material(player_t *player, char *arg)
{
    const char *material_name = strstr(arg, "Set ");

    if (material_name == NULL) {
        return;
    }
    material_name += 4;
    if (strcmp(material_name, "linemate") == 0)
        player->stones->LINEMATE--;
    if (strcmp(material_name, "deraumere") == 0)
        player->stones->DERAUMERE--;
    if (strcmp(material_name, "sibur") == 0)
        player->stones->SIBUR--;
    if (strcmp(material_name, "mendiane") == 0)
        player->stones->MENDIANE--;
    if (strcmp(material_name, "phiras") == 0)
        player->stones->PHIRAS--;
    if (strcmp(material_name, "thystame") == 0)
        player->stones->THYSTAME--;
    if (strcmp(material_name, "food") == 0)
        player->stones->FOOD--;
}

int get_material_count(inventory_t *stones, material_t material)
{
    if (material == LINEMATE)
        return stones->LINEMATE;
    if (material == DERAUMERE)
        return stones->DERAUMERE;
    if (material == SIBUR)
        return stones->SIBUR;
    if (material == MENDIANE)
        return stones->MENDIANE;
    if (material == PHIRAS)
        return stones->PHIRAS;
    if (material == THYSTAME)
        return stones->THYSTAME;
    if (material == FOOD)
        return stones->FOOD;
    return 0;
}

void set_function(main_data_t *md, linked_client_t *client, char *arg)
{
    int fd = client->client->fd;
    int x = client->client->player->pos->x;
    int y = client->client->player->pos->y;
    material_t material = set_to_material(arg);

    if (material == NOTHING) {
        dprintf(fd, "ko\n");
        return;
    }
    if (get_material_count(client->client->player->stones, material) > 0) {
        decrement_material(client->client->player, arg);
        set_graph(md, client, material);
        md->map[x][y].materials[material]++;
        dprintf(fd, "ok\n");
    } else
        dprintf(fd, "ko\n");
}
