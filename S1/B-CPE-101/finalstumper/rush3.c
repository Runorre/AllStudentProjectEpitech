/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** rush3
*/

#include "my.h"
#include <unistd.h>

int verifyrush(char *buff, int h)
{
    if (buff[0] == 'o')
        return 1;
    if (buff[0] == '/' || buff[0] == '*')
        return 2;
    if (buff[0] == 'B')
        return 6;
    if (buff[0] == 'A' && buff[h - 1] == 'A')
        return 3;
    if (buff[0] == 'A' && buff[h - 1] == 'C') {
        if (buff[my_strlen(buff) - 2] == 'C')
            return 4;
        else
            return 5;
    }
    return 0;
}

void showhv(int h, int v)
{
    my_put_nbr(h);
    my_putchar(' ');
    my_put_nbr(v);
}

void showrush3(char *buff, int h, int v)
{
    int verify = verifyrush(buff, h);
    if (verify == 0) {
        write(2, "none", 5);
        write(1, "\n", 1);
        return;
    }
    if (verify == 6) {
        my_putstr("[rush1-3] ");
        showhv(h, v);
        my_putstr(" || [rush1-4] ");
        showhv(h, v);
        my_putstr(" || [rush1-5] ");
        showhv(h, v);
    } else {
            my_putstr("[rush1-");
            my_put_nbr(verify);
            my_putstr("] ");
            showhv(h, v);
    }
    my_putchar('\n');
}

int rush3(char *buff)
{
    int h = 0, v = 1;
    if (buff[0] == '\0') {
        write(2, "none", 5);
        write(1, "\n", 1);
        return 84;
    }
    for (int i = 0; buff[i] != '\n'; i++)
        h++;
    for (int i = h + 1; buff[i] != '\0'; i++) {
        if (buff[i] == '\n')
            v++;
    }
    showrush3(buff, h, v);
    return 0;
}
