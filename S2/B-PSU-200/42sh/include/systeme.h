/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-42sh-theo.berget
** File description:
** systeme
*/

#ifndef SYSTEME_H_
    #define SYSTEME_H_
    #include "sh.h"
    #include "list.h"
    typedef struct systeme_d{
        char *buffer;
        char **env;
        size_t size;
        history *his;
        Element *alias;
        int end;
        int id;
    }systeme;
#endif /* !SYSTEME_H_ */
