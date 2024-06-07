/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** get_save3
*/

#include "rpg.h"

char *recup_chare(char *line, int *i)
{
    int y = *i, compt = 0, l = 0;
    while (line[y] && line[y] != '|') {
        compt++;
        y++;
    }
    char *src = malloc(sizeof(char) * compt + 1);
    y = *i;
    while (line[y] && line[y] != '|') {
        src[l] = line[y];
        l++;
        y++;
    }
    src[l] = 0;
    *i = y + 1;
    return (src);
}

void add_node(char *line, int *i, inv_s *inv)
{
    inv_s *add = malloc(sizeof(inv_s));
    add->name = recup_chare(line, i);
    add->id = my_getnbnbr(line, i);
    add->desc = recup_chare(line, i);
    add->stats = recup_stats_ll(line, i);
    add->next = NULL;
    while (inv->next)
        inv = inv->next;
    inv->next = add;
}

inv_s *create_head(char *line, int *i)
{
    inv_s *head = malloc(sizeof(inv_s));
    head->name = recup_chare(line, i);
    head->id = my_getnbnbr(line, i);
    head->desc = recup_chare(line, i);
    head->stats = recup_stats_ll(line, i);
    head->next = NULL;
    return (head);
}

spells_s *create_head_spell(char *line, int *i)
{
    spells_s *head = malloc(sizeof(spells_s));
    head->name = recup_chare(line, i);
    head->id = my_getnbnbr(line, i);
    head->desc = recup_chare(line, i);
    head->stats = recup_stats_ll(line, i);
    head->next = NULL;
    return (head);
}

void add_node_spell(char *line, int *i, spells_s *spell)
{
    spells_s *add = malloc(sizeof(spells_s));
    add->name = recup_chare(line, i);
    add->id = my_getnbnbr(line, i);
    add->desc = recup_chare(line, i);
    add->stats = recup_stats_ll(line, i);
    add->next = NULL;
    while (spell->next)
        spell = spell->next;
    spell->next = add;
}
