/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** str_to_word_array_tom
*/

#include "rpg.h"

int nb_lettre(char *buffer, int i)
{
    int y = 0, compt = 0;
    while (i > 0) {
        while (buffer[y] && buffer[y] != 10)
            y++;
        while (buffer[y] == 10)
            y++;
        i--;
    }
    while (buffer[y] && buffer[y] != 10) {
        y++;
        compt++;
    }
    return (compt);
}

int compt_nb_mot(char *buffer)
{
    int i = 0, compt = 0;
    while (buffer[i]) {
        if (buffer[i] == 10 && buffer[i + 1] != 10) {
            compt++;
        }
        i++;
    }
    return (compt);
}

char **char_en_char_double(char *buffer)
{
    int nb_mot = compt_nb_mot(buffer), m = 0, l = 0, i = 0;
    char **src = malloc(sizeof(char *) * (nb_mot + 1));
    for (int i = 0; i < nb_mot; i++)
        src[i] = malloc(sizeof(char) * nb_lettre(buffer, i) + 1);
    while (buffer[i]) {
        while (buffer[i] && buffer[i] == 10)
            i++;
        while (buffer[i] && buffer[i] != 10) {
            src[m][l] = buffer[i];
            i++;
            l++;
        }
        while (buffer[i] && buffer[i] == 10)
            i++;
        src[m][l] = 0;
        l = 0;
        m++;
    }
    src[m] = NULL;
    return (src);
}
