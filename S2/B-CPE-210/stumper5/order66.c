/*
** EPITECH PROJECT, 2023
** B-CPE-210-MAR-2-1-stumper5-angelo.anselmet
** File description:
** order66
*/

#include "my.h"

void order66(game *gm)
{
    if (gm->area != NULL) {
        for (int i = 0; gm->area[i]; i++) {
            free(gm->area[i]);
        }
        free(gm->area);
    }
    free(gm);
}
