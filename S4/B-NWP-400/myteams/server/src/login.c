/*
** EPITECH PROJECT, 2024
** MyTeams
** File description:
** login
*/

#include "../include/server.h"

void check_security_login(sm_t *sm, int i, list_user_t *list)
{
    char uuid_str[37];

    if (list->u->connected == false) {
        list->u->connected = true;
        sm->client_socket[i]->user = list->u;
        uuid_unparse(*list->u->id, uuid_str);
        my_putsocket(uuid_str, sm->client_socket[i]->socketfd);
        server_event_user_logged_in(uuid_str);
        sm->client_socket[i]->authy = TRUE;
    } else {
        sm->client_socket[i]->authy = FALSE;
        my_putsocket("409", sm->client_socket[i]->socketfd);
    }
}

void login_com(sm_t *sm, int i, char **parms)
{
    list_user_t *list = sm->list_user;

    if (list == NULL) {
        new_user(sm, i, parms);
    } else {
        while (list && strcmp(parms[1], list->u->name) != 0)
            list = list->next;
        if (list == NULL) {
            new_user(sm, i, parms);
            sm->client_socket[i]->authy = TRUE;
        } else {
            check_security_login(sm, i, list);
        }
    }
}
