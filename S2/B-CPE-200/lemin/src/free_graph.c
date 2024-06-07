/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-angelo.anselmet
** File description:
** free_graph
*/

#include "lem_in.h"

void free_arcs(arcs_t* head)
{
    arcs_t* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    free(head);
}

void free_graph(graph_t* graph)
{
    int i = 0;
    while (i < graph->n_vertex) {
        free_vertex(graph[i].vertex);
        i ++;
    }
    free(graph);
}

void free_vertex(vertex_t* head)
{
    vertex_t* tmp = NULL;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    free(head);
}
