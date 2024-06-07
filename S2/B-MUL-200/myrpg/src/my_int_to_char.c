/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** int to char
*/

#include "rpg.h"

char *put_nb_in_char(int nb, char *nb_char, int i, int size)
{
    int temp = nb, y = 0;
    while (size > 0) {
        while (y < size - 1) {
            temp /= 10;
            y++;
        }
        temp %= 10;
        nb_char[i] = temp + 48;
        i++;
        temp = nb;
        y = 0;
        size--;
    }
    nb_char[i] = 0;
    return (nb_char);
}

int compt_size(int nb)
{
    int compt = 0;
    if (nb == 0)
        return (1);
    if (nb < 0) {
        compt++;
        nb *= -1;
    }
    while (nb > 0) {
        nb /= 10;
        compt++;
    }
    return (compt);
}

char *my_int_to_char(int nb)
{
    int size = compt_size(nb);
    char *nb_char = malloc(sizeof(char) * size + 1);
    int i = 0;
    if (nb < 0) {
        nb_char[i] = '-';
        i++;
        nb *= -1;
        size--;
    }
    if (nb == 0) {
        nb_char[i] = '0';
        nb_char[i + 1] = 0;
        return (nb_char);
    }
    nb_char = put_nb_in_char(nb, nb_char, i, size);
    return (nb_char);
}
