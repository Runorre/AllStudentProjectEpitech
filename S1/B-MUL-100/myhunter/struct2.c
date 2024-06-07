/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myhunter-angelo.anselmet
** File description:
** struct
*/

#include "my.h"
#include "sprite.h"
#include "system.h"
#include "text.h"

struct text create_txt_1(char const *str, struct system_data *sys)
{
    struct text txt;
    txt.text = sfText_create();
    sfText_setString(txt.text, str);
    sfText_setFont(txt.text, sys->font);
    sfText_setCharacterSize(txt.text, 90);
    sfVector2f pos_text = {360, 540};
    sfText_setPosition(txt.text, pos_text);
    return txt;
}

struct text create_txt_score(char const *str, struct system_data *sys)
{
    struct text txt;
    txt.text = sfText_create();
    sfText_setString(txt.text, str);
    sfText_setFont(txt.text, sys->font);
    sfText_setCharacterSize(txt.text, 35);
    sfVector2f pos_text = {462, 625};
    sfText_setPosition(txt.text, pos_text);
    return txt;
}

void next(struct HUD *hud, struct system_data *sys, sfVector2f scale)
{
    hud->bullts1.tex = sfTexture_createFromFile("./assets/bullet.png", NULL);
    hud->bullts1.sp = sfSprite_create();
    hud->bullts1.pos.x = 465;
    hud->bullts1.pos.y = 684;
    sfSprite_setScale(hud->bullts1.sp, scale);
    sfSprite_setTexture(hud->bullts1.sp, hud->bullts1.tex, sfTrue);
    sfSprite_setPosition(hud->bullts1.sp, hud->bullts1.pos);
    hud->bullts2.sp = sfSprite_create();
    hud->bullts2.pos.x = 490;
    hud->bullts2.pos.y = 684;
    sfSprite_setScale(hud->bullts2.sp, scale);
    sfSprite_setTexture(hud->bullts2.sp, hud->bullts1.tex, sfTrue);
    sfSprite_setPosition(hud->bullts2.sp, hud->bullts2.pos);
    hud->bullts3.sp = sfSprite_create();
    hud->bullts3.pos.x = 515;
    hud->bullts3.pos.y = 684;
    sfSprite_setScale(hud->bullts3.sp, scale);
    sfSprite_setTexture(hud->bullts3.sp, hud->bullts1.tex, sfTrue);
    sfSprite_setPosition(hud->bullts3.sp, hud->bullts3.pos);
}

struct HUD create_sp_hud(char const *path, struct system_data *sys)
{
    struct HUD hud;
    hud.score = create_txt_score("R=1", &(*sys));
    hud.blank.tex = sfTexture_createFromFile(path, NULL);
    hud.blank.sp = sfSprite_create();
    hud.blank.pos.x = 450;
    hud.blank.pos.y = 630;
    sfVector2f scale = {3.2, 3.2};
    sfSprite_setScale(hud.blank.sp, scale);
    sfSprite_setTexture(hud.blank.sp, hud.blank.tex, sfTrue);
    sfSprite_setPosition(hud.blank.sp, hud.blank.pos);
    hud.shot.tex = sfTexture_createFromFile("./assets/shot.png", NULL);
    hud.shot.sp = sfSprite_create();
    hud.shot.pos.x = 453;
    hud.shot.pos.y = 684;
    sfSprite_setScale(hud.shot.sp, scale);
    sfSprite_setTexture(hud.shot.sp, hud.shot.tex, sfTrue);
    sfSprite_setPosition(hud.shot.sp, hud.shot.pos);
    next(&hud, &(*sys), scale);
    return hud;
}
