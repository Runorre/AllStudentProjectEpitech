/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** inv5
*/

#include "rpg.h"

void add_node_trophee(champ_s *champion, trophee_s *trophee)
{
    while (trophee->next)
        trophee = trophee->next;
    trophee_s *add = malloc(sizeof(trophee_s));
    if (champion->q1) {
        champion->q1 = false, add->id = 1, add->next = NULL;
        trophee->next = add;
        return;
    }
    if (champion->q2) {
        champion->q2 = false, add->id = 2, add->next = NULL;
        trophee->next = add;
        return;
    }
    if (champion->q3) {
        champion->q3 = false, add->id = 3, add->next = NULL;
        trophee->next = add;
        return;
    }
}

trophee_s *create_head_trophee(champ_s *champion)
{
    trophee_s *head = malloc(sizeof(trophee_s));
    if (champion->q1) {
        champion->q1 = false;
        head->id = 1;
        head->next = NULL;
        return (head);
    }
    if (champion->q2) {
        champion->q2 = false;
        head->id = 2;
        head->next = NULL;
        return (head);
    }
    if (champion->q3) {
        champion->q3 = false;
        head->id = 3;
        head->next = NULL;
        return (head);
    }
}

trophee_s *get_trophhe_from_champ(champ_s *champion)
{
    if (!champion->q1 && !champion->q2 && !champion->q3)
        return (NULL);
    bool q1 = champion->q1, q2 = champion->q2, q3 = champion->q3;
    trophee_s *trophee = create_head_trophee(champion);
    add_node_trophee(champion, trophee);
    add_node_trophee(champion, trophee);
    champion->q1 = q1, champion->q2 = q2, champion->q3 = q3;
    return (trophee);
}

void free_ll(elemnt_inv_s *elm)
{
    while (elm) {
        sfSprite_destroy(elm->icon);
        sfText_destroy(elm->text);
        elm = elm->next;
    }
}

void free_all_inv(wind_inv_s inv)
{
    sfRectangleShape_destroy(inv.button_spells);
    sfRectangleShape_destroy(inv.button_trophee);
    sfRectangleShape_destroy(inv.cadre);
    sfSprite_destroy(inv.fond);
    sfSprite_destroy(inv.ice);
    sfText_destroy(inv.texte_spells);
    sfText_destroy(inv.texte_trophee);
    sfRenderWindow_destroy(inv.wind_inv);
    free_ll(inv.co);
    free_ll(inv.qu);
    free_ll(inv.tr);
}
