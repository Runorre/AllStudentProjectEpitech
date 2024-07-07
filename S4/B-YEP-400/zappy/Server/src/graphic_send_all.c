/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** graphic_send_all
*/

#include "../include/server.h"

void pin_event(int fd, linked_client_t *p)
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

void connection_g(main_data_t *md, linked_client_t *p, egg_node_t *e)
{
    for (linked_client_t *tmp2 = md->list_g; tmp2 != NULL; tmp2 = tmp2->next) {
        dprintf(tmp2->client->fd, "pnw %i %i %i %i %i %s\n", p->client->id,
        e->egg->x, e->egg->y,
        show_orientation(p->client->player->direction),
        p->client->player->level, p->client->team_link->name);
        pin_event(tmp2->client->fd, p);
        dprintf(tmp2->client->fd, "ebo %i\n", e->egg->id);
    }
}

void bct_only(int fd, map_t **map, int widght, int height)
{
    for (int x = 0; x != widght; x++) {
        for (int y = 0; y != height; y++) {
            dprintf(fd, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
            map[x][y].materials[0], map[x][y].materials[1],
            map[x][y].materials[2], map[x][y].materials[3],
            map[x][y].materials[4], map[x][y].materials[5],
            map[x][y].materials[6]);
        }
    }
}

void init_team_graphic(const main_data_t *md, linked_client_t **c)
{
    for (linked_team_t *tmp = md->list_t; tmp != NULL; tmp = tmp->next) {
        for (egg_node_t *tegg = tmp->team_s->eggs;
            tegg != NULL; tegg = tegg->next) {
            dprintf(
                (*c)->client->fd, "enw %i -1 %i %i\n",
                tegg->egg->id, tegg->egg->x, tegg->egg->y
            );
        }
        for (linked_client_t *tc = tmp->team_s->list; tc != NULL;
        tc = tc->next) {
            dprintf((*c)->client->fd, "pnw %i %i %i %i %s\n", tc->client->id,
            tc->client->player->pos->x, tc->client->player->pos->y,
            show_orientation(tc->client->player->direction),
            tc->client->team_link->name);
            pin_event((*c)->client->fd, tc);
        }
    }
}
