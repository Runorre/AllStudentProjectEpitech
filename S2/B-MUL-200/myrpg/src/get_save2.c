/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** get_save2
*/

#include "rpg.h"

stats_s *recup_stats_ll(char *dest, int *i)
{
    stats_s *stat = malloc(sizeof(stats_s));
    stat->attack = my_getnbnbr(dest, i);
    stat->defense = my_getnbnbr(dest, i);
    stat->magie = my_getnbnbr(dest, i);
    stat->hp = my_getnbnbr(dest, i);
    stat->max_hp = my_getnbnbr(dest, i);
    stat->mp = my_getnbnbr(dest, i);
    stat->max_mp = my_getnbnbr(dest, i);
    return (stat);
}

champ_s* get_inv(champ_s* mc, char* line)
{
    int q1, q2, q3, i = 0;
    q1 = my_getnbnbr(line, &i);
    q2 = my_getnbnbr(line, &i);
    q3 = my_getnbnbr(line, &i);
    if (q1 == 1) {
        mc->q1 = 1;
        mc->spells = get_ete(mc);
    }
    if (q2 == 1) {
        mc->q2 = 1;
        mc->spells = get_automne(mc);
    }
    if (q3 == 1) {
        mc->q3 = 1;
    }
    return mc;
}

map_s* recup_map(char* id, char* x, char* y, champ_s** mc)
{
    map_s* gmap = map(str_to_int(id));
    sfVector2f pos = {str_to_int(x), str_to_int(y)};
    sfSprite_setPosition((*mc)->sprite, pos);
    return gmap;
}
