/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** map
*/

#include "../include/server.h"

void allocate_map(main_data_t *md, int i)
{
    md->map[i] = calloc((size_t)md->arg->height, sizeof(map_t));
    for (int j = 0; j < md->arg->height; j++) {
        for (int k = 0; k < 7; k++) {
            md->map[i][j].materials[k] = 0;
        }
    }
}

void fill_map(main_data_t *md, int k, float resources[7])
{
    int i = rand() % md->arg->width;
    int j = rand() % md->arg->height;

    md->map[i][j].materials[k] += 1;
    resources[k]--;
}

void distribute_resources(main_data_t *md, float resources[7])
{
    srand((unsigned int)time(NULL));
    for (int k = 0; k < 7; k++) {
        while (resources[k] > 0) {
            fill_map(md, k, resources);
        }
    }
}

void initialize_map(main_data_t *md)
{
    float total_cells = (float)md->arg->width * (float)md->arg->height;
    float resources[7] = {
        total_cells * 0.5f,
        total_cells * 0.3f,
        total_cells * 0.15f,
        total_cells * 0.1f,
        total_cells * 0.1f,
        total_cells * 0.08f,
        total_cells * 0.05f
    };

    md->map = calloc((size_t)md->arg->width, sizeof(map_t *));
    for (int i = 0; i < md->arg->width; i++) {
        allocate_map(md, i);
    }
    distribute_resources(md, resources);
}
