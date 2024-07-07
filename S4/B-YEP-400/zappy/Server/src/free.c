/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** free
*/

#include "../include/server.h"

void delete_client_a_list(main_data_t *md, client_t *client)
{
    linked_client_t *tmp = NULL;

    for (tmp = md->net->server_client;
        ((tmp->next != NULL) && (tmp->client != client)); tmp = tmp->next);
    if (tmp != NULL) {
        delete_list_socket(&md->net->server_client, tmp, 1);
    }
}

void free_one_socket(linked_client_t *ptr)
{
    fclose(ptr->client->fdpe);
    if (ptr->client->team_link != NULL) {
        delete_in_list_client(&ptr->client->team_link->list, ptr->client);
        ptr->client->team_link = NULL;
    }
    close(ptr->client->fd);
    free(ptr->client->player);
    free(ptr->client);
    ptr = NULL;
}
