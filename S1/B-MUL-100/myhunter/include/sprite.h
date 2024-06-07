/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myhunter-angelo.anselmet
** File description:
** sprite
*/

#include "my.h"
#include "text.h"

#ifndef SPRITE_H_
    #define SPRITE_H_
    struct sprite {
        sfTexture *tex;
        sfSprite *sp;
        sfVector2f pos;
        int status;
        int inverted;
    };

    struct BG {
        struct sprite bg;
        struct sprite front;
        struct sprite duck;
    };
    struct HUD {
        struct sprite blank;
        struct sprite shot;
        struct sprite bullts1;
        struct sprite bullts2;
        struct sprite bullts3;
        struct text score;
    };
#endif /* !SPRITE_H_ */
