/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** keyboard3
*/

#include "rpg.h"

void clik_button(sfRectangleShape *open, sfRectangleShape *annul,
perso_s *fichier, sfRenderWindow *window)
{
    sfVector2i loc = sfMouse_getPositionRenderWindow(window);
    sfFloatRect loc_sauv = sfRectangleShape_getGlobalBounds(open);
    sfFloatRect loc_annu = sfRectangleShape_getGlobalBounds(annul);
    if (sfFloatRect_contains(&loc_sauv ,loc.x, loc.y)) {
        sfRectangleShape_setFillColor(open, sfColor_fromRGB(158, 158, 158));
        sfRectangleShape_setFillColor(annul, sfColor_fromRGB(255, 255, 255));
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            fichier->fini = 1;
        return;
    }
    if (sfFloatRect_contains(&loc_annu ,loc.x, loc.y)) {
        sfRectangleShape_setFillColor(annul, sfColor_fromRGB(158, 158, 158));
        sfRectangleShape_setFillColor(open, sfColor_fromRGB(255, 255, 255));
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            fichier->fini = 2;
        return;
    } else {
        sfRectangleShape_setFillColor(annul, sfColor_fromRGB(255, 255, 255));
        sfRectangleShape_setFillColor(open, sfColor_fromRGB(255, 255, 255));
    }
}

perso_s init_struct_perso(void)
{
    perso_s fichier;
    fichier.fini = 0;
    fichier.maj = 97;
    fichier.touch = 0;
    fichier.taille = 0;
    return (fichier);
}

sfRectangleShape *create_save(int t_rec_x, int t_rec_y, int posx, int posy)
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

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {500, 150, 32};
    sfRenderWindow *window;
    window = sfRenderWindow_create(mode, "Nom du Personnage", sfClose |
    sfResize , NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

sfText *create_kbtext(int posx, int posy, int taille, char *string)
{
    sfFont *texture = sfFont_createFromFile("utilities/fonts/ArialCE.ttf");
    sfVector2f pos = {posx, posy};
    sfText *texte = sfText_create();
    sfText_setCharacterSize(texte, taille);
    sfText_setFont(texte, texture);
    sfText_setPosition(texte, pos);
    sfText_setString(texte, string);
    return (texte);
}
