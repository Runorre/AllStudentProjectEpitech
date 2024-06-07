/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** char
*/

#include "raise.h"
#include "new.h"
#include "object.h"
#include "point.h"
#include "vertex.h"
#include "char.h"

typedef struct
{
    Class base;
    char x;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->x = va_arg((*args), int);
}

static CharClass *Char_add(const CharClass *this, const CharClass *other)
{
    return (new(Char, (this->x + other->x)));
}

static CharClass *Char_sub(const CharClass *this, const CharClass *other)
{
    return (new(Char, (this->x - other->x)));
}

static CharClass *Char_mul(const CharClass *this, const CharClass *other)
{
    return (new(Char, (this->x * other->x)));
}

static CharClass *Char_div(const CharClass *this, const CharClass *other)
{
    return (new(Char, (this->x / other->x)));
}

static bool Char_eq(const CharClass *this, const CharClass *other)
{
    if (this->x == other->x)
        return true;
    else
        return false;
}

static bool Char_gt(const CharClass *this, const CharClass *other)
{
    if (this->x > other->x)
        return true;
    else
        return false;
}

static bool Char_lt(const CharClass *this, const CharClass *other)
{
    if (this->x < other->x)
        return true;
    else
        return false;
}

static char *Char_to_string(CharClass *this)
{
    char *str = malloc(sizeof(char) * (strlen(this->base.__name__) + 8));
    int len = strlen(this->base.__name__) + 1;

    snprintf(str, (len + 7), "<%s (%c)>", this->base.__name__, this->x);
    return str;
}


static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = NULL,
        .__str__ = (to_string_t)&Char_to_string,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .x = 0
};

const Class   *Char = (const Class *)&_description;
