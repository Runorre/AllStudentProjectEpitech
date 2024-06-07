/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** crédit
*/

#include "rpg.h"

sfBool events_cred(sys_data *sys)
{

    if (sys->event.type == sfEvtClosed ||
    (sys->event.type == sfEvtKeyReleased &&
    sys->event.key.code == sfKeyEscape)) {
        sfMusic_stop(sys->music);
        sfRenderWindow_close(sys->window);
        return 1;
    } return 0;
}

sfText *init_text_cred(char *text, sfVector2f pos, int size)
{
    sfText *cred = sfText_create();
    sfText_setString(cred, text);
    sfText_setCharacterSize(cred, size);
    sfText_setPosition(cred, pos);
    sfFont *font = sfFont_createFromFile("utilities/fonts/sub.ttf");
    sfText_setFont(cred, font);
    return cred;
}

sfText **create_text_cred(void)
{
    sfText **crédit = malloc(sizeof(sfText *) * 6);
    crédit[0] = init_text_cred("jeu developpe par\n",
    (sfVector2f){800, 150}, 40);
    crédit[1] = init_text_cred("    Angelo\n", (sfVector2f){875, 250}, 30);
    crédit[2] = init_text_cred("     Tom\n", (sfVector2f){880, 300}, 30);
    crédit[3] = init_text_cred("  Celestin\n", (sfVector2f){875, 350}, 30);
    crédit[4] = init_text_cred("     Dam", (sfVector2f){880, 400}, 30);
    crédit[5] = NULL;
    return crédit;
}

void place_credit(sys_data *sys)
{
    sys->music = sfMusic_createFromFile("utilities/musics/credit.ogg");
    sfMusic_setVolume(sys->music, (10 * sys->music_volume / 50));
    sfMusic_play(sys->music);
    sfClock *clock = sfClock_create(); sfBool leave = 0;
    sfText **credit = create_text_cred();
    while (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < 15 &&
    sfRenderWindow_isOpen(sys->window)) {
        sfRenderWindow_clear(sys->window, sfBlack);
        for (int i = 0; credit[i] != NULL; i++) {
            sfRenderWindow_drawText(sys->window, credit[i], NULL);
        } sfRenderWindow_display(sys->window);
        while (sfRenderWindow_pollEvent(sys->window, &sys->event))
            leave = events_cred(sys);
        if (leave == 1)
            return;
    } sfMusic_stop(sys->music);
    sfRenderWindow_close(sys->window);
}
