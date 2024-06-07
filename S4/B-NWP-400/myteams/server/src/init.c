/*
** EPITECH PROJECT, 2024
** MyTeams
** File description:
** init
*/

#include "../include/server.h"

user_t *create_user(char *user, char *uuid_str)
{
    uuid_t *uuid = malloc(sizeof(uuid_t));
    user_t *new_user = malloc(sizeof(user_t));

    uuid_parse(uuid_str, *uuid);
    new_user->name = user;
    new_user->id = uuid;
    new_user->connected = false;
    return new_user;
}

void init_user(sm_t *main_socket, char *user, char *uuid_str)
{
    list_user_t *last = main_socket->list_user;

    if (last == NULL) {
        last = malloc(sizeof(list_user_t));
        last->u = create_user(user, uuid_str);
        last->next = NULL;
        main_socket->list_user = last;
    } else {
        while (last->next != NULL)
            last = last->next;
        last->next = malloc(sizeof(list_user_t));
        last->next->u = create_user(user, uuid_str);
        last->next->next = NULL;
    }
    server_event_user_loaded(uuid_str, user);
}

int init_users(sm_t *main_socket)
{
    FILE *file = fopen("./server/data/user.txt", "r");
    char *line = NULL;
    char **parsing = NULL;
    size_t size = 0;

    main_socket->list_user = NULL;
    if (file == NULL)
        return 84;
    while (getline(&line, &size, file) != -1) {
        line[strcspn(line, "\n")] = '\0';
        parsing = my_str_to_word_array(line);
        init_user(main_socket, parsing[0], parsing[1]);
    }
    free(line);
    fclose(file);
    return loop_select(main_socket);
}
