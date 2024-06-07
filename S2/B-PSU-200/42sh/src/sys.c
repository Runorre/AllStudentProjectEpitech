/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-42sh-theo.berget
** File description:
** sys
*/

#include "sh.h"

systeme *init_sys(char **env)
{
    systeme *sys = malloc(sizeof(systeme));
    sys->env = env;
    sys->his = NULL;
    sys->buffer = NULL;
    sys->alias = NULL;
    sys->size = 0;
    sys->end = 0;
    sys->id = 1;
    return sys;
}
