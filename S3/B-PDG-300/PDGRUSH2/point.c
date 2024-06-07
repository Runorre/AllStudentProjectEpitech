/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    //args a rajouter

    // Initialize internal resources
    this->x = va_arg((*args), int);
    this->y = va_arg((*args), int);
}

static void Point_dtor()
{
    return;
}

int my_nbrlen(int n)
{
    int len = 0;

    if (n == 0)
        return 1;
    if (n < 0) {
        n *= -1;
        len++;
    }
    while (n > 0) {
        n /= 10;
        len++;
    }
    return len;
}

static char *Point_to_string(PointClass *this)
{
    int len = strlen(this->base.__name__) + my_nbrlen(this->x) + my_nbrlen(this->y);
    char *str = malloc(sizeof(char) * (len + 8));
    snprintf(str, (len + 8), "<%s (%d, %d)>", this->base.__name__, this->x, this->y);
    return str;
}

static PointClass *Point_add(const PointClass *this, const PointClass *other)
{
    return (new(Point, (this->x + other->x), (this->y + other->y)));
}

static PointClass *Point_sub(const PointClass *this, const PointClass *other)
{
    return (new(Point, (this->x - other->x), (this->y - other->y)));
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_to_string,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
