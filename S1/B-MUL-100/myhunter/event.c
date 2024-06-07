/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myhunter-angelo.anselmet
** File description:
** event
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window.h>

void event_menu(struct system_data *sys)
{
    while (sfRenderWindow_pollEvent(sys->window, &sys->event)) {
        if (sys->event.type == sfEvtClosed)
            sfRenderWindow_close(sys->window);
        if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue) {
            sfMusic_stop(sys->sound.music);
            game(&(*sys));
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            sfRenderWindow_close(sys->window);
    }
}

void live(struct system_data *sys)
{
    if (sys->live != 3)
        sys->live++;
}

void if_click(struct system_data *sys, struct sprite *sp)
{
    if (sys->mouse.x >= sp->pos.x && sys->mouse.x <= sp->pos.x + 100) {
        if (sys->mouse.y >= sp->pos.y && sys->mouse.y <= sp->pos.y + 100) {
            sp->status = 3;
            live(&(*sys));
        } else {
            sys->live--;
        }
    } else {
        sys->live--;
    }
}

void event_game(struct system_data *sys, struct sprite *sp)
{
    while (sfRenderWindow_pollEvent(sys->window, &sys->event)) {
        if (sys->event.type == sfEvtClosed)
            sfRenderWindow_close(sys->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            sfRenderWindow_close(sys->window);
        if (sys->event.type == sfEvtMouseButtonReleased) {
            if_click(&(*sys), &(*sp));
            sfSound_play(sys->sound.gun);
        }
        if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue) {
            my_printf("x : %i | y : %i\n", sys->mouse.x, sys->mouse.y);
        }
    }
}
