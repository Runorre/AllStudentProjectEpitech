/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** graphical_time
*/

#include "../include/server.h"

void sgt_function(main_data_t *md, linked_client_t *client, char *args)
{
    int fd = client->client->fd;

    (void)args;
    dprintf(fd, "sgt %d\n", md->arg->freq);
}

void sst_function(main_data_t *md, linked_client_t *client, char *args)
{
    int fd = client->client->fd;
    char *endptr = NULL;
    long freq = 0;

    args += 4;
    freq = strtol(args, &endptr, 10);
    if ((*endptr != '\0') || (freq < 0)) {
        dprintf(fd, "sst %d\n", md->arg->freq);
        return;
    }
    md->arg->freq = (int)freq;
    dprintf(fd, "sst %d\n", md->arg->freq);
}
