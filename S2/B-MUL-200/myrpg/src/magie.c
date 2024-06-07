/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** magie
*/

#include "rpg.h"

void pos_spell(fight_s *fight, sys_data *sys)
{
    float deca = 0.0;
    if (fight->player->spells == NULL)
        return;
    for (spells_s *tmp = fight->player->spells; tmp;
    tmp = tmp->next) {
        sfText_setPosition(tmp->texte,
        (sfVector2f) {fight->s.x - 540.0, fight->s.y + 270.0 + deca});
        deca += 60.0;
    }
}

void show_list_spell(fight_s *fight, sys_data *sys)
{
    if (fight->player->spells == NULL)
        return;
    for (spells_s *tmp = fight->player->spells; tmp;
    tmp = tmp->next) {
        sfRenderWindow_drawText(sys->window, tmp->texte, NULL);
    }
}

spells_s *get_spring(champ_s *mc)
{
    spells_s *spring = malloc(sizeof(spells_s));
    spring->id = 1;
    spring->name = "Eclosion printaniere";
    spring->stats = malloc(sizeof(stats_s));
    spring->stats->mp = 6;
    spring->texte = sfText_create();
    sfText_setString(spring->texte,
    "Eclosion printaniere\t\t\t\t\t\t\t\t\t\t\t\t\t\t6 MP");
    spring->heal = 1;
    spring->stats->attack = 20;
    spring->next = NULL;
    return spring;
}

spells_s *get_automne(champ_s *mc)
{
    spells_s *tmp = mc->spells;
    if (tmp->next != NULL)
        tmp = tmp->next;
    spells_s *automne = malloc(sizeof(spells_s));
    automne->name = "Brise d'automne";
    automne->id = 3;
    automne->stats = malloc(sizeof(stats_s));
    automne->stats->mp = 7;
    automne->texte = sfText_create();
    sfText_setString(automne->texte,
    "Brise d'automne\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  7 MP");
    automne->heal = 0;
    automne->stats->attack = 35;
    automne->next = NULL;
    tmp->next = automne;
    return mc->spells;
}

spells_s *get_ete(champ_s *mc)
{
    spells_s *tmp = mc->spells;
    spells_s *ete = malloc(sizeof(spells_s));
    ete->name = "Solaris";
    ete->id = 2;
    ete->stats = malloc(sizeof(stats_s));
    ete->stats->mp = 9;
    ete->texte = sfText_create();
    sfText_setString(ete->texte,
    "Solaris\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t 9 MP");
    ete->heal = 0;
    ete->stats->attack = 45;
    ete->next = NULL;
    tmp->next = ete;
    return tmp;
}
