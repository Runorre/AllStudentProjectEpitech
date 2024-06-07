/*
** EPITECH PROJECT, 2023
** generator
** File description:
** next
*/

#include "my.h"

int nextbacktrack(char **laby, position *pos, int x, int y)
{
    if (x != 0)
        if (breakable(laby, x - 1, y)) {
            pos->x = x - 1;
            return pos->y = y;
        }
    if (laby[x + 1] != NULL)
        if (breakable(laby, x + 1, y)) {
            pos->x = x + 1;
            return pos->y = y;
        }
    if (y != 0)
        if (breakable(laby, x, y - 1)) {
            pos->y = y - 1;
            return pos->x = x;
        }
    if (laby[x][y + 1] != '\0')
        if (breakable(laby, x, y + 1)) {
            pos->y = y + 1;
            return pos->x = x;
        }
}

int saferand(char **laby, int x, int y)
{
    int random_next = rand() % 4;
    int tmp = -1;
    while (random_next != tmp) {
        tmp = random_next;
        if (random_next == 0 && x == 0)
            random_next++;
        if (random_next == 1 && laby[x][y + 1] == '\0')
            random_next++;
        if (random_next == 2 && laby[x + 1] == NULL)
            random_next++;
        if (random_next == 3 && y == 0)
            random_next = 0;
    }
    return random_next;
}

void nextmove(char **laby, list *file, position *pos)
{
    int random_next = saferand(laby, pos->x, pos->y);
    switch (random_next) {
    case 0:
        pos->x--;
        return;
    case 1:
        pos->y++;
        return;
    case 2:
        pos->x++;
        return;
    case 3:
        pos->y--;
        return;
    }
}
