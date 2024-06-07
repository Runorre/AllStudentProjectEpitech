/*
** EPITECH PROJECT, 2023
** src/error_handling_next
** File description:
** lem_in
*/
#include "../include/lem_in.h"

int start_not_connected_to_end(graph_t* graph, int start)
{
    vertex_t* tmp = graph[start].vertex;
    if (tmp == NULL)
        return 1;
    if (tmp->cost == 0)
        return 1;
    return 0;
}

int check_tunnel_line(char *str)
{
    int i = 0, w = 0;
    while (str[i]) {
        if (str[i] == '-') {
            w++;
        }
        i++;
    }
    if (w > 1) {
        return -1;
    }
    return 0;
}
