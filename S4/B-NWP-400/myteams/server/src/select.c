/*
** EPITECH PROJECT, 2024
** MyTeams
** File description:
** select
*/

#include "../include/server.h"

int select_for_first(sm_t *main_socket, int ac_max_sd)
{
    int i = 0;
    int sd = 0;
    int max_sd = ac_max_sd;

    for (i = 0; i < MAXCLIENT; i++) {
        if (main_socket->client_socket[i])
            sd = main_socket->client_socket[i]->socketfd;
        if (sd > 0)
            FD_SET(sd, &main_socket->readfds);
        if (sd > max_sd)
            max_sd = sd;
    }
    return max_sd;
}

void create_socket(sm_t *main_socket, int new_socket)
{
    int i = 0;

    for (i = 0; i < MAXCLIENT; i++) {
        if (main_socket->client_socket[i] == NULL) {
            main_socket->client_socket[i] = malloc(
                sizeof(*main_socket->client_socket[i]));
            main_socket->client_socket[i]->socketfd = new_socket;
            main_socket->client_socket[i]->authy = 0;
            main_socket->client_socket[i]->user = NULL;
            my_putsocket("200", new_socket);
            break;
        }
    }
}

void new_connection(sm_t *main_socket)
{
    int new_socket = 0;

    if (FD_ISSET(main_socket->socketmaster, &main_socket->readfds)) {
        new_socket = accept(main_socket->socketmaster,
        (struct sockaddr *)&main_socket->addr,
        (socklen_t *) &main_socket->addrlen);
        create_socket(main_socket, new_socket);
    }
}

void action_clients(sm_t *main_socket)
{
    int i = 0;

    for (i = 0; i < MAXCLIENT; i++) {
        if (main_socket->client_socket[i] &&
        FD_ISSET(main_socket->client_socket[i]->socketfd,
        &main_socket->readfds)) {
            action_client(main_socket, i);
        }
    }
}
