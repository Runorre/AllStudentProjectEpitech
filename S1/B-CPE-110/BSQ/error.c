/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-BSQ-angelo.anselmet
** File description:
** error manage
*/

#include "my.h"

int checkneg(char *num)
{
    if (num[0] == '-')
        return -1;
    return my_getnbr2(num);
}

int checklen(char *seed, int y)
{
    if (my_strlen(seed) <= y)
        return 0;
    return 1;
}

int checkseed(char *seed)
{
    for (int i = 0; seed[i] != '\0'; i++) {
        if (!(seed[i] == '.' || seed[i] == 'o'))
            return 1;
    }
    return 0;
}

int checkifsquare(char **square)
{
    int i = 1;
    int len = my_getnbr2(square[0]);
    if (len == -1)
        return 1;
    if (square[1] == NULL)
        return 1;
    int e = my_strlen(square[1]);
    while (square[i] != NULL) {
        if (!(square[i][0] == '\0') && e == my_strlen(square[i]))
            i++;
        else
            break;
    }
    if ((i - 1) != len)
        return 1;
    return 0;
}
