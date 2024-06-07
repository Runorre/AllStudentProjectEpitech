/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** sys
*/

#include "rpg.h"

sys_data* init_sys(void)
{
    sys_data* sys = malloc(sizeof(sys_data));
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    sfFloatRect rect = {.height = 1080, .width = 1920, .top = 0, .left = 0};
    sys->rect_view = rect;
    sys->view = sfView_createFromRect(sys->rect_view);
    sys->window = sfRenderWindow_create(mode, "Spring",
        sfClose | sfResize, NULL);
    sys->music = sfMusic_createFromFile("./utilities/musics/music.ogg");
    sfMusic_setVolume(sys->music, 10);
    sfMusic_setLoop(sys->music, sfTrue);
    sfRenderWindow_setFramerateLimit(sys->window, 60);
    sfRenderWindow_setMouseCursorVisible(sys->window, sfFalse);
    sys->music_volume = 50;
    sfRenderWindow_setView(sys->window, sys->view);
    sfImage* i_icon = sfImage_createFromFile("./utilities/sprites/icon.png");
    const sfUint8* u_icon = sfImage_getPixelsPtr(i_icon);
    sfRenderWindow_setIcon(sys->window, 32, 32, u_icon);
    sys->quest = init_quest();
    return sys;
}
