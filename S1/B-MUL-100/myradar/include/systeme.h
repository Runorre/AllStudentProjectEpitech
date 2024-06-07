/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myradar-angelo.anselmet
** File description:
** systeme
*/

#include "my.h"

#ifndef SYSTEME_H_
    #define SYSTEME_H_
    typedef struct sys_data {
        sfRenderWindow *win;
        sfEvent event;
        sfClock *clock;
        sfTime time;
        float seconds;
        sfSprite *bg;
        int show_hitbox;
        int show_sp;
    }sys_data;
#endif /* !SYSTEME_H_ */
