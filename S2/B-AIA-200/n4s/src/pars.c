/*
** EPITECH PROJECT, 2023
** B-AIA-200-MAR-2-1-n4s-sonny.rameaux
** File description:
** pars
*/

#include "../include/my.h"

int my_columnsnbr(char *str)
{
    int m = 0;
    int n = 0;
    if (!str)
        return -84;
    for (; str[n] != '\0'; n++) {
        if (str[n] == ':') {
            m++;
        }
    }
    m++;
    return m;
}

int my_spacelen(char *str, int n)
{
    int m = 0;
    while (str[n] != '\0' && str[n] != ':') {
        m++;
        n++;
    }
    return (m);
}

values *my_str_to_float_struct(char *str)
{
    int height = my_columnsnbr(str);
    if (height == -84) return NULL;
    int i = 0, x = 0; values *val = malloc(sizeof(values));
    char **array = malloc(sizeof(char *) * (height + 1));
    for (int y = 0; y <= height; y++, i++) {
        array[y] = malloc(sizeof(char) * (my_spacelen(str, i) + 1));
        for (x = 0; str[i] != '\0' && str[i] != ':' && str[i] != '\n'; x++) {
            array[y][x] = str[i];
            i++;
        }
        array[y][x] = '\0';
        if (str[i] == '\0') break;
    }
    array[height] = NULL;
    val->left = (float)atof(array[0]);
    val->midleft = (float)atof(array[8]);
    val->middle = (float)atof(array[15]);
    val->midright = (float)atof(array[24]);
    val->right = (float)atof(array[31]);
    return val;
}
