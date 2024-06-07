/*
** EPITECH PROJECT, 2022
** star
** File description:
** create a star
*/

#include <unistd.h>

void large_space (int size)
{
    for (int i = 0; i != size; i++)
        my_putchar(' ');
}

int up_star (int size)
{
    int range = ((size * 6) / 2) - 1, a = 1;
    large_space(range);
    my_putchar('*');
    my_putchar('\n');
    for (int i = 0; i != (size - 1); i++) {
        large_space(range - a);
        my_putchar('*');
        large_space((a * 2) - 1);
        my_putchar('*');
        my_putchar('\n');
        a++;
    }
    for (int e = 0; e != ((size * 4) + 3); e++) {
        if (e == ((size *2) +1))
            large_space((a * 2) - 3);
        else
            my_putchar('*');
    }
    return a;
}

void middle_star (int size)
{
    int range = ((size * 6) - 1), a = 1;
    for (int i = 0; i != ((size * 2) -1); i++) {
        if (i >= size) {
            a--;
            range += 2;
        }
        if (i == size) {
            a--;
            range += 2;
        }
        large_space(a);
        my_putchar('*');
        large_space(range - 4);
        my_putchar('*');
        my_putchar('\n');
        if (i < size) {
            a++;
            range -= 2;
        }
    }
}

void down_star(int size, int a)
{
    int range = ((size * 6) / 2) - 1;
    for (int e = 0; e != ((size * 2) + 1); e++)
        my_putchar('*');
    large_space((a * 2) - 3);
    for (int e = 0; e != ((size * 2) + 1); e++)
        my_putchar('*');
    for (int i = 0; i != (size - 1); i++) {
        my_putchar('\n');
        large_space(range - (a - 1));
        my_putchar('*');
        large_space((a * 2) - 3);
        my_putchar('*');
        a--;
    }
    my_putchar('\n');
    large_space(range);
    my_putchar('*');
}

void star (unsigned int size)
{
    if (size == 0) {
        return;
    }
    if (size == 1) {
        int range = ((size * 6) / 2);
        large_space(range);
        my_putchar('*');
        my_putchar('\n');
        write(1, "*** ***\n *   *\n*** ***\n   *\n", 31);
    } else {
        int a = up_star(size);
        my_putchar('\n');
        middle_star(size);
        down_star(size, a);
        my_putchar('\n');
    }
}
