/*
** EPITECH PROJECT, 2024
** B-NWP-400-MAR-4-1-myteams-angelo.anselmet
** File description:
** check_command
*/

#include "client.h"

void check_command(char *message, client_t *client)
{
    char *cmd = strtok(message, " \r\n");

    if (cmd == NULL)
        return;
    if (strcmp(cmd, "/help") == 0)
        print_h();
    if (strcmp(cmd, "/login") == 0)
        login(cmd, client);
    if (strcmp(message, "/logout") == 0)
        logout(client, cmd);
    if (strcmp(message, "/users") == 0)
        users(client, cmd);
    if (strcmp(message, "/user") == 0)
        user(cmd, client);
    if (strcmp(message, "/send") == 0)
        return;
    if (strcmp(message, "/messages") == 0)
        return;
}
