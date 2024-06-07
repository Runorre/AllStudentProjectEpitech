/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-mypaint-angelo.anselmet
** File description:
** main
*/

#include "my.h"

int add_color(button_shape *button)
{
    sfVector2f black = {30, 100};
    sfVector2f red = {70, 100};
    sfVector2f blue = {110, 100};
    sfVector2f green = {150, 100};
    sfVector2f size = {40, 40};
    button->shape[0] = init_button(black, size, sfBlack);
    button->shape[1] = init_button(red, size, sfRed);
    button->shape[2] = init_button(blue, size, sfBlue);
    button->shape[3] = init_button(green, size, sfGreen);
}

sys_data *init_system2(sys_data *sys)
{
    sys->m_s = EDIT;
    sys->button->open_pos = (sfVector2f) {125, 100};
    sys->button->open_size = (sfVector2u) {60, 40};
    sys->button->open = init_text(sys->button->open_pos, 25, "OPEN");
    sys->button->save_pos = (sfVector2f) {225, 100};
    sys->button->save_size = (sfVector2u) {60, 40};
    sys->button->save = init_text(sys->button->save_pos, 25, "SAVE");
    sys->pen->color_pen = sfBlack;
    sys->button->is_active = sfTrue;
    sys->pen->size = 20;
    sys->pen->size_pos = (sfVector2f) {380, 100};
    sys->pen->st_size = my_strcat("Size :", take_nbr(sys->pen->size));
    sys->pen->text_size = init_text(sys->pen->size_pos, 25, sys->pen->st_size);
    set_pencil(sys);
    set_eraser(sys);
    set_up(sys);
    set_down(sys);
    sys->save->pos_save = (sfVector2f) {500, 400};
    sys->save->save_text = init_text(sys->save->pos_save, 50, "Name of file:");
    return sys;
}

sys_data *init_system(void)
{
    sys_data *sys = malloc(sizeof(sys_data));
    sys->last_color = sfBlack;
    sys->button = malloc(sizeof(button_shape));
    sys->canva = malloc(sizeof(canva_shape));
    sys->sprites = malloc(sizeof(glob_sprites));
    sys->save = malloc(sizeof(save_conf));
    sys->pen = malloc(sizeof(pen_conf));
    sfVideoMode mode = {1920, 1080, 32};
    sys->button->shape = malloc(sizeof(sfRectangleShape*) * 4);
    sys->window = sfRenderWindow_create(mode, "my_paint", sfResize |
    sfClose, NULL);
    sys->button->is_active = sfFalse;
    sys->canva->pos_canva = (sfVector2f) {20, 180};
    sys->canva->canva_image = sfImage_createFromColor(1880, 800, sfWhite);
    sys->canva->canva_text = sfTexture_createFromImage(sys->canva->canva_image,
    NULL);
    sys->canva->canva = add_canva(sys->canva);
    sys->event = malloc(sizeof(sfEvent));
    return init_system2(sys);
}

int main(void)
{
    sys_data *sys = init_system();
    initmenu(sys);
    sys->c_hover = sfColor_fromRGBA(105, 105, 105, 70);
    sys->c_press = sfColor_fromRGBA(105, 105, 105, 30);
    sfColor sfGrey = sfColor_fromRGB(220,220,220);
    add_color(sys->button);
    sys->button->pos_button =
    sfRectangleShape_getPosition(sys->button->shape[0]);
    sys->button->size_button = (sfVector2u) {40, 40};
    sys->canva->pos_canva = sfSprite_getPosition(sys->canva->canva);
    sys->canva->size_canva = sfImage_getSize(sys->canva->canva_image);
    sys->canva->mousepress = 0;
    while (sfRenderWindow_isOpen(sys->window))
        inter_loop(sys, sfGrey);
    sfRenderWindow_destroy(sys->window);
    free(sys->button);
    free(sys->canva);
    free(sys);
    return 0;
}
