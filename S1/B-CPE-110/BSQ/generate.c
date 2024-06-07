/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-BSQ-angelo.anselmet
** File description:
** generate
*/

#include "my.h"

char **createvalue(int y, char *num)
{
    char **square = malloc(sizeof(char *) * (y + 2));
    square[0] = malloc(sizeof(char) * (my_strlen(num) + 1));
    square[0] = num;
    return square;
}

char *createlinegenere(char const *line, int y, int decale, int len)
{
    int i = decale;
    char *square = malloc(sizeof(char) * y + 1);
    for (int x = 0; x != y; x++) {
        if (line[i] == '\0' || len == 1)
            i = 0;
        square[x] = line[i];
        i++;
    }
    return square;
}

char *antibug(char **ar, int len)
{
    char *ab = malloc(sizeof(char) * 3);
    if (len == 1 && ar[2][0] == '.') {
        ab[0] = '.';
        ab[1] = '.';
        ab[2] = '\0';
        return ab;
    }
    if (len == 1 && ar[2][0] == 'o') {
        ab[0] = 'o';
        ab[1] = 'o';
        ab[2] = '\0';
        return ab;
    }
    return ar[2];
}

int generate(char **ar)
{
    int y = checkneg(ar[1]), len = (my_strlen(ar[2]));
    int len2 = my_strlen(ar[2]);
    ar[2] = antibug(ar, len2);
    int y_square = 1, decale = 0;
    if (y == -1)
        return 84;
    char **square = createvalue(y, ar[1]);
    while (y_square != y + 1) {
        if (len == decale)
            decale = 0;
        square[y_square] = createlinegenere(ar[2], y, decale, len2);
        decale++;
        y_square++;
    }
    int final = bsq2(square);
    free(square);
    return final;
}
