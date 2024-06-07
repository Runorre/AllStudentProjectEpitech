/*
** EPITECH PROJECT, 2024
** MyTeams
** File description:
** new_user
*/

#include "../include/server.h"

void create_new_user(sm_t *sm, list_user_t **list, char *name, uuid_t *uuid)
{
    char uuid_str[37];
    char result[200];

    uuid_unparse(*uuid, uuid_str);
    (*list)->u = malloc(sizeof(user_t));
    (*list)->u->name = name;
    (*list)->u->id = uuid;
    (*list)->u->connected = true;
    (*list)->next = NULL;
    sprintf(result, "%s:%s", name, uuid_str);
    appendtofile("./server/data/user.txt", result);
}

void add_new_user(sm_t *sm, list_user_t **list, char *name, uuid_t *uuid)
{
    char uuid_str[37];
    char result[200];

    uuid_unparse(*uuid, uuid_str);
    while ((*list)->next != NULL)
        (*list) = (*list)->next;
    (*list)->next = malloc(sizeof(list_user_t *));
    (*list)->next->u = malloc(sizeof(user_t));
    (*list)->next->u->name = name;
    (*list)->next->u->id = uuid;
    (*list)->next->u->connected = true;
    (*list)->next->next = NULL;
    sprintf(result, "%s:%s", name, uuid_str);
    appendtofile("./server/data/user.txt", result);
}

void new_user(sm_t *sm, int i, char **parms)
{
    list_user_t *list = sm->list_user;
    uuid_t *uuid = malloc(sizeof(uuid_t));
    char uuid_str[37];

    uuid_generate(*uuid);
    uuid_unparse(*uuid, uuid_str);
    if (list == NULL) {
        sm->list_user = malloc(sizeof(list_user_t));
        create_new_user(sm, &sm->list_user, parms[1], uuid);
        list = sm->list_user;
        sm->client_socket[i]->user = list->u;
    } else {
        add_new_user(sm, &list, parms[1], uuid);
        sm->client_socket[i]->user = list->next->u;
    }
    server_event_user_created(uuid_str, parms[1]);
    server_event_user_logged_in(uuid_str);
    my_putsocket(uuid_str, sm->client_socket[i]->socketfd);
}
