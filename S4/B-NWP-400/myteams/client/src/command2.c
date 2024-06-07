/*
** EPITECH PROJECT, 2024
** B-NWP-400-MAR-4-1-myteams-angelo.anselmet
** File description:
** command2
*/

#include "client.h"

void login(char *cmd, client_t *client)
{
    char *uid = NULL;
    char *name = strtok(NULL, " \r\n");
    char *string = NULL;
    size_t size = 0;

    if (name == NULL)
        return;
    remove_quotes(name);
    string = malloc(sizeof(char) * (strlen(cmd) + strlen(name) + 4));
    sprintf(string, "%s:%s\r\n", cmd, name);
    write(client->server_socket, string, strlen(string));
    getline(&uid, &size, client->stream);
    uid[strcspn(uid, "\r\n")] = 0;
    if (check_error(uid, client) == 1) {
        return;
    } else {
        client->uid = strdup(uid);
        client->name = strdup(name);
        client_event_logged_in(uid, name);
    }
}

void logout(client_t *client, char *cmd)
{
    char *string;
    size_t size = 0;

    string = malloc(sizeof(char) * (strlen(cmd)));
    sprintf(string, "%s\r\n", cmd);
    write(client->server_socket, cmd, strlen(cmd));
    if (check_error(cmd, client) == 1)
        return;
    client_event_logged_out(client->uid, client->name);
    close(client->server_socket);
    exit(0);
}

void users(client_t *client, char *cmd)
{
    char *string = NULL;
    char *str = NULL;
    char *uid = NULL;
    char *name = NULL;
    char *status = NULL;
    size_t size = 0;

    string = malloc(sizeof(char) * (strlen(cmd) + 2));
    sprintf(string, "%s\r\n", cmd);
    write(client->server_socket, string, strlen(string));
    while (getline(&str, &size, client->stream) != 1) {
        str[strcspn(str, "\r\n")] = 0;
        if (strcmp(str, "204") == 0 || check_error(str, client) == 1)
            return;
        uid = strtok(str, ":");
        name = strtok(NULL, ":");
        status = strtok(NULL, ":");
        client_print_users(uid, name, atoi(status));
    }
}

void user(char *cmd, client_t *client)
{
    char *uid = strtok(NULL, " \r\n");
    char *name = NULL;
    char *string = malloc(sizeof(char) * (strlen(cmd) + strlen(uid) + 2));
    char *status = NULL;
    char *str = NULL;
    size_t size = 0;

    if (uid == NULL)
        return;
    remove_quotes(uid);
    sprintf(string, "%s:%s\r\n", cmd, uid);
    write(client->server_socket, string, strlen(string));
    getline(&str, &size, client->stream);
    str[strcspn(str, "\r\n")] = 0;
    if (check_error(str, client) == 2)
        return (void) client_error_unknown_user(uid);
    uid = strtok(str, ":");
    name = strtok(NULL, ":");
    status = strtok(NULL, ":");
    client_print_user(uid, name, atoi(status));
}
