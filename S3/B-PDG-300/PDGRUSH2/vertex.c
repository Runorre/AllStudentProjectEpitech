/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** vertex
*/

#include "raise.h"
#include "new.h"
#include "object.h"
#include "point.h"
#include "vertex.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg((*args), int);
    this->y = va_arg((*args), int);
    this->z = va_arg((*args), int);
}

static void Vertex_dtor()
{
    return;
}

int my_nbrlen1(int n)
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

static char *Vertex_to_string(VertexClass *this)
{
    int len = strlen(this->base.__name__) + my_nbrlen1(this->x) + 
    my_nbrlen1(this->y) + my_nbrlen1(this->z);
    char *str = malloc(sizeof(char) * (len + 10));
    snprintf(str, (len + 10), "<%s (%d, %d, %d)>", this->base.__name__, 
    this->x, this->y, this->z);
    return str;
}

static VertexClass *Vertex_add(const VertexClass *this, const VertexClass *other)
{
    return (new(Vertex, (this->x + other->x), (this->y + other->y), (this->z + other->z)));
}

static VertexClass *Vertex_sub(const VertexClass *this, const VertexClass *other)
{
    return (new(Vertex, (this->x - other->x), (this->y - other->y), (this->z - other->z)));
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_to_string,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;
