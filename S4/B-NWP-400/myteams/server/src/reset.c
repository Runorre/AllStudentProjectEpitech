/*
** EPITECH PROJECT, 2024
** MyTeams
** File description:
** reset
*/

#include "../include/server.h"

void reset_user(sm_t *ms, int i)
{
    list_user_t *list = ms->list_user;
    char uuid_str[37];

    if (ms->client_socket[i]->user) {
        while (list && strcmp(ms->client_socket[i]->user->name,
        list->u->name) != 0)
            list = list->next;
        uuid_unparse(*ms->client_socket[i]->user->id, uuid_str);
        server_event_user_logged_out(uuid_str);
        list->u->connected = false;
    }
}
