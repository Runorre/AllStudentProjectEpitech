/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** editor
*/

#include "rpg.h"

void ed_pressed_cases(sys_data* sys, var_editor** v_ed, ed_layers** layers)
{
    if (sys->event.mouseButton.button == sfMouseLeft) {
        if (sel_buttons_clicked(sys->event.mouseButton,
            &(*v_ed)->sel, *layers)) {
            update_current_layer((*v_ed)->sel, layers);
        pal_clicked(&(*v_ed)->pal, &sys->event.mouseButton, &(*v_ed)->sel);
        check_current_layer((*v_ed)->sel, layers,
            (sfVector2f){sys->event.mouseButton.x, sys->event.mouseButton.y});
        (*v_ed)->sel->status = DRAWING;
        }
        if (sel_buttons_clicked(sys->event.mouseButton,
            &(*v_ed)->sel, *layers)) {
            update_current_layer((*v_ed)->sel, layers);
        }
        pal_clicked(&(*v_ed)->pal, &sys->event.mouseButton, &(*v_ed)->sel);
        check_current_layer((*v_ed)->sel, layers,
            (sfVector2f){sys->event.mouseButton.x, sys->event.mouseButton.y});
        (*v_ed)->sel->status = DRAWING;
    }
}

void events_editor(sys_data* sys, var_editor** v_ed, ed_layers** layers)
{
    switch (sys->event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(sys->window);
            break;
        case sfEvtMouseButtonPressed:
            ed_pressed_cases(sys, v_ed, layers);
            break;
        case sfEvtMouseButtonReleased:
            (*v_ed)->sel->status = HANDS_UP;
        default:
            break;
    }
}

var_editor* init_var_editor(int x, int y)
{
    var_editor* v_ed = malloc(sizeof(var_editor));
    v_ed->pal = init_palette();
    v_ed->sel = init_selection();
    v_ed->bg_pal = init_rect(
        (sfVector2f){1920 - 14 * 32 - 5, 1080 / 3 - 300 - 5},
        (sfVector2f){32 * 13 + 10, 32 * 25 + 10},
            sfColor_fromRGB(255, 102, 102));
    v_ed->bg_map = init_rect(
        (sfVector2f){3, 3}, (sfVector2f){x * 32, y * 32}, sfBlack);
    return v_ed;
}

void editor(int x, int y, sys_data* sys, char* name)
{
    var_editor* v_ed = init_var_editor(x, y);
    ed_layers* layers = init_layers(x, y, name);
    sfRenderWindow_setMouseCursorVisible(sys->window, sfTrue);
    while (sfRenderWindow_isOpen(sys->window)) {
        while (sfRenderWindow_pollEvent(sys->window, &sys->event)) {
            events_editor(sys, &v_ed, &layers);
        }
        if (v_ed->sel->status == DRAWING) {
            check_current_layer(v_ed->sel, &layers,
                (sfVector2f){sys->event.mouseMove.x, sys->event.mouseMove.y});
        }
        sfRenderWindow_clear(sys->window, sfColor_fromRGB(255, 204, 153));
        sfRenderWindow_drawRectangleShape(sys->window, v_ed->bg_pal, NULL);
        sfRenderWindow_drawRectangleShape(sys->window, v_ed->bg_map, NULL);
        draw_palette(sys->window, v_ed->pal);
        draw_sel(sys->window, v_ed->sel);
        draw_layers_editor(sys->window, layers);
        sfRenderWindow_display(sys->window);
    }
}
