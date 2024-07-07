/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** pin
*/

#include "../include/server.h"

void pin_function(main_data_t *md, linked_client_t *client_list, char *args)
{
    char *endptr = NULL;
    long client_id = strtol(args + 4, &endptr, 10);
    const linked_client_t *client = NULL;

    (void)md;
    if (*endptr != '\0')
        return;
    client = find_client_by_id(client_list, client_id);
    if ((client != NULL) && (client->client != NULL)
        && (client->client->player != NULL)) {
        pin(client_list->client->fd, client);
    } else {
        dprintf(client_list->client->fd, "ko\n");
    }
}
