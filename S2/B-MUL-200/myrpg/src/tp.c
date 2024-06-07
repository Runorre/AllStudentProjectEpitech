/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** tp
*/

#include "rpg.h"

map_s* map(int id)
{
    switch (id) {
        case 1:
            return map1();
        case 2:
            return map2();
        case 3:
            return map3();
        case 4:
            return map4();
        case 5:
            return map5();
        default:
            break;
    }
    return map1();
}

int tp_collision(sfSprite* sprite, sfVector2f size_a, sfRectangleShape* rect)
{
    sfVector2f pos_a = sfSprite_getPosition(sprite);
    sfVector2f pos_b = sfRectangleShape_getPosition(rect);
    sfVector2f size_b = sfRectangleShape_getSize(rect);
    if ((pos_a.x) < (pos_b.x + size_b.x)
        && (pos_a.x + size_a.x) > (pos_b.x)
        && (pos_a.y) < (pos_b.y + size_b.y)
        && (pos_a.y + size_a.y) > (pos_b.y)) {
        return 1;
    }
    return 0;
}

void tp_map(tp_s* tp, champ_s* mc, sys_data* sys)
{
    tp_s* tmp = tp;
    sfVector2f size_mc = {32.0, 32.0};
    while (tmp != NULL) {
        if (tp_collision(mc->sprite, size_mc, tmp->rect)) {
            sfSprite_setPosition(mc->sprite, tmp->pos);
            game(sys, map(tmp->dest), mc);
            break;
        }
        tmp = tmp->next;
    }
    return;
}

void draw_tp(sfRenderWindow* window, tp_s* tp)
{
    tp_s* tmp = tp;
    while (tmp != NULL) {
        sfRenderWindow_drawRectangleShape(window, tmp->rect, NULL);
        tmp = tmp->next;
    }
}

tp_s* add_tp(tp_s* head, sfRectangleShape* rect, int id, sfVector2f pos)
{
    tp_s* tmp = malloc(sizeof(tp_s));
    tmp->dest = id;
    tmp->rect = rect;
    tmp->pos = pos;
    if (head == NULL) {
        tmp->next = NULL;
        return tmp;
    }
    tmp->next = head;
    return tmp;
}
