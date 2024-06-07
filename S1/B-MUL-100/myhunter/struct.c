/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myhunter-angelo.anselmet
** File description:
** struct
*/

#include "my.h"
#include "sprite.h"
#include "system.h"

struct sprite create_sp(char const *path)
{
    struct sprite sheet;
    sheet.tex = sfTexture_createFromFile(path, NULL);
    sheet.sp = sfSprite_create();
    sfSprite_setTexture(sheet.sp, sheet.tex, sfTrue);
    return sheet;
}

struct sprite create_sp_duck(char const *path, struct system_data *sys)
{
    struct sprite sheet;
    sheet.tex = sfTexture_createFromFile(path, NULL);
    sheet.sp = sfSprite_create();
    sfSprite_setTexture(sheet.sp, sheet.tex, sfTrue);
    randomduck(&sheet, &(*sys));
    sfSprite_setPosition(sheet.sp, sheet.pos);
    sfSprite_setTextureRect(sheet.sp, sys->rect);
    sfSprite_setScale(sheet.sp, (sfVector2f) {3, 3});
    return sheet;
}

struct sfx create_sfx(void)
{
    struct sfx sound;
    sound.fly = sfSound_create();
    sound.fall = sfSound_create();
    sound.gun = sfSound_create();
    sfSoundBuffer* flyb = sfSoundBuffer_createFromFile("./assets/fly.wav");
    sfSoundBuffer* fallb = sfSoundBuffer_createFromFile("./assets/falling.wav");
    sfSoundBuffer* gunb = sfSoundBuffer_createFromFile("./assets/gun.wav");
    sfSound_setBuffer(sound.fly, flyb);
    sfSound_setBuffer(sound.fall, fallb);
    sfSound_setBuffer(sound.gun, gunb);
    sound.music = sfMusic_createFromFile("./assets/main.wav");
    return sound;
}

struct BG create_bg(struct system_data *sys)
{
    struct BG bg;
    bg.bg = create_sp("./assets/stage2.png");
    bg.front = create_sp("./assets/stage3.png");
    sfSprite_setScale(bg.bg.sp, (sfVector2f) {0.86, 0.70});
    sfSprite_setScale(bg.front.sp, (sfVector2f) {0.86, 0.70});
    bg.duck = create_sp_duck("./assets/greenc.png", &(*sys));
    return bg;

}

struct system_data create_sys(void)
{
    struct system_data sys;
    sfVideoMode mode = {1920, 1080, 62};
    sys.window = sfRenderWindow_create(mode, "MyHunter",
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(sys.window, 60);
    sfRenderWindow_setMouseCursorVisible(sys.window, sfFalse);
    sfRenderWindow_setMouseCursorGrabbed(sys.window, sfTrue);
    sys.clock = sfClock_create();
    sfIntRect rect = {80, 0, 29, 44};
    sys.rect = rect;
    sys.sound = create_sfx();
    sys.font = sfFont_createFromFile("./assets/m29.TTF");
    sys.live = 3;
    return sys;
}
