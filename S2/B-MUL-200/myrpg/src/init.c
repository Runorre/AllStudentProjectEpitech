/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** init
*/

#include "rpg.h"

sfSprite* init_sprite(char* file)
{
    sfSprite* sprite = sfSprite_create();
    sfTexture* texture = sfTexture_createFromFile(file, NULL);
    if (texture == NULL) return NULL;
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}
