/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** time
*/

#include "../include/server.h"

void queue_user(main_data_t *md, linked_client_t **user)
{
    linked_queue_t *q = (*user)->client->queue;

    if ((q != NULL) && ((!(*user)->client->player->is_in_incantation)
        || (q->queue->action == &incantation_function))) {
        q->queue->time_left--;
        if (q->queue->time_left <= 0) {
            q->queue->action(md, (*user), q->queue->agrs);
            remove_first_node(&(*user)->client->queue);
            (*user)->client->nbr_queue--;
        }
    }
}

void action_user_time(main_data_t *md, linked_client_t **user)
{
    if ((*user)->client->player->life == 0) {
        if ((*user)->client->player->stones->FOOD > 0) {
            (*user)->client->player->life = 126;
            (*user)->client->player->stones->FOOD--;
            pins_event(md, user);
        } else {
            check_stop_incantation(md, user);
            (*user)->client->team_link->nbr_live--;
            write((*user)->client->fd, "dead\n", 5);
            dead_event_graphic(md, user);
            (*user)->client->disconnect = 1;
        }
    } else {
        queue_user(md, user);
        (*user)->client->player->life--;
    }
}

void client_action(main_data_t *md, linked_team_t *tmp)
{
    linked_client_t *destroyer = NULL;

    for (linked_client_t *user = tmp->team_s->list;
    user != NULL; user = user->next) {
        if (destroyer != NULL) {
            delete_client_a_list(md, destroyer->client);
            destroyer = NULL;
        }
        if (user->client->disconnect == 0)
            action_user_time(md, &user);
        else {
            destroyer = user;
        }
    }
    if (destroyer != NULL) {
        delete_client_a_list(md, destroyer->client);
    }
}

void reset_resources(main_data_t *md)
{
    float initial_resources[7] = {0};
    float current_resources[7] = {0};

    calculate_initial_resources(md, initial_resources);
    calculate_current_resources(md, current_resources);
    distribute_new(md, initial_resources, current_resources);
}

void action_time(main_data_t *md)
{
    linked_team_t *tmp = md->list_t;

    if (md->reset_res == 0) {
        reset_resources(md);
        md->reset_res = 20;
        for (linked_client_t *client_node = md->list_g;
        client_node != NULL; client_node = client_node->next) {
        bct_only(
            client_node->client->fd, md->map, md->arg->width, md->arg->height
        );
    }
    }
    if (md->reset_res > 0)
        md->reset_res--;
    for (; tmp != NULL; tmp = tmp->next) {
        client_action(md, tmp);
    }
}
