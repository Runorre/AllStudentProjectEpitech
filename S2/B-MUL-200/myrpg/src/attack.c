/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** attack
*/

#include "rpg.h"

void heal_spell(fight_s *f, sys_data *sys, spells_s *tmp)
{
    int recup = (rand() % tmp->stats->attack) + 15;
    int tmphp = f->player->stats->hp + recup;
    if (tmphp > f->player->stats->max_hp) {
        int downgrade = tmphp - f->player->stats->max_hp;
        tmphp -= downgrade;
        f->player->stats->hp = tmphp;
        recup -= downgrade;
    } else {
        f->player->stats->hp = tmphp;
    }
    char * msg = my_strcat("Vous avez recupere ", putnbr(recup));
    msg = my_strcat(msg, " HP");
    sfText_setString(f->upper_msg, msg);
    f->clock = sfClock_create();
    f->down_status = 1;
}

void attack_spell(fight_s *f, sys_data *sys, spells_s *tmp)
{
    int dmg = (rand() % tmp->stats->attack) + 10;
    dmg += f->player->stats->magie;
    dmg -= f->enemie->stats->defense;
    f->enemie->stats->hp -= dmg;
    char *msg = my_strcat("Vous avez attaquer ", f->enemie->name);
    msg = my_strcat(msg, " est a pris ");
    msg = my_strcat(msg, putnbr(dmg));
    msg = my_strcat(msg, " de degats");
    sfText_setString(f->upper_msg, msg);
    free(msg);
    f->clock = sfClock_create();
    f->down_status = 1;
}

void magic_attack(fight_s *f, sys_data *sys)
{
    spells_s *tmp = f->player->spells;
    for (int i = 0; i != f->move_cursor && tmp; i++)
        tmp = tmp->next;
    if (f->player->stats->mp < tmp->stats->mp) {
        sfText_setString(f->upper_msg,
        "Vous n'avez pas assez de magie");
        f->clock = sfClock_create();
        f->no_mana = 1;
        return;
    }
    f->player->stats->mp -= tmp->stats->mp;
    char *newmp = my_strcat(putnbr(f->player->stats->mp), "/");
    newmp = my_strcat(newmp, putnbr(f->player->stats->max_mp));
    newmp = my_strcat("MP : ", newmp);
    sfText_setString(f->mp, newmp);
    if (tmp->heal)
        heal_spell(f, sys, tmp);
    else
        attack_spell(f, sys, tmp);
}

void attack_enemy(fight_s *f, sys_data *sys)
{
    sfVector2f s = sfView_getCenter(sys->view);
    sfText_setPosition(f->upper_msg, (sfVector2f)
        {s.x - 400.0, s.y - 440.0});
    char *msg = my_strcat("Vous avez attaquer ", f->enemie->name);
    int degats = (rand() % f->player->stats->attack) + 3;
    degats -= f->enemie->stats->defense;
    if (degats <= 0)
        degats = rand() % 3 + 1;
    msg = my_strcat(msg, " est a pris ");
    msg = my_strcat(msg, putnbr(degats));
    msg = my_strcat(msg, " de degats");
    f->enemie->stats->hp -= degats;
    sfText_setString(f->upper_msg, msg);
    free(msg);
}

void enemy_attack(fight_s *fight, sys_data *sys)
{
    sfVector2f s = sfView_getCenter(sys->view);
    sfText_setPosition(fight->upper_msg, (sfVector2f)
        {s.x - 300.0, s.y - 440.0});
    char *msg = my_strcat(fight->enemie->name, " vous a fait ");
    int degats = (rand() % fight->enemie->stats->attack) + 3;
    degats -= fight->player->stats->defense;
    if (degats <= 0)
        degats = rand() % 3;
    msg = my_strcat(msg, putnbr(degats));
    msg = my_strcat(msg, " de degats");
    fight->player->stats->hp -= degats;
    sfText_setString(fight->upper_msg, msg);
    if (fight->player->stats->hp < 0)
        fight->player->stats->hp = 0;
    char *newhp = my_strcat(putnbr(fight->player->stats->hp), "/");
    newhp = my_strcat(newhp, putnbr(fight->player->stats->max_hp));
    newhp = my_strcat("HP : ", newhp);
    sfText_setString(fight->hp, newhp);
    free(msg);
}
