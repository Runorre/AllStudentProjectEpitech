/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** keyboard5
*/

#include "rpg.h"

void shake_screen(giu_s perso, perso_s fichier, char *name, sys_data *sys)
{
    sfClock *clock = sfClock_create(); float joan = 0.0;
    sfVector2i position = sfRenderWindow_getPosition(perso.window);
    sfVector2i position_one = {position.x + 35, position.y};
    sfVector2i position_two = {position.x - 35, position.y};
    while (joan < 40) {
        sfTime time = sfClock_getElapsedTime(clock);
        joan = sfTime_asMilliseconds(time);
        pos_debut(perso, perso.window, position_one);
        affichage(perso, fichier, name, sys);
    } sfClock_restart(clock);
    sfTime time = sfClock_getElapsedTime(clock);
    joan = sfTime_asMilliseconds(time);
    while (joan < 40) {
        sfTime time = sfClock_getElapsedTime(clock);
        joan = sfTime_asMilliseconds(time);
        pos_deux(perso, perso.window, position_two);
        affichage(perso, fichier, name, sys);
    } pos_apres(perso, perso.window, position);
    affichage(perso, fichier, name, sys); sfClock_destroy(clock);
}

char *event_moment(char *input, perso_s *fichier, giu_s perso, sys_data *sys)
{
    sfEvent event;
    int key = 0;
    while (sfRenderWindow_pollEvent(perso.window, &event)) {
        if (event.type == sfEvtClosed) {
            shake_screen(perso, *fichier, input, sys);
        }
        if (event.type == sfEvtKeyPressed) {
            key = event.key.code;
            char *nv_input = remplir_char(input, key, fichier);
            fichier->affiche = 0;
            return (nv_input);
        }
    }
    return (input);
}

char *generate_aleatoire(void)
{
    char *name = malloc(sizeof(char) * 7);
    for (int i = 0; i < 6; i++) {
        name[i] = (rand() % 26) + 97;
    }
    name[6] = 0;
    return (name);
}

char *check_witch_end(perso_s add, char *name)
{
    if (add.fini == 1) {
        if (name == NULL)
            name = generate_aleatoire();
        return (name);
    }
    return (generate_aleatoire());
}

void free_part(giu_s perso)
{
    sfRectangleShape_destroy(perso.button_hasard);
    sfRectangleShape_destroy(perso.place_input);
    sfRectangleShape_destroy(perso.button_open);
    sfText_destroy(perso.titre_open);
    sfText_destroy(perso.titre_hasard);
    sfText_destroy(perso.texte_open);
    sfText_destroy(perso.texte_to_open);
    sfText_destroy(perso.maj);
}
