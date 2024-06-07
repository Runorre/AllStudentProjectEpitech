/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** initfight2
*/

#include "rpg.h"

fight_s *init_struct6(fight_s *fight, sfVector2f s, sys_data *sys)
{
    fight->cur_s = sfSound_create();
    fight->buf_sound = sfSoundBuffer_createFromFile(
        "./utilities/musics/cursor.ogg");
    sfSound_setBuffer(fight->cur_s, fight->buf_sound);
    sfSound_setVolume(fight->cur_s, (10 * sys->music_volume / 50));
    fight->gm = sfMusic_createFromFile("./utilities/musics/gm.ogg");
    fight->vic = sfMusic_createFromFile("./utilities/musics/victory.ogg");
    sfMusic_setVolume(fight->gm, (10 * sys->music_volume / 50) + 10);
    sfMusic_setVolume(fight->vic, (10 * sys->music_volume / 50));
    return fight;
}

fight_s *init_struct5(fight_s *fight, sfVector2f s, sys_data *sys)
{
    sfText_setPosition(fight->upper_msg,
    (sfVector2f) {s.x - 400.0, s.y - 440.0});
    fight->s = s;
    if (fight->player->spells == NULL)
        return fight;
    fight->nbr_spells = 0;
    for (struct spells_t *tmp = fight->player->spells; tmp; tmp = tmp->next) {
        if (tmp && tmp->texte != NULL && fight->font != NULL) {
            sfText_setFont(tmp->texte, fight->font);
            fight->nbr_spells++;
        }
    }
    fight->no_mana = 0;
    fight->changemenu = 0;
    return init_struct6(fight, s, sys);
}

fight_s *init_struct4(fight_s *fight, sfVector2f s,
                        champ_s *player, sys_data *sys)
{
    fight->name = sfText_create();
    fight->hp = sfText_create();
    fight->mp = sfText_create();
    sfText_setFont(fight->name, fight->font);
    sfText_setFont(fight->hp, fight->font);
    sfText_setFont(fight->mp, fight->font);
    sfText_setString(fight->name, player->name);
    char *hp = putnbr(player->stats->hp);
    char *mp = putnbr(player->stats->mp);
    char *max_mp = putnbr(player->stats->max_mp);
    char *max_hp = putnbr(player->stats->max_hp);
    sfText_setString(fight->hp,
    my_strcat("HP : ", my_strcat(hp, my_strcat("/", max_hp))));
    sfText_setString(fight->mp,
    my_strcat("MP : ", my_strcat(mp, my_strcat("/", max_mp))));
    sfText_setPosition(fight->name,
    (sfVector2f) {s.x - 690.0, s.y + 445.0});
    sfText_setPosition(fight->hp, (sfVector2f) {s.x - 290.0, s.y + 445.0});
    sfText_setPosition(fight->mp, (sfVector2f) {s.x + 240.0, s.y + 445.0});
    return init_struct5(fight, s, sys);
}

fight_s *init_struct3(fight_s *fight, sfVector2f s,
                        sfTexture *box, sys_data *sys)
{
    sfText_setColor(fight->chos_act, sfWhite);
    sfText_setPosition(fight->chos_act,
    (sfVector2f) {s.x - 470.0, s.y + 310.0});
    sfText_setFont(fight->upper_msg, fight->font);
    sfText_setColor(fight->upper_msg, sfWhite);
    fight->cursor = sfSprite_create();
    sfTexture *t = sfTexture_createFromFile("./utilities/sprites/cursor.png",
    NULL);
    sfSprite_setTexture(fight->cursor, t, sfTrue);
    sfSprite_setPosition(fight->cursor,
    (sfVector2f) {s.x - 530.0, s.y + 300.0});
    sfSprite_setScale(fight->cursor, (sfVector2f) {2.0, 2.0});
    fight->down_status = 0;
    fight->move_cursor = 0;
    fight->s_box = sfSprite_create();
    sfSprite_setTexture(fight->s_box, box, sfTrue);
    sfSprite_setPosition(fight->s_box,
        (sfVector2f) {s.x - 720.0, s.y + 435.0});
    sfSprite_setScale(fight->s_box, (sfVector2f) {3.2, 0.8});
    return init_struct4(fight, s, fight->player, sys);
}

fight_s *init_struct2(fight_s *fight, sfVector2f s,
                        champ_s *player, sys_data *sys)
{
    sfTexture *t = sfTexture_createFromFile("./utilities/sprites/box.png",
    NULL);
    fight->box = sfSprite_create();
    fight->opt_box = sfSprite_create();
    sfSprite_setTexture(fight->box, t, sfTrue);
    sfSprite_setTexture(fight->opt_box, t, sfTrue);
    sfSprite_setScale(fight->box, (sfVector2f) {3.2, 2.0});
    sfSprite_setScale(fight->opt_box, (sfVector2f) {3.0, 0.5});
    sfSprite_setPosition(fight->box,
    (sfVector2f) {s.x - 720.0, s.y + 250.0});
    sfSprite_setPosition(fight->opt_box,
    (sfVector2f) {s.x - 720.0, s.y - 440.0});
    fight->font = sfFont_createFromFile("./utilities/fonts/sub.ttf");
    fight->chos_act = sfText_create(); fight->upper_msg = sfText_create();
    sfText_setFont(fight->chos_act, fight->font);
    char *str = "Attaque\t\t\t\t\t\t  Magie\t\t\t\t\t\t\t  Fuite";
    sfText_setString(fight->chos_act, str);
    return init_struct3(fight, s, t, sys);
}
