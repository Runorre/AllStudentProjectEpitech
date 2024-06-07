/*
** EPITECH PROJECT, 2022
** Rush-1-1
** File description:
** Square
*/

#include <unistd.h>

void arete(int x, int p, int m)
{
    for (int i = 0; i != x; i++) {
        if (i == 0 || i == (x - 1))
            my_putchar(p);
        else
            my_putchar(m);
    }
    my_putchar('\n');
}

void rush (int x, int y)
{
    int p = 'o', h = '-', v = '|', s = ' ';
    if (y == 0 || x == 0) {
        write(2, "Invalid size\n", 13);
        return;
    }
    arete(x, p, h);
    for (int i = 0; i != (y - 2) && (y - 2) > 0; i++) {
        arete(x, v, s);
    }
    if (y > 1) {
    arete(x, p, h);
    }
}
