/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** client_action
*/

#include "../include/server.h"

void limiteur_check(main_data_t *md, linked_client_t *tmp, char *com, int j)
{
    (void)md;
    if (tmp->client->nbr_queue < 10) {
        tmp->client->nbr_queue++;
        add_in_list_queue(&tmp->client->queue,
        add_node_queue(com, waiting_time[j], com_client_f[j]));
    }
}

void command_client(main_data_t *md, linked_client_t *tmp, char *com)
{
    int fd = tmp->client->fd;
    bool is_execute = false;

    (void)md;
    if (strncmp("Incantation", com, 11) == 0)
        is_execute = verif_incan(md, tmp, com);
    if (strncmp("Fork", com, 4) == 0)
        pre_forh_g(md, tmp);
    for (int j = 0; ((com_client_s[j] != NULL) && (!is_execute)); j++) {
        if (strncmp(com_client_s[j], com, strlen(com_client_s[j])) == 0) {
            limiteur_check(md, tmp, com, j);
            is_execute = true;
        }
    }
    if (!is_execute)
        write(fd, "ko\n", 3);
}

void command_graph(main_data_t *md, linked_client_t *tmp, char *com)
{
    int fd = tmp->client->fd;
    bool is_execute = false;

    for (int j = 0; ((com_graph_s[j] != NULL) && (!is_execute)); j++) {
        if (strncmp(com_graph_s[j], com, strlen(com_graph_s[j])) == 0) {
            com_graph_f[j](md, tmp, com);
            is_execute = true;
        }
    }
    if (!is_execute)
        write(fd, "suc\n", 4);
}

void commande_default(main_data_t *md, linked_client_t *tmp, const char *com)
{
    int fd = tmp->client->fd;
    bool is_team = false;

    if (strcmp("GRAPHIC", com) == 0) {
        gteam(md, &tmp);
        is_team = true;
    }
    for (linked_team_t *ttmp = md->list_t;
        ((ttmp != NULL) && (!is_team)); ttmp = ttmp->next) {
        if (strcmp(ttmp->team_s->name, com) == 0) {
            ateam(md, &tmp, &ttmp);
            is_team = true;
        }
    }
    if (!is_team)
        write(fd, "ko\n", 3);
}

void checking_type_client(main_data_t *md, linked_client_t *tmp, char *com)
{
    switch (tmp->client->type) {
        case CLIENT:
            command_client(md, tmp, com);
            break;
        case GRAPHIC:
            command_graph(md, tmp, com);
            break;
        case NOTCONNECT:
            commande_default(md, tmp, com);
            break;
        default:
            commande_default(md, tmp, com);
            break;
    }
}
