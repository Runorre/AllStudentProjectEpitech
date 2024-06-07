/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** editor_layer2
*/

#include "rpg.h"

void save_layer(int** layer, char* layername, int x, int y)
{
    int fd, i = 0, j, len;
    char* tmp, c;
    fd = open(layername, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        write(2, "Opening error\n", 15);
        return;
    }
    while (i < y) {
        j = 0;
        while (j < x) {
            len = len_nb(layer[i][j]);
            tmp = malloc(sizeof(char) * len + 1);
            tmp = int_to_str(layer[i][j], tmp);
            tmp[len] = '\0';
            write(fd, tmp, my_strlen(tmp));
            c = (j == x - 1) ? '\n' : ' ';
            write(fd, &c, 1);
            j ++;
        } i ++;
    }
}

void save_map(ed_layers* layers)
{
    int x, y;
    x = layers->x;
    y = layers->y;
    save_layer(layers->i_bg, my_strcat(layers->name, "_bg"), x, y);
    save_layer(layers->i_mid, my_strcat(layers->name, "_mid"), x, y);
    save_layer(layers->i_fg, my_strcat(layers->name, "_fg"), x, y);
}

void check_current_layer(selec_s* sel, ed_layers** layers, sfVector2f mouse)
{
    switch ((*layers)->current) {
        case BG:
            layer_clicked((*layers)->s_bg, mouse, sel, (*layers)->i_bg);
            break;
        case MID:
            layer_clicked((*layers)->s_mid, mouse, sel, (*layers)->i_mid);
            break;
        case FG:
            layer_clicked((*layers)->s_fg, mouse, sel, (*layers)->i_fg);
            break;
        default:
            break;
    }
}

void update_current_layer(selec_s* sel, ed_layers** layer)
{
    int i = 0;
    button_s* tmp = sel->layers_selected;
    while (tmp != NULL && tmp->status != PRESSED) {
        i ++;
        tmp = tmp->next;
    }
    switch (i) {
        case 0:
            (*layer)->current = BG;
            break;
        case 1:
            (*layer)->current = MID;
            break;
        case 2:
            (*layer)->current = FG;
            break;
        default:
            (*layer)->current = BG;
            break;
    }
}
