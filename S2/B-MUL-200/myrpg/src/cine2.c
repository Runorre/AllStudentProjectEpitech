/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** cine2
*/

#include "rpg.h"

int cine_events(sys_data* sys, sfSound* voice)
{
    if (sys->event.type == sfEvtKeyReleased)
        if (sys->event.key.code == sfKeyEscape) {
            sfSound_stop(voice);
            return 1;
        }
    if (sys->event.type == sfEvtClosed) {
        sfSound_stop(voice);
        sfRenderWindow_close(sys->window);
    }
    return 0;
}
