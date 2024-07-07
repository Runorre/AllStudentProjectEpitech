/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server
*/

#include "../include/server.h"

void handle_select_result(main_data_t *md, int select_result)
{
    if (select_result == 0)
        action_time(md);
    if (select_result > 0) {
        new_connection(md);
        action_clients(md);
    }
}

void loop_select(main_data_t *md)
{
    int max_sd = 0;
    struct timeval time_val = {0};
    int select_result = 0;
    float interval = 1.0f / (float)md->arg->freq;
    float remaining_usec = 0.0f;

    while (1) {
        FD_ZERO(&md->net->readfds);
        FD_SET(md->net->sockfd, &md->net->readfds);
        max_sd = select_for_first(md->net, md->net->sockfd);
        time_val.tv_sec = (time_t)interval;
        remaining_usec = (interval - (float)time_val.tv_sec) * 1000000;
        time_val.tv_usec = (suseconds_t)remaining_usec;
        select_result = select(max_sd + 1, &md->net->readfds,
        NULL, NULL, &time_val);
        handle_select_result(md, select_result);
    }
}

void server_init(main_data_t *md)
{
    int opt = 1;

    if (setsockopt(md->net->sockfd, SOL_SOCKET, SO_REUSEADDR,
        (char *)&opt, sizeof(opt)) < 0)
        return;
    if (bind(md->net->sockfd,
    (struct sockaddr *) &md->net->addr_serv, md->net->sock_size) == -1)
        return;
    if (listen(md->net->sockfd, 10) == -1)
        return;
    loop_select(md);
}
