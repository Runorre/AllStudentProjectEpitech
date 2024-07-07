/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** reset
*/

#include "../include/server.h"

void calculate_initial_resources(main_data_t *md, float initial_resources[7])
{
    float total_cells = (float)md->arg->width * (float)md->arg->height;

    initial_resources[0] = total_cells * 0.5f;
    initial_resources[1] = total_cells * 0.3f;
    initial_resources[2] = total_cells * 0.15f;
    initial_resources[3] = total_cells * 0.1f;
    initial_resources[4] = total_cells * 0.1f;
    initial_resources[5] = total_cells * 0.08f;
    initial_resources[6] = total_cells * 0.05f;
}

void update_current_resources(main_data_t *md, float current[7], int i, int j)
{
    for (int k = 0; k < 7; k++) {
        current[k] += (float)md->map[i][j].materials[k];
    }
}

void calculate_current_resources(main_data_t *md, float current_resources[7])
{
    for (int i = 0; i < md->arg->width; i++) {
        for (int j = 0; j < md->arg->height; j++) {
            update_current_resources(md, current_resources, i, j);
        }
    }
}

void distribute_mat(main_data_t *md, float initial[7], float current[7], int k)
{
    int i = 0;
    int j = 0;

    while (current[k] < initial[k]) {
        i = rand() % md->arg->width;
        j = rand() % md->arg->height;
        md->map[i][j].materials[k] += 1;
        current[k]++;
    }
}

void distribute_new(main_data_t *md, float initial[7], float current[7])
{
    for (int k = 0; k < 7; k++) {
        distribute_mat(md, initial, current, k);
    }
}
