/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** orientation
*/

#include "../include/server.h"

int convert_orientation(direction_t orientation, int output)
{
    switch (orientation) {
        case UP:
            return output;
        case RIGHT:
            return output + 2;
        case DOWN:
            return output + 4;
        case LEFT:
            return output + 6;
        default:
            return 0;
    }
}

int direction_cs_next(int dx, int dy)
{
    if (dx == 0) {
        if (dy > 0)
            return 1;
        if (dy < 0)
            return 5;
    }
    return 0;
}

int direction_cs(int dx, int dy)
{
    if (dx > 0) {
        if (dy > 0)
            return 2;
        if (dy < 0)
            return 4;
        if (dy == 0)
            return 3;
    }
    if (dx < 0) {
        if (dy > 0)
            return 8;
        if (dy < 0)
            return 6;
        if (dy == 0)
            return 7;
    }
    return direction_cs_next(dx, dy);
}

int direction(
    pos_t *destination, pos_t *source, args_t *size, direction_t orientation
)
{
    int dx = destination->x - source->x;
    int dy = destination->y - source->y;
    int output = 0;

    if ((destination->x == source->x) && (destination->y == source->y))
        return 0;
    if (abs(dx) > (size->width / 2)) {
        dx = dx < 0 ? (size->width - abs(dx)) : (abs(dx) - size->width);
    }
    if (abs(dy) > (size->height / 2)) {
        dy = dy < 0 ? (size->height - abs(dy)) : (abs(dy) - size->height);
    }
    output = direction_cs(dx, dy);
    output = convert_orientation(orientation, output);
    if (output > 8) {
        output -= 8;
    }
    if (output == 0)
        output = 8;
    return output;
}
