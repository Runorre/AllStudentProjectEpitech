/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myhunter-angelo.anselmet
** File description:
** system
*/

#include "sfx.h"

#ifndef SYSTEM_H_
    #define SYSTEM_H_
    struct system_data {
        sfRenderWindow *window;
        sfEvent event;
        sfVector2i mouse;
        sfIntRect rect;
        sfClock *clock;
        sfTime time;
        float seconds;
        int random;
        struct sfx sound;
        sfFont* font;
        int score;
        int live;
    };
#endif /* !SYSTEM_H_ */
