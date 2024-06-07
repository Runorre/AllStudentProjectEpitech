/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-angelo.anselmet
** File description:
** dijkstra
*/

#include "../include/lem_in.h"

ant_t *init_ant(int start, int nbr_ant)
{
    ant_t *ant = malloc(sizeof(ant_t));
    ant->pos = start;
    ant->move = 0;
    ant->next = NULL;
    ant->prev_move = start;
    ant->id = 1;
    ant_t *tmp = ant;
    for (int i = 2; i != nbr_ant + 1; i++) {
        ant_t *new = malloc(sizeof(ant_t));
        new->pos = start;
        new->move = 0;
        new->id = i;
        ant->prev_move = start;
        new->next = NULL;
        tmp->next = new;
        tmp = tmp->next;
    }
    return ant;
}

int my_putant(ant_t *ant, int check, hashtable *ht)
{
    if (check == ant->pos)
        return 0;
    my_putchar('P');
    my_putnbr(ant->id);
    my_putchar('-');
    my_putstr(find_name(ht, ant->pos));
    if (ant->next)
        my_putchar(' ');
    return 1;
}

int move_ant(graph_t *grap, int end, ant_t *tmp)
{
    if (tmp->pos == end)
        return 0;
    vertex_t *lowless = NULL;
    for (vertex_t *tmp2 = grap[tmp->pos].vertex; tmp2; tmp2 = tmp2->next) {
        if (!lowless && grap[tmp2->dest].ant == NULL)
            lowless = tmp2;
        if ((lowless && lowless->cost > tmp2->cost)
        && grap[tmp2->dest].ant == NULL)
            lowless = tmp2;
    }
    if (!lowless) return 0;
    if (lowless->dest != end) {
        grap[tmp->pos].ant = NULL;
        tmp->pos = lowless->dest;
        grap[lowless->dest].ant = tmp;
        return 0;
    } else {
        grap[tmp->pos].ant = NULL, tmp->pos = lowless->dest;
        return 1;
    }
}

void dijkstra_main(graph_t *grap, pars_t *parse, hashtable *ht)
{
    int nbr_ant_end = 0, move = 0;
    ant_t *ant = init_ant(parse->pos_begin, parse->nb_ants);
    while (nbr_ant_end != parse->nb_ants) {
        for (ant_t *tmp = ant; tmp; tmp = tmp->next) {
            int check = tmp->pos;
            nbr_ant_end += move_ant(grap, parse->pos_end, tmp);
            move += my_putant(tmp, check, ht);
        }
        if (move != 0) {
            my_putchar('\n');
            move = 0;
        }
    }
}
