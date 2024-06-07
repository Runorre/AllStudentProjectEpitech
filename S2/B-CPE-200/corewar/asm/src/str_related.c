/*
** EPITECH PROJECT, 2023
** CoreWar
** File description:
** str_related
*/

#include "../include/asm.h"

int my_strlen(char *str)
{
    if (!str)
        return 0;
    int i = 0;
    for (; str[i]; i++)
        ;
    return i;
}

int my_strcmp(char *str_o, char *str_t)
{
    if (!str_o || !str_t)
        return -1;
    int i = 0;
    for (; str_o[i] && str_t[i] && str_o[i] == str_t[i]; i++);
    if (i == my_strlen(str_o) && my_strlen(str_o) == my_strlen(str_t))
        return 0;
    return 1;
}

int *len_words(char *str, char c, int *size)
{
    if (!str[0])
        return 0;
    int word_count = 1, space = 1, word = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == c && space == 0)
            word_count++, space = 1;
        if (str[i] != c)
            space = 0;
    }
    if (space == 1)
        word_count--;
    int *lens = malloc((word_count + 1) * sizeof(int)), lenth = 0, h = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == c && word == 1)
            lens[h] = lenth, lenth = 0, h++, word = 0;
        if (str[i] != c)
            lenth++, word = 1;
    }
    lens[h] = lenth, *size = word_count;
    return lens;
}

char **str_to_word_array(char *str, char c)
{
    if (my_strcmp(str, "\0") == 0)
        return NULL;
    int size;
    int *lens = len_words(str, c, &size);
    char **map = malloc((size + 1) * sizeof(char *));
    int i = 0, j = 0;
    for (int h = 0; i < size; i++) {
        for (; str[j] && str[j] == c; j++)
            ;
        map[i] = malloc((lens[i] + 1) * sizeof(char));
        for (h = 0; str[j] && str[j] != c; j++, h++)
            map[i][h] = str[j];
        map[i][h] = '\0';
    }
    map[i] = NULL;
    free(lens);
    return map;
}

char *my_strcat(char *str1, char *str2)
{
    int size_o = my_strlen(str1), size_tw = my_strlen(str2);
    char *answer = malloc((size_o + size_tw + 1) * sizeof(char));
    int i = 0;
    for (; i < size_o; i++)
        answer[i] = str1[i];
    for (int j = 0; j < size_tw; j++, i++)
        answer[i] = str2[j];
    answer[size_o + size_tw] = '\0';
    return answer;
}
