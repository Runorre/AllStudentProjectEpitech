/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-angelo.anselmet
** File description:
** algo
*/

#include "../include/lem_in.h"

int is_in_list(vertex_t* list, int value)
{
    vertex_t* tmp = list;
    while (tmp != NULL) {
        if (tmp->dest == value)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

vertex_t* stock_to_do(vertex_t* adjacents, vertex_t* path)
{
    vertex_t* to_do = NULL, *tmp = adjacents;
    while (tmp != NULL) {
        if (!is_in_list(path, tmp->dest)) {
            to_do = add_vertex(to_do, tmp->dest);
        }
        tmp = tmp->next;
    }
    return to_do;
}

void print_vertex(vertex_t* list)
{
    vertex_t* tmp = list;
    while (tmp != NULL) {
        my_printf("%d\t", tmp->dest);
        tmp = tmp->next;
    }
    my_printf("\n");
}

int path_len(vertex_t* list)
{
    int len = 0;
    vertex_t* tmp = list;
    while (tmp != NULL) {
        len ++;
        tmp = tmp->next;
    }
    return len;
}

vertex_t* algo(graph_t* graph, int current, int end, vertex_t* path)
{
    vertex_t* to_do = stock_to_do(graph[current].vertex, path);
    vertex_t* tmp = NULL;
    vertex_t* tmp2 = NULL;
    path = add_vertex(path, current);
    while (to_do != NULL && current != end) {
        tmp = algo(graph, to_do->dest, end, path);
        tmp2 = to_do;
        to_do = to_do->next;
        free(tmp2);
    }
    free_vertex(to_do);
    if (path_len(tmp) > path_len(path)) {
        return tmp;
    }
    return path;
}
