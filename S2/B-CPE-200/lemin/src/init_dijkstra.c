/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-angelo.anselmet
** File description:
** dijkstra
*/
#include "../include/lem_in.h"

vertex_t *backtoback(graph_t *graph, vertex_t *tmp, int origine, int cost)
{
    vertex_t *tmp2 = graph[tmp->dest].vertex;
    while (tmp2->dest != origine) {
        tmp2 = tmp2->next;
    }
    if (tmp2)
        tmp2->cost = cost;
    return tmp2;
}

waiting_t *assigncost(graph_t *graph, vertex_t *vertex, waiting_t *wait)
{
    for (vertex_t *tmp = vertex; tmp; tmp = tmp->next) {
        if (tmp->cost == 0) {
            tmp->cost = wait->cost;
            backtoback(graph, tmp, wait->value, wait->cost);
            wait = addnode(wait, tmp->dest, wait->cost);
        }
    }
    return wait;
}

waiting_t *addnode(waiting_t *current, int where, int cost)
{
    waiting_t *tmp2 = current;
    for (waiting_t *tmp = current; tmp; tmp = tmp->next) {
        if (tmp->value == where)
            return current;
    }
    while (tmp2 && tmp2->next != NULL)
        tmp2 = tmp2->next;
    waiting_t *new = malloc(sizeof(waiting_t));
    new->value = where;
    new->next = NULL;
    new->cost = cost + 1;
    if (current) {
        new->prev = current;
        tmp2->next = new;
        return current;
    } else {
        new->prev = NULL;
        return new;
    }
}

int init_moves(arcs_t *arc, pars_t *parse, int iter_hash, hashtable *ht)
{
    int error = 0;
    graph_t *graph = init_graph(arc, iter_hash);
    if (arc == NULL)
        return 1;
    error = init_dijkstra(graph, parse, ht);
    free_graph(graph);
    return error;
}

int init_dijkstra(graph_t *graph, pars_t *parse, hashtable *ht)
{
    waiting_t *wait = addnode(NULL, parse->pos_end, 0);
    while (wait) {
        wait = assigncost(graph, graph[wait->value].vertex, wait);
        wait = wait->next;
    }
    if (start_not_connected_to_end(graph, parse->pos_begin))
        return 1;
    dijkstra_main(graph, parse, ht);
    return (0);
}
