/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-dante-angelo.anselmet
** File description:
** main
*/

#include "my.h"

int breakable(char **laby, int x, int y)
{
    if (y < 0 || x < 0 || laby[x] == NULL || laby[x][y] == '*')
        return 0;
    int checker = 0;
    if (x != 0 && laby[x - 1][y] == '*')
        checker++;
    if (laby[x + 1] && laby[x + 1][y] == '*')
        checker++;
    if (y != 0 && laby[x][y - 1] == '*')
        checker++;
    if (laby[x][y + 1] == '*')
        checker++;
    if (checker >= 2)
        return 0;
    else
        return 1;
}

list *backtracking(char **laby, list *file, position *pos)
{
    if (file == NULL)
        return NULL;
    int tx = pos->x;
    int ty = pos->y;
    while (file != NULL && tx == pos->x && ty == pos->y) {
        if (file == NULL)
            return NULL;
        if (file->prev != NULL)
            free(file->prev);
        nextbacktrack(laby, pos, file->x, file->y);
        file = file->next;
    }
    return file;
}

void recusive_avance(char **laby, list *file, int x, int y)
{
    position *pos = malloc(sizeof(position));
    pos->x = x;
    pos->y = y;
    while (file != NULL) {
        if (file == NULL)
            return;
        if (breakable(laby, pos->x, pos->y)) {
            laby[pos->x][pos->y] = '*';
            file = addnode(file, pos->x, pos->y);
            nextmove(laby, file, pos);
        } else {
            file = backtracking(laby, file, pos);
        }
    }
    free(pos);
}

int init_generate(int x, int y, int perfect)
{
    int random = rand() % 2;
    char **laby = createstruct(x, y);
    list *file = addnode(NULL, 0, 0);
    laby[0][0] = '*';
    if (random)
        recusive_avance(laby, file, 0, 1);
    else
        recusive_avance(laby, file, 1, 0);
    antimazeimp(laby, x, y);
    if (perfect == 0) {
        for (int i = 0; i != 5; i++)
            imparfait(laby, x, y);
    }
    my_putstrstr(laby);
    free(file);
    return 0;
}

int main(int ac, char **ar)
{
    srand(time(NULL));
    if (ac < 3 || ac > 4)
        return 84;
    if (atoi(ar[1]) < 4 || atoi(ar[2]) < 4)
        return 84;
    if (ac == 3)
        return init_generate(atoi(ar[2]), atoi(ar[1]), 0);
    if (ac == 4 && my_strcmp("perfect", ar[3]))
        return init_generate(atoi(ar[2]), atoi(ar[1]), 1);
    else
        return 84;
}
