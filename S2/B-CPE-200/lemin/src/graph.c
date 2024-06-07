/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-angelo.anselmet
** File description:
** graph
*/

#include "../include/lem_in.h"

void print_arcs(arcs_t* head)
{
    arcs_t* tmp = head;
    while (tmp != NULL) {
        my_putnbr(tmp->src), my_putstr(" -> "), my_putnbr(tmp->dest);
        my_putchar('\n');
        tmp = tmp->next;
    }
}

arcs_t* add_arcs(arcs_t* head, int src, int dest, int oriented)
{
    arcs_t* tmp = malloc(sizeof(arcs_t));
    tmp->src = src;
    tmp->dest = dest;
    if (head == NULL) {
        tmp->next = NULL;
        if (!oriented) {
            tmp = add_arcs(tmp, dest, src, 1);
        }
        return tmp;
    }
    tmp->next = head;
    if (!oriented) {
        tmp = add_arcs(tmp, dest, src, 1);
    }
    return tmp;
}

vertex_t* add_vertex(vertex_t* head, int dest)
{
    vertex_t* tmp = malloc(sizeof(vertex_t));
    tmp->dest = dest;
    if (head == NULL) {
        tmp->next = NULL;
        tmp->cost = 0;
        return tmp;
    }
    tmp->next = head;
    tmp->cost = 0;
    return tmp;
}

void print_graph(graph_t* graph)
{
    int i = 0;
    vertex_t* tmp;
    while (i < graph->n_vertex) {
        tmp = graph[i].vertex;
        my_printf("VERTEX %d\t", i);
        while (tmp != NULL) {
            my_printf("%d - %i -> %d\t\t", i, tmp->cost ,tmp->dest);
            tmp = tmp->next;
        }
        my_printf("\n");
        i ++;
    }
}

graph_t* init_graph(arcs_t* arcs, int n_vertex)
{
    graph_t* graph = malloc(sizeof(graph_t) * n_vertex + sizeof(graph_t));
    int i = 0;
    while (i < n_vertex + 1) {
        graph[i].vertex = NULL;
        i ++;
    }
    graph->n_vertex = n_vertex;
    arcs_t* tmp = arcs;
    while (tmp != NULL) {
        int src = tmp->src;
        int dest = tmp->dest;
        graph[src].vertex = add_vertex(graph[src].vertex, dest);
        graph[src].ant = NULL;
        tmp = tmp->next;
    }
    return graph;
}
