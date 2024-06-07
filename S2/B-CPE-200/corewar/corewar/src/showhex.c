/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-corewar-angelo.anselmet
** File description:
** showhex
*/

#include "corewar.h"

int my_pow(int nb, int power)
{
    int ans = 1;
    for (int i = 0; i < power; i++)
        ans *= nb;
    return ans;
}

void print_hexa(char c)
{
    int ans = 0;
    for (int i = 7, p = 0, pow = 3; i > 3; i--, pow--) {
        p = c >> i;
        ans += (p & 1) * my_pow(2, pow);
    }
    int ans2 = 0;
    for (int i = 3, p = 0, pow = 3; i >= 0; i--, pow--) {
        p = c >> i;
        ans2 += (p & 1) * my_pow(2, pow);
    }
    if (ans < 10)
        my_put_nbr(ans);
    else
        my_putchar((ans - 10) + 'A');
    if (ans2 < 10)
        my_put_nbr(ans2);
    else
        my_putchar((ans2 - 10) + 'A');
}

void colorplayer(champ *p)
{
    switch (p->allpc->reg[0]) {
    case 1:
        my_putstr("\033[1;34m");
        break;
    case 2:
        my_putstr("\033[1;31m");
        break;
    case 3:
        my_putstr("\033[1;33m");
        break;
    case 4:
        my_putstr("\033[1;32m");
        break;
    }
}

void showarena(char *arena, champ *p)
{
    int e = 0;
    for (int i = 0; i != MEM_SIZE; i++) {
        if (p && p->start == i)
            colorplayer(p);
        if (p && p->end == i) {
            my_putstr("\033[0m");
            p = p->next;
        }
        if (e == 32) {
            my_putchar('\n');
            e = 0;
        }
        print_hexa(arena[i]);
        if (e != 31)
            my_putchar(' ');
        e++;
    }
    my_putchar('\n');
}
