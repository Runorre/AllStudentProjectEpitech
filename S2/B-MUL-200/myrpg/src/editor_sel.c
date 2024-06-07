/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** editor_sel
*/

#include "rpg.h"

void update_sel_buttons(selec_s** sel, int i)
{
    int j = 0;
    button_s* tmp = (*sel)->layers_selected;
    sfIntRect* rect = malloc(sizeof(sfIntRect));
    sfTexture* texture;
    rect->top = 0, rect->width = 1690 / 2, rect->height = 272;
    tmp = (*sel)->layers_selected;
    while (tmp != NULL) {
        if (i == j) {
            tmp->status = PRESSED;
            rect->left = rect->width;
        } else {
            tmp->status = IDLE;
            rect->left = 0;
        } texture = sfTexture_createFromFile(tmp->file, rect);
        sfRectangleShape_setTexture(tmp->rect, texture, sfTrue);
        tmp = tmp->next, j ++;
    }
}

int sel_buttons_clicked(sfMouseButtonEvent mouse, selec_s** sel,
    ed_layers* layers)
{
    int i = 0, check = 0;
    button_s* tmp = (*sel)->layers_selected;
    if (is_rect_clicked((*sel)->save->rect, (sfVector2f){mouse.x, mouse.y})) {
        save_map(layers);
        return 0;
    }
    while (tmp != NULL) {
        if (is_rect_clicked(tmp->rect, (sfVector2f){mouse.x, mouse.y})) {
            check = 1;
            break;
        }
        i ++, tmp = tmp->next;
    }
    if (!check) return 0;
    update_sel_buttons(sel, i);
    return 1;
}

void draw_sel(sfRenderWindow* window, selec_s* sel)
{
    sfRenderWindow_drawRectangleShape(window, sel->rect, NULL);
    display_buttons(window, sel->layers_selected);
    display_buttons(window, sel->save);
}

selec_s* init_sel_buttons(selec_s* sel)
{
    sfIntRect* rect = malloc(sizeof(sfIntRect));
    sfTexture* texture;
    rect->top = 0, rect->width = 1690 / 2,
    rect->height = 272; rect->left = rect->width;
    sel->layers_selected = init_buttons_list(
        my_str_to_word_array("Background\nMiddleground\nForeground"),
        "./utilities/sprites/button.png", (sfVector2f){1375, 875},
        (sfVector2f){275, 55});
    sel->save = init_button("Save", "./utilities/sprites/button.png",
        (sfVector2f){1375 + 300, 875}, (sfVector2f){150, 55});
    sel->layers_selected->status = PRESSED;
    texture = sfTexture_createFromFile(sel->layers_selected->file, rect);
    sfRectangleShape_setTexture(sel->layers_selected->rect, texture, sfTrue);
    return sel;
}

selec_s* init_selection(void)
{
    selec_s* sel = malloc(sizeof(selec_s));
    int i = 1, j = 1, size = 32;
    sel->id = 1;
    sel->tile = init_palette_sprite(i, j, size);
    sel->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(sel->rect, (sfVector2f){size, size});
    sfRectangleShape_setPosition(sel->rect,
        (sfVector2f){1920 - 14 * 32, 1080 / 3 - 300});
    sfRectangleShape_setOutlineColor(sel->rect, sfRed);
    sfRectangleShape_setOutlineThickness(sel->rect, 2);
    sfRectangleShape_setFillColor(sel->rect, sfColor_fromRGBA(255, 0, 0, 50));
    sel = init_sel_buttons(sel);
    return sel;
}
