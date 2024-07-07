/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** broadcast
*/

#include "../include/server.h"

void send_message_everyone(main_data_t *md, linked_client_t *c, char *m)
{
    int i = 0;

    for (linked_client_t *tmp = md->net->server_client;
    tmp != NULL; tmp = tmp->next) {
        if ((tmp->client->id != c->client->id)
            && (tmp->client->type == CLIENT)) {
            i = direction(tmp->client->player->pos, c->client->player->pos,
            md->arg, tmp->client->player->direction);
            dprintf(tmp->client->fd, "message %i, %s\n", i, m);
        }
        if (tmp->client->type == GRAPHIC) {
            dprintf(tmp->client->fd, "pbc %i %s\n", c->client->id, m);
        }
    }
    dprintf(c->client->fd, "ok\n");
}

void broadcast_function(main_data_t *md, linked_client_t *c, char *a)
{
    char *msg = strstr(a, "Broadcast ");

    if ((msg == NULL) || (strlen(a) == strlen("Broadcast "))) {
        dprintf(c->client->fd, "ko\n");
    } else {
        msg += strlen("Broadcast ");
        if (strrchr(msg, '\n') == (msg + (strlen(msg) - 1)))
            msg[strcspn(msg, "\n")] = 0;
        send_message_everyone(md, c, msg);
    }
}
