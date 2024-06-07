/*
** EPITECH PROJECT, 2024
** Rush2
** File description:
** new
*/

#include "raise.h"
#include "new.h"
#include "object.h"
#include "player.h"

Object *new(const Class *class, ...)
{
    va_list ap;
    va_start(ap, class);
    Object *newClass;

    if (!class) 
        return NULL;
    newClass = va_new(class, &ap);
    va_end(ap);
    return newClass;
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *newClass = malloc(class->__size__);
    
    newClass = memcpy(newClass, class, class->__size__);
    if (class->__ctor__ != NULL)
        class->__ctor__(newClass, ap);
    return newClass;
}

void delete(Object *ptr)
{
    Class *data = ptr;

    if (!ptr)
        return;
    if (data->__dtor__ != NULL)
        data->__dtor__(data);
    free(data);
}
