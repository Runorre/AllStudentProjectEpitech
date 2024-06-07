/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myradar-angelo.anselmet
** File description:
** game
*/

#include "my.h"

void create_offset(ll_plane **tmp)
{
    (*tmp)->obj->offset.x = (*tmp)->obj->end.x - (*tmp)->obj->pos.x;
    (*tmp)->obj->offset.y = (*tmp)->obj->end.y - (*tmp)->obj->pos.y;
    int absolue = 0;
    if (abs((*tmp)->obj->offset.x) > abs((*tmp)->obj->offset.y))
        absolue = abs((*tmp)->obj->offset.x);
    else
        absolue = abs((*tmp)->obj->offset.y);
    (*tmp)->obj->offset.x = ((*tmp)->obj->offset.x / absolue);
    (*tmp)->obj->offset.x *= ((float) (*tmp)->obj->speed / 10.0);
    (*tmp)->obj->offset.y = ((*tmp)->obj->offset.y / absolue);
    (*tmp)->obj->offset.y *= ((float) (*tmp)->obj->speed / 10.0);
}

void init_planesp(ll_plane **allplane, sfTexture *texture)
{
    for (ll_plane *tmp = *allplane; tmp; tmp = tmp->next) {
        tmp->obj->sp = sfSprite_create();
        sfSprite_setTexture(tmp->obj->sp, texture, sfTrue);
        sfSprite_setPosition(tmp->obj->sp, tmp->obj->pos);
        sfSprite_setOrigin(tmp->obj->sp, (sfVector2f) {0, 0});
        tmp->obj->hitbox = sfRectangleShape_create();
        sfRectangleShape_setSize(tmp->obj->hitbox, (sfVector2f) {20.0, 20.0});
        sfRectangleShape_setOutlineColor(tmp->obj->hitbox, sfGreen);
        sfRectangleShape_setFillColor(tmp->obj->hitbox, sfTransparent);
        sfRectangleShape_setOutlineThickness(tmp->obj->hitbox, 1.0);
        sfRectangleShape_setPosition(tmp->obj->hitbox, tmp->obj->pos);
        sfRectangleShape_setOrigin(tmp->obj->hitbox, (sfVector2f) {0, 0});
        set_rotation(tmp->obj);
        create_offset(&tmp);
    }
}

void init_towersp(ll_tower **alltower, sfTexture *texture)
{
    for (ll_tower * tp = *alltower; tp; tp = tp->next) {
        tp->obj->cir = sfCircleShape_create();
        sfCircleShape_setRadius(tp->obj->cir, 1080.0 * (tp->obj->rad / 100.0));
        sfCircleShape_setOutlineColor(tp->obj->cir, sfGreen);
        sfCircleShape_setFillColor(tp->obj->cir, sfTransparent);
        sfCircleShape_setOutlineThickness(tp->obj->cir, 1.0);
        sfCircleShape_setPosition(tp->obj->cir, tp->obj->pos);
        sfCircleShape_setOrigin(tp->obj->cir, tp->obj->poss);
        tp->obj->sp = sfSprite_create();
        sfSprite_setTexture(tp->obj->sp, texture, sfTrue);
        sfSprite_setPosition(tp->obj->sp, tp->obj->pos);
        sfSprite_setOrigin(tp->obj->sp, (sfVector2f) {256.0, 256.0});
        sfSprite_setScale(tp->obj->sp, (sfVector2f) {0.1, 0.1});
    }
}

void order66(ll_plane **allplane, ll_tower **alltower, sys_data *sys)
{
    for (ll_tower *tp = *alltower; tp; tp = tp->next) {
        sfSprite_destroy(tp->obj->sp);
        sfCircleShape_destroy(tp->obj->cir);
    }
    for (ll_plane *tmp = *allplane; tmp; tmp = tmp->next) {
        sfSprite_destroy(tmp->obj->sp);
        sfRectangleShape_destroy(tmp->obj->hitbox);
    }
    sfSprite_destroy(sys->bg);
}

int init_radar(ll_plane *allplane, ll_tower *alltower)
{
    sfVideoMode mode = {1920, 1080, 64};
    sys_data sys;
    sys.win = sfRenderWindow_create(mode, "MyRadar", sfResize | sfClose, NULL);
    sys.bg = sfSprite_create();
    sfTexture *planeT = sfTexture_createFromFile("./assets/plane.png", NULL);
    sfTexture *towerT = sfTexture_createFromFile("./assets/tower.png", NULL);
    sfTexture *bg = sfTexture_createFromFile("./assets/map.jpg", NULL);
    sfSprite_setTexture(sys.bg, bg, sfTrue);
    sfSprite_setScale(sys.bg, (sfVector2f) {0.86, 0.70});
    init_planesp(&allplane, planeT);
    init_towersp(&alltower, towerT);
    radar(allplane, alltower, &sys);
    order66(&allplane, &alltower, &sys);
    sfTexture_destroy(planeT);
    sfTexture_destroy(towerT);
    sfTexture_destroy(bg);
    free(allplane);
    free(alltower);
    sfRenderWindow_destroy(sys.win);
    return 0;
}
