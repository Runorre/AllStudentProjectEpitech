/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** keyboard2
*/

#include "rpg.h"

int mauvaise_key(int key)
{
    if (key >= 26) {
        if (key == 38 || key == 58 || key == 59 || key == 57 || key == 34
        || (key >= 75 && key <= 84) || key == 48) {
            return (0);
        }
        return (1);
    }
    return (0);
}

char *my_realloc(int key, char *texte, perso_s *fichier)
{
    if (fichier->taille >= 24)
        return (texte);
    char *temp;
    if (texte != NULL) {
        temp = malloc(sizeof(char) * (my_strlen(texte) + 2));
    } else
        temp = malloc(sizeof(char) * 2);
    int i = 0;
    for (; texte != NULL && texte[i]; i++)
        temp[i] = texte[i];
    if (fichier->touch != 0)
        temp[i] = fichier->touch;
    else
        temp[i] = key + fichier->maj;
    temp[i + 1] = '\0';
    if (texte != NULL)
        free(texte);
    fichier->taille += 1;
    return (temp);
}

char *enleve_char(char *texte, perso_s *fichier)
{
    if (texte == NULL)
        return (texte);
    int taille = my_strlen(texte);
    if (taille == 0)
        return (NULL);
    char *nv_texte = malloc(sizeof(char) * taille);
    int i = 0;
    while (texte[i] && texte[i + 1]) {
        nv_texte[i] = texte[i];
        i++;
    }
    nv_texte[i] = '\0';
    free(texte);
    fichier->taille -= 2;
    return (nv_texte);
}

int no_change(int key, perso_s *fichier)
{
    if (key == -1 || mauvaise_key(key) == 1)
        return (1);
    if (key == 38) {
        if (fichier->maj == 97) {
            fichier->maj = 65;
            return (1);
        }
        fichier->maj = 97;
        return (1);
    }
    if (key == 58) {
        fichier->fini = 1;
        return (1);
    }
    return (0);
}

char *remplir_char(char *texte, int key, perso_s *fichier)
{
    if (no_change(key, fichier) == 1)
        return (texte);
    char *nv_texte = NULL;
    if (key == 59) {
        nv_texte = enleve_char(texte, fichier);
        return (nv_texte);
    }
    if (key == 57)
        fichier->touch = 32;
    if (key == 34)
        fichier->touch = 95;
    if (key >= 75 && key <= 84)
        fichier->touch = 48 + (key - 75);
    if (key == 48)
        fichier->touch = 46;
    nv_texte = my_realloc(key, texte, fichier);
    return (nv_texte);
}
