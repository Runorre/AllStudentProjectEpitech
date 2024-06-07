/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** inv3
*/

#include "rpg.h"

void add_node_co(spells_s *spell, elemnt_inv_s *co, int i)
{
    while (co->next) {
        co = co->next;
    }
    elemnt_inv_s *add = malloc(sizeof(elemnt_inv_s));
    char *desc = NULL;
    if (spell->id == 1) {
        desc = flower;
        add = add_node_inv(sprite_flower, desc, i, (sfVector2f){0.64, 0.41});
    } else if (spell->id == 2) {
        desc = soleil;
        add = add_node_inv(sprite_soleil, desc, i, (sfVector2f){1.36, 1.31});
    } else {
        desc = leaf;
        add = add_node_inv(sprite_feuille, desc, i, (sfVector2f){0.64, 0.58});
    }
    co->next = add;
    add->next = NULL;
}

elemnt_inv_s *init_ll_inv_co(spells_s *spell)
{
    if (spell == NULL)
        return (NULL);
    elemnt_inv_s *co;
    int i = 2;
    if (spell->id == 1) {
        co = create_head_inv(sprite_flower, flower, (sfVector2f){0.64, 0.41});
    } else if (spell->id == 2) {
        co = create_head_inv(sprite_soleil, soleil, (sfVector2f){1.36, 1.31});
    } else {
        co = create_head_inv(sprite_feuille, leaf, (sfVector2f){0.64, 0.58});
    }
    co->next = NULL;
    spell = spell->next;
    while (spell) {
        add_node_co(spell, co, i);
        spell = spell->next;
        i++;
    }
    return (co);
}

void add_node_tr(trophee_s *trophee, elemnt_inv_s *tr, int i)
{
    while (tr->next) {
        tr = tr->next;
    }
    elemnt_inv_s *add = malloc(sizeof(elemnt_inv_s));
    if (trophee->id == 1) {
        add = add_node_inv(sprite_hair, hair, i, (sfVector2f){1, 1.12});
    } else if (trophee->id == 2) {
        add = add_node_inv(sprite_citrou, pumpkin, i, (sfVector2f){0.64, 0.6});
    } else {
        add = add_node_inv(sprite_king, king, i, (sfVector2f){1, 1.04});
    }
    tr->next = add;
    add->next = NULL;
}

elemnt_inv_s *init_ll_inv_tr(trophee_s *trophee)
{
    if (trophee == NULL)
        return (NULL);
    elemnt_inv_s *tr;
    int i = 2;
    if (trophee->id == 1) {
        tr = create_head_inv(sprite_hair, hair, (sfVector2f){1, 1.12});
    } else if (trophee->id == 2) {
        tr = create_head_inv(sprite_citrou, pumpkin, (sfVector2f){0.64, 0.59});
    } else {
        tr = create_head_inv(sprite_king, king, (sfVector2f){1, 1.04});
    }
    tr->next = NULL;
    trophee = trophee->next;
    while (trophee) {
        add_node_tr(trophee, tr, i);
        trophee = trophee->next;
        i++;
    }
    return (tr);
}

sfSprite *create_invsprite(char *titre, sfVector2f pos, sfVector2f scale)
{
    sfTexture *texture = sfTexture_createFromFile(titre, NULL);
    sfSprite *image = sfSprite_create();
    sfSprite_setPosition(image, pos);
    sfSprite_setTexture(image, texture, false);
    sfSprite_setScale(image, scale);
    return (image);
}
