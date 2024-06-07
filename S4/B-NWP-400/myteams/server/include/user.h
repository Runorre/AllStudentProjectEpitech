/*
** EPITECH PROJECT, 2024
** MyTeams
** File description:
** user
*/

#include "server.h"

#ifndef USER_H_
    #define USER_H_
typedef struct user_s {
    uuid_t *id;
    char *name;
    bool connected;
} user_t;

typedef struct list_user_s {
    user_t *u;
    struct list_user_s *next;
} list_user_t;
#endif /* !USER_H_ */
