/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** victory
*/

#include "rpg.h"

void events_victory(sys_data* sys, fight_s *fight)
{
    switch (sys->event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(sys->window);
            break;
        case sfEvtKeyPressed:
            sys->fight = 0;
            break;
        default:
            break;
    }
}

void vic_loop(fight_s *fight, sys_data *sys)
{
    while (sfRenderWindow_isOpen(sys->window) && sys->fight == 4) {
        while (sfRenderWindow_pollEvent(sys->window, &sys->event))
            events_victory(sys, fight);
        sfRenderWindow_clear(sys->window, sfBlack);
        draw_aera(fight, sys);
        draw_life(fight, sys);
        draw_hud(fight, sys);
        sfRenderWindow_drawText(sys->window, fight->chos_act, NULL);
        sfRenderWindow_display(sys->window);
    }
    sfSoundBuffer_destroy(fight->buf_sound);
    sfMusic_stop(fight->vic);
    sfMusic_destroy(fight->vic);
    sfMusic_destroy(fight->gm);
    free(fight);
}

void level_2(fight_s *fight)
{
    fight->player->level->lvl = 2;
    fight->player->spells = get_ete(fight->player);
    fight->player->stats->max_hp += 25;
    fight->player->stats->hp = fight->player->stats->max_hp;
    fight->player->stats->max_mp += 10;
    fight->player->stats->mp = fight->player->stats->max_mp;
    fight->player->stats->attack += 15;
    fight->player->stats->defense += 7;
    fight->player->stats->magie += 4;
    char *newmp = my_strcat(putnbr(fight->player->stats->mp), "/");
    newmp = my_strcat(newmp, putnbr(fight->player->stats->max_mp));
    newmp = my_strcat("MP : ", newmp);
    sfText_setString(fight->mp, newmp);
    char *newhp = my_strcat(putnbr(fight->player->stats->hp), "/");
    newhp = my_strcat(newhp, putnbr(fight->player->stats->max_hp));
    newhp = my_strcat("HP : ", newhp);
    sfText_setString(fight->hp, newhp);
}

void level_3(fight_s *fight)
{
    fight->player->level->lvl = 3;
    fight->player->spells = get_automne(fight->player);
    fight->player->stats->max_hp += 25;
    fight->player->stats->hp = fight->player->stats->max_hp;
    fight->player->stats->max_mp += 15;
    fight->player->stats->mp = fight->player->stats->max_mp;
    fight->player->stats->attack += 12;
    fight->player->stats->defense += 5;
    fight->player->stats->magie += 6;
    char *newmp = my_strcat(putnbr(fight->player->stats->mp), "/");
    newmp = my_strcat(newmp, putnbr(fight->player->stats->max_mp));
    newmp = my_strcat("MP : ", newmp);
    sfText_setString(fight->mp, newmp);
    char *newhp = my_strcat(putnbr(fight->player->stats->hp), "/");
    newhp = my_strcat(newhp, putnbr(fight->player->stats->max_hp));
    newhp = my_strcat("HP : ", newhp);
    sfText_setString(fight->hp, newhp);
}

void victory(fight_s *fight, sys_data *sys)
{
    char *msg = "Vous gagnez ";
    msg = my_strcat(msg, putnbr(fight->enemie->level->exp));
    msg = my_strcat(msg, " d'experience.");
    fight->player->level->exp += fight->enemie->level->exp;
    fight->down_status = 11;
    if (fight->player->level->lvl == 1 && fight->player->level->exp >= 10) {
        msg = my_strcat(msg, "\n\t\tVous passez niveau 2.");
        level_2(fight);
    } else if (fight->player->level->lvl == 2 &&
                fight->player->level->exp >= 20) {
        msg = my_strcat(msg, "\n\t\tVous passez niveau 3.");
        level_3(fight);
    }
    sfText_setString(fight->chos_act, msg);
    sfText_move(fight->chos_act, (sfVector2f) {230.0, 0.0});
    vic_loop(fight, sys);
}
