/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** inv2
*/

#include "rpg.h"

sfRectangleShape *create_button(int t_rec_x, int t_rec_y, int posx, int posy)
{
    sfVector2f taille_rec = {t_rec_x, t_rec_y};
    sfVector2f pos_rec = {posx, posy};
    sfRectangleShape *button = sfRectangleShape_create();
    sfRectangleShape_setSize(button, taille_rec);
    sfRectangleShape_setPosition(button, pos_rec);
    sfRectangleShape_setOutlineColor(button, sfColor_fromRGB(0, 0, 0));
    sfRectangleShape_setOutlineThickness(button, 2);
    return (button);
}

sfText *create_text_inv(int posx, int posy, int taille, char *string)
{
    sfFont *texture = sfFont_createFromFile("utilities/fonts/ice.ttf");
    sfVector2f pos = {posx, posy};
    sfText *texte = sfText_create();
    sfText_setCharacterSize(texte, taille);
    sfText_setFont(texte, texture);
    sfText_setPosition(texte, pos);
    sfText_setString(texte, string);
    sfText_setFillColor(texte, sfBlack);
    return (texte);
}

sfRenderWindow *create_window_inv(char *name)
{
    char *titre = my_strcat("Inventaire de ", name);
    sfVideoMode mode = {960, 800, 32};
    sfRenderWindow *window;
    window = sfRenderWindow_create(mode, titre, sfClose , NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    free(titre);
    return (window);
}

elemnt_inv_s *add_node_inv(char *file, char *description, int i,
sfVector2f scale)
{
    sfTexture *texture = sfTexture_createFromFile(file, NULL);
    elemnt_inv_s *add = malloc(sizeof(elemnt_inv_s));
    add->icon = sfSprite_create();
    sfSprite_setPosition(add->icon, (sfVector2f){50, 150 * i});
    sfSprite_setTexture(add->icon, texture, false);
    sfSprite_setScale(add->icon, scale);
    add->text = create_text_inv(150, 150 * i, 20, description);
    return (add);
}

elemnt_inv_s *create_head_inv(char *file, char *description, sfVector2f scale)
{
    sfTexture *texture = sfTexture_createFromFile(file, NULL);
    elemnt_inv_s *head = malloc(sizeof(elemnt_inv_s));
    head->icon = sfSprite_create();
    sfSprite_setPosition(head->icon, (sfVector2f){50, 150});
    sfSprite_setTexture(head->icon, texture, false);
    sfSprite_setScale(head->icon, scale);
    head->text = create_text_inv(150, 150, 20, description);
    return (head);
}
