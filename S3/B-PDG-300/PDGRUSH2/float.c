/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** float
*/

#include "raise.h"
#include "new.h"
#include "object.h"
#include "point.h"
#include "vertex.h"
#include "int.h"
#include "float.h"

typedef struct
{
    Class   base;
    double     x;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->x = va_arg((*args), double);
}

static char *Float_to_string(FloatClass *this)
{
    char *str = malloc(sizeof(char) * 255);
    snprintf(str, 255, "<%s (%f)>", this->base.__name__, this->x);
    return str;
}

static FloatClass *Float_add(const FloatClass *this, const FloatClass *other)
{
    return (new(Float, (this->x + other->x)));
}

static FloatClass *Float_sub(const FloatClass *this, const FloatClass *other)
{
    return (new(Float, (this->x - other->x)));
}

static FloatClass *Float_mul(const FloatClass *this, const FloatClass *other)
{
    return (new(Float, (this->x * other->x)));
}

static FloatClass *Float_div(const FloatClass *this, const FloatClass *other)
{
    return (new(Float, (this->x / other->x)));
}

static bool Float_eq(const FloatClass *this, const FloatClass *other)
{
    if (this->x == other->x)
        return true;
    else
        return false;
}

static bool Float_gt(const FloatClass *this, const FloatClass *other)
{
    if (this->x > other->x)
        return true;
    else
        return false;
}

static bool Float_lt(const FloatClass *this, const FloatClass *other)
{
    if (this->x < other->x)
        return true;
    else
        return false;
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = NULL,
        .__str__ = (to_string_t)&Float_to_string,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .x = 0.0
};

const Class   *Float = (const Class *)&_description;
