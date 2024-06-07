/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** inv4
*/

#include "rpg.h"

elemnt_inv_s *create_head_qu(champ_s *champion)
{
    elemnt_inv_s *head = malloc(sizeof(elemnt_inv_s));
    head->text = create_text_inv(150, 150, 20, Q1);
    if (champion->q1)
        head->icon = create_invsprite(CHECK, (sfVector2f){50, 150},
        (sfVector2f){1, 1.21});
    else
        head->icon = create_invsprite(WRONG, (sfVector2f){50, 150},
        (sfVector2f){1, 1.02});
    head->next = NULL;
    return (head);
}

void add_node_qu(elemnt_inv_s *qu, champ_s *champion, int i)
{
    elemnt_inv_s *add = malloc(sizeof(elemnt_inv_s));
    if (i == 2) {
        add->text = create_text_inv(150, 150 * i, 20, Q2);
        if (champion->q2) {
            add->icon = create_invsprite(CHECK, (sfVector2f){50, 150 * i},
                (sfVector2f){1, 1.21});
        } else {
            add->icon = create_invsprite(WRONG, (sfVector2f){50, 150 * i},
                (sfVector2f){1, 1.02});
        } add->next = NULL;
    } else {
        add->text = create_text_inv(150, 150 * i, 20, Q3);
        if (champion->q3) {
            add->icon = create_invsprite(CHECK, (sfVector2f){50, 150 * i},
                (sfVector2f){1, 1.21});
        } else {
            add->icon = create_invsprite(WRONG, (sfVector2f){50, 150 * i},
                (sfVector2f){1, 1.02});
        } add->next = NULL;
    } while (qu->next) { qu = qu->next; } qu->next = add;
}

elemnt_inv_s *init_struct_qu(champ_s *champion)
{
    elemnt_inv_s *qu = create_head_qu(champion);
    for (int i = 2; i < 4; i++)
        add_node_qu(qu, champion, i);
    return (qu);
}

wind_inv_s init_struct_inv(sfRenderWindow* window, champ_s *champion)
{
    wind_inv_s inv;
    inv.wind_inv = create_window_inv(champion->name);
    inv.button_spells = create_button(170, 30, 0, 0);
    inv.button_trophee = create_button(170, 30, 180, 0);
    inv.quete = create_button(170, 30, 360, 0);
    inv.texte_spells = create_text_inv(0, 0, 20, "Competence(s)");
    inv.texte_quete = create_text_inv(400, 0, 20, "Quetes");
    sfText_setColor(inv.texte_spells, sfColor_fromRGB(0, 0, 0));
    inv.texte_trophee = create_text_inv(206, 0, 20, "Trophee(s)");
    sfText_setColor(inv.texte_trophee, sfColor_fromRGB(0, 0, 0));
    inv.spells = true; inv.trophee = false; inv.w_quete = false;
    inv.cadre = create_button(960, 770, 0, 30);
    inv.co = init_ll_inv_co(champion->spells);
    inv.tr = init_ll_inv_tr(champion->trophee);
    inv.fond = create_invsprite(FOND, (sfVector2f){0, 30},
        (sfVector2f){2, 2.3});
    inv.ice = create_invsprite(FLOCON, (sfVector2f){150, 10},
        (sfVector2f){1, 1});
    inv.qu = init_struct_qu(champion);
    return (inv);
}

void check_click(wind_inv_s *inv)
{
    sfVector2i loc = sfMouse_getPositionRenderWindow(inv->wind_inv);
    sfFloatRect loc_sp = sfRectangleShape_getGlobalBounds(inv->button_spells);
    sfFloatRect loc_tr = sfRectangleShape_getGlobalBounds(inv->button_trophee);
    sfFloatRect loc_qu = sfRectangleShape_getGlobalBounds(inv->quete);
    if (sfFloatRect_contains(&loc_sp ,loc.x, loc.y) && inv->spells == false) {
        sfSprite_setPosition(inv->ice, (sfVector2f){150, 10});
        inv->spells = true;
        inv->trophee = inv->w_quete = false;
    }
    if (sfFloatRect_contains(&loc_tr ,loc.x, loc.y) && inv->trophee == false) {
        sfSprite_setPosition(inv->ice, (sfVector2f){330, 10});
        inv->trophee = true;
        inv->spells = inv->w_quete = false;
    }
    if (sfFloatRect_contains(&loc_qu ,loc.x, loc.y) && inv->w_quete == false) {
        sfSprite_setPosition(inv->ice, (sfVector2f){515, 10});
        inv->trophee = inv->spells = false;
        inv->w_quete = true;
    }
}
