/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** team
*/

#include "../include/server.h"

void create_team(main_data_t *md)
{
    for (int i = 0; md->arg->teams[i] != NULL; i++) {
        add_in_list_team(&md->list_t, md->arg->teams[i], md);
    }
}

void gteam(main_data_t *md, linked_client_t **tmp)
{
    (*tmp)->client->type = GRAPHIC;
    (*tmp)->client->team_link = NULL;
    (*tmp)->client->id = 0;
    add_in_user_in_list(&md->list_g, &(*tmp)->client);
    dprintf((*tmp)->client->fd, "msz %i %i\nsgt %i\n",
        md->arg->width, md->arg->height, md->arg->freq);
    bct_only((*tmp)->client->fd, md->map, md->arg->width, md->arg->height);
    init_team_graphic(md, tmp);
}

void ateam(main_data_t *md, linked_client_t **tmp, linked_team_t **t)
{
    egg_node_t *egg = NULL;

    if ((*t)->team_s->nbr_member < (*t)->team_s->nbr_max_member) {
        egg = (*t)->team_s->eggs;
        md->net->id++;
        (*t)->team_s->nbr_member++;
        (*tmp)->client->team_link = (*t)->team_s;
        (*tmp)->client->type = CLIENT;
        (*tmp)->client->id = md->net->id;
        (*t)->team_s->nbr_live++;
        dprintf((*tmp)->client->fd, "%i\n%i %i\n",
        ((*t)->team_s->nbr_max_member - (*t)->team_s->nbr_member),
        md->arg->width, md->arg->height);
        (*tmp)->client->player = allocate_player(egg);
        connection_g(md, (*tmp), egg);
        remove_head_egg(&(*t)->team_s->eggs);
        add_in_user_in_list(&(*t)->team_s->list, &(*tmp)->client);
    } else {
        write((*tmp)->client->fd, "ko\n", 3);
    }
}

void init_eggs(egg_node_t **egg, int nbr_max, main_data_t *md, egg_node_t **l)
{
    egg_node_t *new = NULL;

    *egg = NULL;
    for (int i = 0; i < nbr_max; i++) {
        new = malloc(sizeof(egg_node_t));
        new->egg = malloc(sizeof(egg_t));
        new->egg->x = rand() % md->arg->width;
        new->egg->y = rand() % md->arg->height;
        md->egg_id++;
        new->egg->id = md->egg_id;
        new->next = NULL;
        if (*egg == NULL) {
            *egg = new;
            *l = *egg;
        } else {
            add_egg_to_end(new, l);
        }
    }
}

void add_in_list_team(linked_team_t **list, char *name, main_data_t *md)
{
    linked_team_t *tmp = NULL;
    linked_team_t *new = malloc(sizeof(linked_team_t));

    new->team_s = malloc(sizeof(team_t));
    new->team_s->name = name;
    new->team_s->nbr_member = 0;
    new->team_s->nbr_live = 0;
    new->team_s->nbr_max_member = md->arg->clientsNb;
    new->team_s->list = NULL;
    new->team_s->last = NULL;
    init_eggs(
        &new->team_s->eggs,
        new->team_s->nbr_max_member, md, &new->team_s->last
    );
    new->next = NULL;
    if (*list != NULL) {
        for (tmp = (*list); tmp->next != NULL; tmp = tmp->next);
        tmp->next = new;
    } else
        *list = new;
}
