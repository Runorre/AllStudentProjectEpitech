/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ai_actions
*/

#include "../include/server.h"

const char *material_to_string(material_t material)
{
    switch (material) {
        case FOOD:
            return "food";
        case LINEMATE:
            return "linemate";
        case DERAUMERE:
            return "deraumere";
        case SIBUR:
            return "sibur";
        case MENDIANE:
            return "mendiane";
        case PHIRAS:
            return "phiras";
        case THYSTAME:
            return "thystame";
        case NOTHING:
            return "";
        default:
            return "";
    }
}

void position(main_data_t *md, linked_client_t *client, Co_t *co, Off_t *off)
{
    switch (client->client->player->direction) {
        case UP:
            upper(md, client, co, off);
            break;
        case RIGHT:
            right(md, client, co, off);
            break;
        case DOWN:
            down(md, client, co, off);
            break;
        case LEFT:
            left(md, client, co, off);
            break;
        default:
            break;
    }
}

void append_materials(main_data_t *md, string_t *result, int x, int y)
{
    char *buffer = NULL;

    for (int m = 0; m < 7; m++) {
        for (int n = 0; n < md->map[x][y].materials[m]; n++) {
            asprintf(&buffer, " %s", material_to_string((material_t)m));
            string_append(result, buffer);
            free(buffer);
        }
    }
}

void pro_visio(
    main_data_t *md, linked_client_t *client, string_t *result, int i
)
{
    Co_t coords = {0};
    Off_t offset = {0};
    int player_on_tile = 0;

    for (int j = -i; j <= i; j++) {
        offset.i = i;
        offset.j = j;
        position(md, client, &coords, &offset);
        if (egg_at_position(md, coords.x, coords.y)) {
            string_append(result, " egg");
        }
        player_on_tile = player_at_position(md, coords.x, coords.y);
        for (int k = 0; k < player_on_tile; k++) {
            string_append(result, " player");
        }
        append_materials(md, result, coords.x, coords.y);
        string_append(result, ",");
    }
}

void look_function(main_data_t *md, linked_client_t *client, char *args)
{
    int fd = client->client->fd;
    int vision = client->client->player->level;
    string_t result = {0};

    (void)args;
    string_init(&result);
    string_append(&result, "[");
    for (int i = 0; i <= vision; i++) {
        pro_visio(md, client, &result, i);
    }
    string_append(&result, " ]");
    dprintf(fd, "%s\n", result.data);
    string_free(&result);
}
