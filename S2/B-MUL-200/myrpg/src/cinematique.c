/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** cinematique
*/

#include "rpg.h"

sfText *init_subtitle(char *text)
{
    sfText *sub = sfText_create();
    sfText_setString(sub, text);
    sfText_setScale(sub, (sfVector2f){1, 1});
    sfText_setPosition(sub, (sfVector2f){500, 875});
    sfFont *font = sfFont_createFromFile("utilities/fonts/sub.ttf");
    sfText_setFont(sub, font);
    return sub;
}

void put_cine(sys_data *sys, sfSprite *cine, sfText *text)
{
    sfRenderWindow_clear(sys->window, sfBlack);
    sfRenderWindow_drawSprite(sys->window, cine, NULL);
    sfRenderWindow_drawText(sys->window, text, NULL);
    sfRenderWindow_display(sys->window);
}

sfText **create_text(void)
{
    sfText **text = malloc(sizeof(sfText *) * 6);
    char *t = CINE_T;
    text[0] = init_subtitle(t);
    t = CINE_T2;
    text[1] = init_subtitle(t);
    t = CINE_T3;
    text[2] = init_subtitle(t);
    t = CINE_T4;
    text[3] = init_subtitle(t);
    t = CINE_T5;
    text[4] = init_subtitle(t);
    t = CINE_T6;
    text[5] = init_subtitle(t); text[6] = NULL; return text;
}

sfSprite **create_sprite(void)
{
    sfSprite **sprite = malloc(sizeof(sfSprite *) * 6);
    sprite[0] = init_sprite("utilities/cine/king_cine.png");
    sfSprite_setScale(sprite[0], (sfVector2f){1.5, 1.5});
    sprite[1] = init_sprite("utilities/cine/war_cine.png");
    sfSprite_setScale(sprite[1], (sfVector2f){1.25, 1.25});
    sprite[2] = init_sprite("utilities/cine/miror_cine.png");
    sfSprite_setScale(sprite[2], (sfVector2f){1.5, 1.5});
    sprite[3] = init_sprite("utilities/cine/miror_cine.png");
    sfSprite_setScale(sprite[3], (sfVector2f){1.5, 1.5});
    sprite[4] = init_sprite("utilities/cine/soul_cine.png");
    sfSprite_setScale(sprite[4], (sfVector2f){1.10, 1.10});
    sprite[5] = init_sprite("utilities/cine/out_cine.png");
    sfSprite_setScale(sprite[5], (sfVector2f){1.25, 1.25});
    sprite[6] = NULL; return sprite;
}

void cinematique(sys_data *sys)
{
    sfClock *clock = sfClock_create(); sfSound *voice = sfSound_create();
    sfSoundBuffer *buf = sfSoundBuffer_createFromFile(
        "utilities/musics/voice.ogg");
    sfSound_setBuffer(voice, buf);
    sfSound_setVolume(voice, (10 * sys->music_volume / 25));
    sfSound_play(voice); int seconds[] = {8, 6, 4, 13, 8, 7};
    sfSprite **sprite = create_sprite(); sfText **text = create_text();
    int i = 0, check;
    while (sfRenderWindow_isOpen(sys->window) && i < 6) {
        while (sfRenderWindow_pollEvent(sys->window, &sys->event)) {
            check = cine_events(sys, voice);
        }
        if (check) return;
        put_cine(sys, sprite[i], text[i]);
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > seconds[i]) {
            sfClock_restart(clock);
            i++;
        }
    }
}
