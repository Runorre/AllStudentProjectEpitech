/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** Int
*/

#include "raise.h"
#include "new.h"
#include "object.h"
#include "point.h"
#include "vertex.h"
#include "int.h"

typedef struct
{
    Class   base;
    int     x;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->x = va_arg((*args), int);
}

int my_nbrlen2(int n)
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

static char *Int_to_string(IntClass *this)
{
    int len = my_nbrlen2(this->x) + strlen(this->base.__name__);
    char *str = malloc(sizeof(char) * (len + 7));
    snprintf(str, (len + 7), "<%s (%d)>", this->base.__name__, this->x);
    return str;
}

static IntClass *Int_add(const IntClass *this, const IntClass *other)
{
    return (new(Int, (this->x + other->x)));
}

static IntClass *Int_sub(const IntClass *this, const IntClass *other)
{
    return (new(Int, (this->x - other->x)));
}

static IntClass *Int_mul(const IntClass *this, const IntClass *other)
{
    return (new(Int, (this->x * other->x)));
}

static IntClass *Int_div(const IntClass *this, const IntClass *other)
{
    return (new(Int, (this->x / other->x)));
}

static bool Int_eq(const IntClass *this, const IntClass *other)
{
    if (this->x == other->x)
        return true;
    else
        return false;
}

static bool Int_gt(const IntClass *this, const IntClass *other)
{
    if (this->x > other->x)
        return true;
    else
        return false;
}

static bool Int_lt(const IntClass *this, const IntClass *other)
{
    if (this->x < other->x)
        return true;
    else
        return false;
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = NULL,
        .__str__ = (to_string_t)&Int_to_string,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .x = 0
};

const Class   *Int = (const Class *)&_description;
