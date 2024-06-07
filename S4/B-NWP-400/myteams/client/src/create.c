/*
** EPITECH PROJECT, 2024
** B-NWP-400-MAR-4-1-myteams-angelo.anselmet
** File description:
** create
*/

#include "client.h"

void create_team(client_t *client, char *cmd)
{
    char *name = strtok(NULL, " \r\n");
    char *desc = strtok(NULL, " \r\n");
    char *string = malloc(sizeof(char) * (strlen(cmd) + strlen(team) + 2));

    if (name == NULL || strlen(name) > MAX_NAME_LENGTH ||
    desc == NULL || strlen(desc) > MAX_DESCRIPTION_LENGTH)
        return;
    remove_quotes(name);
    remove_quotes(desc);
    sprintf(string, "%s:%s:%s\r\n", cmd, name, desc);
    write(client->server_socket, string, strlen(string));
    if (check_error(string, &client) == 1)
        return;
}

void create_channel(client_t *client, char *cmd)
{
    char *channel = strtok(NULL, " \r\n");
    char *string = malloc(sizeof(char) * (strlen(cmd) + strlen(channel) + 2));

    if (channel == NULL)
        return;
    remove_quotes(channel);
    sprintf(string, "%s:%s\r\n", cmd, channel);
    write(client->server_socket, string, strlen(string));
    if (check_error(string, &client) == 1)
        return;
}

void create_thread(client_t *client, char *cmd)
{
    char *thread = strtok(NULL, " \r\n");
    char *string = malloc(sizeof(char) * (strlen(cmd) + strlen(thread) + 2));

    if (thread == NULL)
        return;
    remove_quotes(thread);
    sprintf(string, "%s:%s\r\n", cmd, thread);
    write(client->server_socket, string, strlen(string));
    if (check_error(string, &client) == 1)
        return;
}

void create(client_t *client, char *cmd)
{
    if (client->use == NO_USE)
        create_team(client, cmd);
    if (client->use == TEAM)
        create_channel(client, cmd);
    if (client->use == CHANNEL)
        create_channel(client, cmd);
    if (client->use == THREAD)
        create_thread(client, cmd);
}
