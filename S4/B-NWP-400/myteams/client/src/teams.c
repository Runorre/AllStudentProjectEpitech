/*
** EPITECH PROJECT, 2024
** B-NWP-400-MAR-4-1-myteams-angelo.anselmet
** File description:
** teams
*/

#include "client.h"

void subscribe(client_t *client, char *cmd)
{
    char *team = strtok(NULL, " \r\n");
    char *str;
    char *string;

    string = malloc(sizeof(char) * (strlen(cmd) + strlen(team) + 2));
    sprintf(string, "%s:%s\r\n", cmd, team);
    write(client->server_socket, string, strlen(str));
    if (check_error(str, client) == 1)
        return;
    client_print_subscribed(team, team);
}

void subscribed2(client_t *client, char *cmd, char *str)
{
    char *uid;
    char *name;
    int desc;
    char *string;
    size_t size = 0;

    if (str != NULL) {
        remove_quotes(str);
        string = malloc(sizeof(char) * (strlen(cmd) + strlen(str) + 2));
        sprintf(string, "%s:%s\r\n", cmd, str);
        write(client->server_socket, string, strlen(string));
        while (getline(&str, &size, client->stream) != -1) {
            uid = strtok(str, ":\r\n");
            name = strtok(NULL, ":\r\n");
            desc = atoi(strtok(NULL, ":\r\n"));
            client_print_users(uid, name, desc);
        }
    }
}

void subscribed(client_t *client, char *cmd)
{
    char *str;
    char *uid;
    char *name;
    char *desc;
    size_t size = 0;

    str = strtok(NULL, " \r\n");
    if (str == NULL) {
        str = strcat(cmd, "\r\n");
        write(client->server_socket, str, strlen(str));
        if (check_error(str, client) == 1)
            return;
        while (getline(&str, &size, client->stream) != -1) {
            uid = strtok(str, ":\r\n");
            name = strtok(NULL, ":\r\n");
            desc = strtok(NULL, ":\r\n");
            client_print_teams(uid, name, desc);
        }
    }
    subscribed2(client, cmd, str);
}

void unsubscribe(client_t *client, char *cmd)
{
    char *team = strtok(NULL, " \r\n");
    char *string = malloc(sizeof(char) * (strlen(cmd) + strlen(team) + 2));

    if (team == NULL)
        return;
    remove_quotes(team);
    sprintf(string, "%s:%s\r\n", cmd, team);
    write(client->server_socket, string, strlen(string));
    if (check_error(string, client) == 1)
        return;
    client_print_unsubscribed(team, team);
}
