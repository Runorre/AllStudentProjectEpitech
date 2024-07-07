/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** select
*/

#include "../include/server.h"

int select_for_first(network_t *network, int ac_max_sd)
{
    int sd = 0;
    int max_sd = ac_max_sd;

    for (linked_client_t *tmp = network->server_client; tmp != NULL;
    tmp = tmp->next) {
        if (tmp != NULL)
            sd = tmp->client->fd;
        if (sd > 0)
            FD_SET(sd, &network->readfds);
        if (sd > max_sd)
            max_sd = sd;
    }
    return max_sd;
}

void action_client(main_data_t *md, linked_client_t *tmp)
{
    char *line = NULL;
    size_t n = 0;

    if (getline(&line, &n, tmp->client->fdpe) >= 0) {
        line[strcspn(line, "\n")] = 0;
        checking_type_client(md, tmp, line);
    } else {
        free(line);
        if (tmp->client->type == GRAPHIC)
            delete_in_list_client(&md->list_g, tmp->client);
        if (tmp->client->type == CLIENT) {
            tmp->client->team_link->nbr_live--;
            dead_event_graphic(md, &tmp);
        }
        delete_list_socket(&md->net->server_client, tmp, 1);
    }
}

void action_clients(main_data_t *md)
{
    linked_client_t *tmp = md->net->server_client;

    for (; tmp != NULL; tmp = tmp->next) {
        if ((tmp != NULL) &&
        (FD_ISSET(tmp->client->fd,
        &md->net->readfds))) {
            action_client(md, tmp);
        }
    }
}
