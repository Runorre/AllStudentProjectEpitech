/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** get_save4
*/

#include "rpg.h"

inv_s *recup_inv(char *line)
{
    int i = 0;
    inv_s *inv = malloc(sizeof(inv_s));
    inv = create_head(line, &i);
    while (line[i])
        add_node(line, &i, inv);
    return (inv);
}

stats_s *recup_stats(char *dest)
{
    stats_s *stat = malloc(sizeof(stats_s));
    int i = 0;
    stat->attack = my_getnbnbr(dest, &i);
    stat->defense = my_getnbnbr(dest, &i);
    stat->magie = my_getnbnbr(dest, &i);
    stat->hp = my_getnbnbr(dest, &i);
    stat->max_hp = my_getnbnbr(dest, &i);
    stat->mp = my_getnbnbr(dest, &i);
    stat->max_mp = my_getnbnbr(dest, &i);
    return (stat);
}
