/*
** EPITECH PROJECT, 2022
** Rush-1-5
** File description:
** Square
*/

#include <unistd.h>

void arete(int x, int p, int m, int ap)
{
    if (x == 1){
        my_putchar(p);
        my_putchar('\n');
        return;
    }
    for (int i = 1; i != x; i++) {
        if (i == 1) {
            my_putchar(p);
        }
        if (i == (x - 1)) {
            my_putchar(ap);
        } else {
            my_putchar(m);
        }
    }
    my_putchar('\n');
}

void rush (int x, int y)
{
    int p = 'A', ap = 'C', h = 'B', s = ' ';
    if (x == 1 || y == 1) {
        p = h;
        ap = h;
    }
    char e[] = "Invalid size";
    if (y == 0 || x == 0) {
        write(2, "Invalid size\n", 13);
        return;
    }
    arete(x, p, h, ap);
    for (int i = 0; i != (y - 2) && (y - 2) > 0; i++) {
        arete(x, h, s, h);
    }
    if (y > 1) {
        arete(x, ap, h, p);
    }
}
