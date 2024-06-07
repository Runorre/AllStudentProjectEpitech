/*
** EPITECH PROJECT, 2024
** MyTeams
** File description:
** main
*/

#include "../include/server.h"

//TODO separator :

int loop_select(sm_t *main_socket)
{
    int max_sd = 0;
    int activity = 0;

    while (TRUE) {
        FD_ZERO(&main_socket->readfds);
        FD_SET(main_socket->socketmaster, &main_socket->readfds);
        max_sd = main_socket->socketmaster;
        max_sd = select_for_first(main_socket, max_sd);
        activity = select(max_sd + 1, &main_socket->readfds,
        NULL, NULL, NULL);
        new_connection(main_socket);
        action_clients(main_socket);
    }
}

int init_server2(sm_t *main_socket)
{
    int opt = TRUE;
    int i = 0;

    for (i; i < MAXCLIENT; i++)
        main_socket->client_socket[i] = NULL;
    if (setsockopt(main_socket->socketmaster, SOL_SOCKET, SO_REUSEADDR,
        (char *)&opt, sizeof(opt)) < 0)
        return 84;
    if (bind(main_socket->socketmaster,
    (struct sockaddr *) &main_socket->addr, main_socket->addrlen) == -1)
        return 84;
    if (listen(main_socket->socketmaster, 10) == -1)
        return 84;
    return init_users(main_socket);
}

int init_server(char *port)
{
    int i = 0;
    sm_t *main_socket = malloc(sizeof(sm_t));

    main_socket->port = atoi(port);
    main_socket->addrlen = sizeof(main_socket->addr);
    main_socket->socketmaster = socket(AF_INET, SOCK_STREAM, 6);
    if (main_socket->socketmaster == -1)
        return 84;
    main_socket->addr.sin_family = AF_INET;
    main_socket->addr.sin_addr.s_addr = INADDR_ANY;
    main_socket->addr.sin_port = htons(main_socket->port);
    main_socket->client_socket = malloc(
        sizeof(*main_socket->client_socket) * 100);
    return init_server2(main_socket);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    if (!is_all_digits(argv[1]))
        return 84;
    return init_server(argv[1]);
}
