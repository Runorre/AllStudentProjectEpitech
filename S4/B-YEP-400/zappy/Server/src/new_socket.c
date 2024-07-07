/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** new_socket
*/

#include "../include/server.h"

void delete_in_list_client(linked_client_t **list, client_t *ptr)
{
    linked_client_t *tmp = NULL;

    if (*list == NULL) {
        return;
    }
    if ((*list)->client == ptr) {
        *list = (*list)->next;
        return;
    }
    for (tmp = *list;
        (tmp != NULL) && (tmp->next != NULL) && (tmp->next->client != ptr);
        tmp = tmp->next);
    if ((tmp == NULL) || (tmp->next == NULL)) {
        return;
    }
    tmp->next = tmp->next->next;
}

int delete_list_socket(linked_client_t **list, linked_client_t *ptr, int f)
{
    linked_client_t *tmp = NULL;

    if (*list == ptr) {
        *list = ptr->next;
        if (f == 1)
            free_one_socket(ptr);
        return 0;
    }
    for (tmp = *list; (tmp->next != NULL) && (tmp->next != ptr);
    tmp = tmp->next);
    if (!tmp->next) {
        return 84;
    }
    tmp->next = ptr->next;
    if (f == 1)
        free_one_socket(ptr);
    return 0;
}

int add_in_list_socket(
    linked_client_t **list, linked_client_t *new, main_data_t **md
)
{
    linked_client_t *tmp = NULL;

    if (!new)
        return 84;
    if (!*list) {
        *list = new;
        (*md)->net->last = new;
        return 0;
    }
    tmp = (*md)->net->last;
    tmp->next = new;
    (*md)->net->last = new;
    return 0;
}

linked_client_t *add_node_client(int socket_client, main_data_t *md)
{
    linked_client_t *new = malloc(sizeof(linked_client_t));

    (void)md;
    new->client = malloc(sizeof(client_t));
    new->client->id = 0;
    new->client->fd = socket_client;
    new->client->disconnect = 0;
    new->client->fdpe = fdopen(socket_client, "r+");
    new->client->type = NOTCONNECT;
    new->client->player = NULL;
    new->client->team_link = NULL;
    new->client->queue = NULL;
    new->client->nbr_queue = 0;
    new->next = NULL;
    return new;
}

void new_connection(main_data_t *md)
{
    int new_socket = 0;

    if (FD_ISSET(md->net->sockfd, &md->net->readfds)) {
        new_socket = accept(md->net->sockfd,
        (struct sockaddr *)&md->net->addr_serv,
        &md->net->sock_size);
        add_in_list_socket(&md->net->server_client,
        add_node_client(new_socket, md), &md);
        write(new_socket, "WELCOME\n", 8);
    }
}
