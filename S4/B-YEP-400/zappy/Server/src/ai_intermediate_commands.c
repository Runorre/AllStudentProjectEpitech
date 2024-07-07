/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ai_intermediate_commands
*/

#include "../include/server.h"

void connect_nbr_function(main_data_t *md, linked_client_t *client, char *args)
{
    int fd = client->client->fd;
    const team_t *team = client->client->team_link;

    (void)args;
    (void)md;
    dprintf(fd, "%d\n", team->nbr_max_member - team->nbr_member);
}

void update_player_pos(player_t *player, int x, int y)
{
    player->pos->x = x;
    player->pos->y = y;
}

void move_player(main_data_t *md, linked_client_t *client)
{
    int x = client->client->player->pos->x;
    int y = client->client->player->pos->y;

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
    eject_notif(md, client, x, y);
}

void print_result(int fd, bool player_moved)
{
    if (player_moved)
        dprintf(fd, "ok\n");
    else
        dprintf(fd, "ko\n");
}

void eject_function(main_data_t *md, linked_client_t *client, char *args)
{
    Co_t co = {client->client->player->pos->x, client->client->player->pos->y};
    bool player_moved = false;

    (void)args;
    for (linked_client_t *client_tmp = md->net->server_client; client_tmp
        != NULL; client_tmp = client_tmp->next) {
        if ((client_tmp->client->player->pos->x == co.x)
            && (client_tmp->client->player->pos->y == co.y)
            && (client_tmp->client->fd != client->client->fd)) {
            move_player(md, client_tmp);
            dprintf(client_tmp->client->fd, "eject: %i\n",
            show_orientation(client_tmp->client->player->direction));
            player_moved = true;
            destroy_egg_if_exists(client->client->team_link, client_tmp, md);
        }
    }
    print_result(client->client->fd, player_moved);
}
