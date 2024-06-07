/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** gameover
*/

#include "rpg.h"

void events_gm(sys_data* sys, fight_s *fight)
{
    switch (sys->event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(sys->window);
            sfSoundBuffer_destroy(fight->buf_sound), sfMusic_stop(fight->gm);
            sfMusic_destroy(fight->vic);
            sfMusic_destroy(fight->gm);
            break;
        case sfEvtKeyPressed:
            sfSoundBuffer_destroy(fight->buf_sound);
            sfMusic_stop(fight->gm);
            sfMusic_destroy(fight->vic);
            sfMusic_destroy(fight->gm);
            sfFloatRect rect = {.height = 1080, .width = 1920, .top = 0,
            .left = 0};
            sys->rect_view = rect;
            sys->view = sfView_createFromRect(sys->rect_view);
            sfRenderWindow_setView(sys->window, sys->view);
            menu(sys);
            break;
    }
}

void gameover(fight_s *f, sys_data *sys)
{
    sfTexture *t = sfTexture_createFromFile("./utilities/sprites/gm.png", NULL);
    sfSprite *gm = sfSprite_create();
    sfSprite_setTexture(gm, t, sfTrue);
    sfSprite_setPosition(gm, (sfVector2f) {f->s.x - 730.0, f->s.y - 455.0});
    sfSprite_setScale(gm, (sfVector2f) {1.5, 1.5});
    sfText *txt = sfText_create();
    sfText_setFont(txt, f->font);
    sfText_setString(txt, "Appuyer sur une touche pour continuer");
    sfText_setPosition(txt, (sfVector2f) {f->s.x - 380.0, f->s.y + 355.0});
    while (sfRenderWindow_isOpen(sys->window)) {
        while (sfRenderWindow_pollEvent(sys->window, &sys->event))
            events_gm(sys, f);
        sfRenderWindow_clear(sys->window, sfBlack);
        sfRenderWindow_drawSprite(sys->window, gm, NULL);
        sfRenderWindow_drawText(sys->window, txt, NULL);
        sfRenderWindow_display(sys->window);
    }
}
