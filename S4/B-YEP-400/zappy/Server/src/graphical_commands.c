/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** graphical_commands
*/

#include "../include/server.h"

void msz_function(main_data_t *md, linked_client_t *client, char *args)
{
    int fd = client->client->fd;

    (void)args;
    dprintf(fd, "msz %i %i\n", md->arg->width, md->arg->height);
}

void bct(main_data_t *md, linked_client_t *client, char *args)
{
    int fd = client->client->fd;
    int x = 0;
    int y = 0;

    sscanf(args, "%*s %d %d", &x, &y);
    if ((x < 0) || (x >= md->arg->width)
        || (y < 0) || (y >= md->arg->height)) {
        dprintf(fd, "ko\n");
        return;
    }
    dprintf(fd, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
    md->map[x][y].materials[0], md->map[x][y].materials[1],
    md->map[x][y].materials[2], md->map[x][y].materials[3],
    md->map[x][y].materials[4], md->map[x][y].materials[5],
    md->map[x][y].materials[6]);
}

void bct_function(main_data_t *md, linked_client_t *client, char *args)
{
    bct(md, client, args);
}

void mct_function(main_data_t *md, linked_client_t *client, char *args)
{
    (void)args;
    bct_only(client->client->fd, md->map, md->arg->width, md->arg->height);
}

void tna_function(main_data_t *md, linked_client_t *client, char *args)
{
    int fd = client->client->fd;
    int i = 0;

    (void)args;
    while (i < md->arg->nb_teams) {
        dprintf(fd, "tna %s\n", md->arg->teams[i]);
        i++;
    }
}
