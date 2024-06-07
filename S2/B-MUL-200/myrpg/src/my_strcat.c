/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** my_strcat
*/

#include "rpg.h"

int my_strlen(char const* str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char* my_strcat(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int i = 0;
    int j = 0;
    char *dest;
    dest = malloc(sizeof(char) * (len1 + len2) + 1);
    while (i < len1) {
        dest[i] = str1[i];
        i ++;
    }
    while (j < len2) {
        dest[i] = str2[j];
        j ++;
        i ++;
    }
    dest[i] = '\0';
    return dest;
}
