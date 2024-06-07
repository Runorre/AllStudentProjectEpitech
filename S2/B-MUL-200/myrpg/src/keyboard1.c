/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** keyboard
*/

#include "rpg.h"

void free_all(giu_s perso)
{
    sfRenderWindow_destroy(perso.window);
    sfText_destroy(perso.end);
}

bool events_kb(giu_s perso, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(perso.window);
        return (true);
    }
    return (false);
}

void affichage_end(giu_s perso, char *name)
{
    sfEvent event;
    sfClock *clock = sfClock_create();
    sfTime time;
    float joan = 0.0;
    bool finish = false;
    perso.end_name = create_kbtext(280, 65, 20, name);
    sfText_setColor(perso.end_name, sfColor_fromRGB(0, 0, 0));
    while (joan <= 4 && sfRenderWindow_isOpen(perso.window)) {
        time = sfClock_getElapsedTime(clock);
        joan = sfTime_asSeconds(time);
        while (sfRenderWindow_pollEvent(perso.window, &event))
            finish = events_kb(perso, event);
        sfRenderWindow_display(perso.window);
        sfRenderWindow_clear(perso.window, sfColor_fromRGB(255, 255, 255));
        sfRenderWindow_drawText(perso.window, perso.end, NULL);
        sfRenderWindow_drawText(perso.window, perso.end_name, NULL);
    }
    sfClock_destroy(clock);
    if (!finish)
        sfRenderWindow_close(perso.window);
}

char* get_name_champion(sys_data *sys)
{
    char *name = NULL;
    giu_s perso = init_struct_giu();
    perso_s add = init_struct_perso();
    sfEvent event;
    sfRenderWindow_setKeyRepeatEnabled(perso.window, sfFalse);
    while (sfRenderWindow_isOpen(perso.window) && add.fini == 0) {
        clik_button(perso.button_open, perso.button_hasard, &add, perso.window);
        affichage(perso, add, name, sys);
        name = event_moment(name, &add, perso, sys);
        if (add.fini > 0) {
            name = check_witch_end(add, name);
        }
        add.touch = 0;
    }
    affichage_end(perso, name);
    return (name);
}
