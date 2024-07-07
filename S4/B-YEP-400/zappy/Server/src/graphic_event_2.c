/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** graphic_event_2
*/

#include "../include/server.h"

//Fonction pour le cs qui sert a afficher au graphique les id incantation
void cs_chec(char **str, linked_client_t *c, client_t *tmp)
{
    char *tmp_str = NULL;
    char *old_str = NULL;

    (void)c;
    asprintf(&tmp_str, " %i", tmp->id);
    old_str = *str;
    asprintf(str, "%s%s", old_str != NULL ? old_str : "", tmp_str);
    free(old_str);
    free(tmp_str);
}

void write_all_inc_g(
    char **str, main_data_t *md, linked_client_t *c, client_t **l
)
{
    (void)md;
    for (int i = 0; l[i] != NULL; i++) {
        cs_chec(str, c, l[i]);
    }
}

void graph_end_inc(main_data_t *md, linked_client_t *c, int r)
{
    for (linked_client_t *tmp = md->list_g; tmp != NULL; tmp = tmp->next) {
        dprintf(tmp->client->fd, "pie %i %i %i\n", c->client->player->pos->x,
        c->client->player->pos->y, r);
    }
}

void pre_forh_g(main_data_t *md, linked_client_t *c)
{
    for (linked_client_t *tmp = md->list_g; tmp != NULL; tmp = tmp->next) {
        dprintf(tmp->client->fd, "pfk %i\n", c->client->id);
    }
}

void take_graph(main_data_t *md, linked_client_t *c, material_t mat)
{
    for (linked_client_t *tmp = md->list_g; tmp != NULL; tmp = tmp->next) {
        dprintf(tmp->client->fd, "pgt %i %i\n", c->client->id, (int)mat);
        pin_event(tmp->client->fd, c);
    }
}
