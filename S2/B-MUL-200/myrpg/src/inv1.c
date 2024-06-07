/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** inv1
*/

#include "rpg.h"

bool event_moment_inv(wind_inv_s *inv, sfClock* clock)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(inv->wind_inv, &event)) {
        if (event.type == sfEvtClosed)
            return true;
        if (event.key.code == sfKeyI &&
            sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 0.5)
            return true;
        if (event.type == sfEvtMouseButtonReleased) {
            check_click(inv);
            return (false);
        }
    }
    return (false);
}

void affichage_inv_spell(wind_inv_s inv, elemnt_inv_s *elm)
{
    while (elm) {
        sfRenderWindow_drawSprite(inv.wind_inv, elm->icon, NULL);
        sfRenderWindow_drawText(inv.wind_inv, elm->text, NULL);
        elm = elm->next;
    }
}

void affichage_inv(wind_inv_s inv)
{
    sfRenderWindow_display(inv.wind_inv);
    sfRenderWindow_clear(inv.wind_inv, sfColor_fromRGB(38, 196, 236));
    sfRenderWindow_drawRectangleShape(inv.wind_inv, inv.button_trophee, NULL);
    sfRenderWindow_drawRectangleShape(inv.wind_inv, inv.button_spells, NULL);
    sfRenderWindow_drawRectangleShape(inv.wind_inv, inv.quete, NULL);
    sfRenderWindow_drawText(inv.wind_inv, inv.texte_spells, NULL);
    sfRenderWindow_drawText(inv.wind_inv, inv.texte_trophee, NULL);
    sfRenderWindow_drawText(inv.wind_inv, inv.texte_quete, NULL);
    sfRenderWindow_drawRectangleShape(inv.wind_inv, inv.cadre, NULL);
    sfRenderWindow_drawSprite(inv.wind_inv, inv.fond, NULL);
    sfRenderWindow_drawSprite(inv.wind_inv, inv.ice, NULL);
    if (inv.spells) {
        affichage_inv_spell(inv, inv.co);
    } else if (inv.trophee) {
        affichage_inv_spell(inv, inv.tr);
    } else {
        affichage_inv_spell(inv, inv.qu);
    }
}

void hover_inv(wind_inv_s *inv)
{
    sfVector2i loc = sfMouse_getPositionRenderWindow(inv->wind_inv);
    sfFloatRect loc_sp = sfRectangleShape_getGlobalBounds(inv->button_spells);
    sfFloatRect loc_tr = sfRectangleShape_getGlobalBounds(inv->button_trophee);
    sfFloatRect loc_qu = sfRectangleShape_getGlobalBounds(inv->quete);
    sfColor couleur = sfColor_fromRGB(30, 144, 255);
    if (sfFloatRect_contains(&loc_sp ,loc.x, loc.y))
        sfRectangleShape_setFillColor(inv->button_spells, couleur);
    else
        sfRectangleShape_setFillColor(inv->button_spells, sfWhite);
    if (sfFloatRect_contains(&loc_tr ,loc.x, loc.y))
        sfRectangleShape_setFillColor(inv->button_trophee, couleur);
    else
        sfRectangleShape_setFillColor(inv->button_trophee, sfWhite);
    if (sfFloatRect_contains(&loc_qu ,loc.x, loc.y))
        sfRectangleShape_setFillColor(inv->quete, couleur);
    else
        sfRectangleShape_setFillColor(inv->quete, sfWhite);
}

void inventaire(sys_data* sys, champ_s *champion)
{
    sfView_reset(sys->view, sys->rect_view);
    sfRenderWindow_setView(sys->window, sys->view);
    sfRenderWindow_setMouseCursorVisible(sys->window, sfTrue);
    champion->trophee = get_trophhe_from_champ(champion);
    wind_inv_s inv = init_struct_inv(sys->window, champion);
    bool end_affichage = false;
    sfClock* clock = sfClock_create();
    while (!end_affichage) {
        affichage_inv(inv);
        hover_inv(&inv);
        end_affichage = event_moment_inv(&inv, clock);
    }
    sfRenderWindow_close(inv.wind_inv);
    sfRenderWindow_destroy(inv.wind_inv);
    sfRenderWindow_setMouseCursorVisible(sys->window, sfFalse);
    sfView_zoom(sys->view, 0.7);
}
