/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myradar-angelo.anselmet
** File description:
** struct
*/

#include "my.h"

#ifndef STRUCT_H_
    #define STRUCT_H_
    typedef struct tower {
        sfVector2f pos;
        sfVector2f poss;
        int rad;
        sfSprite *sp;
        sfCircleShape *cir;
    }tower;

    typedef struct plane {
        sfVector2f pos;
        sfVector2f end;
        int speed;
        int show;
        int starting;
        int safe;
        sfSprite *sp;
        sfVector2f offset;
        sfRectangleShape *hitbox;
    }plane;

    typedef struct ll_tower {
        struct tower *obj;
        struct ll_tower *next;
    }ll_tower;

    typedef struct ll_plane {
        struct plane *obj;
        struct ll_plane *next;
    }ll_plane;
#endif /* !STRUCT_H_ */
