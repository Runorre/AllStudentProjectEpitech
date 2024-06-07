/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** keyboard4
*/

#include "rpg.h"

giu_s init_struct_giu(void)
{
    giu_s pers;
    pers.affiche = 0;
    pers.window = create_window();
    pers.place_input = create_save(400, 50, 45, 50);
    pers.button_open = create_save(150, 29, 340, 115);
    pers.button_hasard = create_save(150, 29, 170, 115);
    pers.titre_open = create_kbtext(380, 120, 15, "Enregistrer");
    sfText_setColor(pers.titre_open, sfColor_fromRGB(0, 86, 37));
    pers.titre_hasard = create_kbtext(205, 120, 15, "Peu Importe");
    sfText_setColor(pers.titre_hasard, sfColor_fromRGB(133, 6, 6));
    pers.texte_open = create_kbtext(147, 16, 20, "Nom du Personnage:");
    sfText_setColor(pers.texte_open, sfColor_fromRGB(0, 0, 0));
    pers.texte_to_open = create_kbtext(85, 65, 20, NULL);
    sfText_setColor(pers.texte_to_open, sfColor_fromRGB(0, 0, 0));
    pers.maj = create_kbtext(24, 65, 20, "MAJ");
    sfText_setColor(pers.maj, sfColor_fromRGB(0, 0, 0));
    pers.end = create_kbtext(25, 65, 20, "Votre personnage s'appelle:");
    sfText_setColor(pers.end, sfColor_fromRGB(0, 0, 0));
    return (pers);
}

void affichage(giu_s open, perso_s fichier, char *name, sys_data *sys)
{
    sfRenderWindow_display(sys->window);
    sfRenderWindow_display(open.window);
    sfRenderWindow_clear(open.window, sfColor_fromRGB(255, 255, 255));
    sfRenderWindow_drawRectangleShape(open.window, open.place_input, NULL);
    sfRenderWindow_drawRectangleShape(open.window, open.button_open, NULL);
    sfRenderWindow_drawRectangleShape(open.window, open.button_hasard, NULL);
    sfRenderWindow_drawText(open.window, open.titre_open, NULL);
    sfRenderWindow_drawText(open.window, open.titre_hasard, NULL);
    sfRenderWindow_drawText(open.window, open.texte_open, NULL);
    sfRenderWindow_drawText(open.window, open.texte_to_open, NULL);
    if (fichier.maj == 65)
        sfRenderWindow_drawText(open.window, open.maj, NULL);
    if (name == NULL) {
        sfText_setString(open.texte_to_open, "Entrer un nom");
    } else {
        sfText_setString(open.texte_to_open, name);
    }
}

void pos_debut(giu_s perso, sfRenderWindow *window, sfVector2i position_one)
{
    sfRenderWindow_setPosition(window, position_one);
    sfRectangleShape_setPosition(perso.button_hasard, (sfVector2f){160, 115});
    sfRectangleShape_setPosition(perso.button_open, (sfVector2f){330, 115});
    sfRectangleShape_setPosition(perso.place_input, (sfVector2f){35, 50});
    sfText_setPosition(perso.titre_open, (sfVector2f){355, 120});
    sfText_setPosition(perso.titre_hasard, (sfVector2f){185, 120});
    sfText_setPosition(perso.texte_open, (sfVector2f){137, 16});
    sfText_setPosition(perso.texte_to_open, (sfVector2f){75, 65});
    sfText_setPosition(perso.titre_hasard, (sfVector2f){185, 120});
    sfText_setPosition(perso.maj, (sfVector2f){14, 65});
}

void pos_apres(giu_s perso, sfRenderWindow *window, sfVector2i position)
{
    sfRenderWindow_setPosition(window, position);
    sfRectangleShape_setPosition(perso.button_hasard, (sfVector2f){170, 115});
    sfRectangleShape_setPosition(perso.button_open, (sfVector2f){340, 115});
    sfRectangleShape_setPosition(perso.place_input, (sfVector2f){45, 50});
    sfText_setPosition(perso.titre_open, (sfVector2f){365, 120});
    sfText_setPosition(perso.titre_hasard , (sfVector2f){195, 120});
    sfText_setPosition(perso.texte_open , (sfVector2f){147, 16});
    sfText_setPosition(perso.texte_to_open , (sfVector2f){85, 65});
    sfText_setPosition(perso.titre_hasard , (sfVector2f){195, 120});
    sfText_setPosition(perso.maj , (sfVector2f){24, 65});
}

void pos_deux(giu_s perso, sfRenderWindow *window, sfVector2i position_two)
{
    sfRenderWindow_setPosition(window, position_two);
    sfRectangleShape_setPosition(perso.button_hasard, (sfVector2f){180, 115});
    sfRectangleShape_setPosition(perso.button_open, (sfVector2f){350, 115});
    sfRectangleShape_setPosition(perso.place_input, (sfVector2f){55, 50});
    sfText_setPosition(perso.titre_open, (sfVector2f){375, 120});
    sfText_setPosition(perso.titre_hasard , (sfVector2f){205, 120});
    sfText_setPosition(perso.texte_open , (sfVector2f){157, 16});
    sfText_setPosition(perso.texte_to_open , (sfVector2f){95, 65});
    sfText_setPosition(perso.titre_hasard , (sfVector2f){205, 120});
    sfText_setPosition(perso.maj , (sfVector2f){34, 65});
}
