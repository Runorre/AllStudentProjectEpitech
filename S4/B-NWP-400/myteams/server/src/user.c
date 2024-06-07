/*
** EPITECH PROJECT, 2024
** MyTeams
** File description:
** user
*/

#include "../include/server.h"

void user_com(sm_t *sm, int i, char **argv)
{
    list_user_t *list = sm->list_user;
    char str[62];
    char uuid_str[37];

    if (argv[1] == NULL)
        return my_putsocket("403", sm->client_socket[i]->socketfd);
    uuid_unparse(*list->u->id, uuid_str);
    while (list && strcmp(uuid_str, argv[1]) != 0) {
        list = list->next;
        if (list)
            uuid_unparse(*list->u->id, uuid_str);
    }
    if (!list)
        return my_putsocket("404", sm->client_socket[i]->socketfd);
    sprintf(str, "%s:%s:%i", uuid_str, list->u->name, list->u->connected);
    my_putsocket(str, sm->client_socket[i]->socketfd);
}

void users_com(sm_t *sm, int i, char **argv)
{
    list_user_t *list = sm->list_user;
    char str[62];
    char uuid_str[37];

    while (list) {
        uuid_unparse(*list->u->id, uuid_str);
        sprintf(str, "%s:%s:%i", uuid_str, list->u->name, list->u->connected);
        my_putsocket(str, sm->client_socket[i]->socketfd);
        list = list->next;
    }
    my_putsocket("204", sm->client_socket[i]->socketfd);
}
