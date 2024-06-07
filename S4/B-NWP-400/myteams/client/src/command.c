/*
** EPITECH PROJECT, 2024
** B-NWP-400-MAR-4-1-myteams-angelo.anselmet
** File description:
** command
*/

#include "client.h"

void read_command(client_t *client)
{
    char *message = NULL;
    fd_set readfds;
    fd_set all_fd;
    size_t len = 0;

    FD_SET(client->server_socket, &all_fd);
    FD_SET(STDIN_FILENO, &all_fd);
    client->stream = fdopen(client->server_socket, "r");
    while (1) {
        readfds = all_fd;
        if (select(client->server_socket + 1, &readfds,
        NULL, NULL, NULL) == -1) {
            close(client->server_socket);
            exit(0);
        }
        set_command(readfds, client, message);
    }
}

void get_string(char *string, char **str, client_t *client)
{
    for (int i = 0; str[i] != NULL; i++)
        remove_quotes(str[i]);
    if (str[0] != NULL && str[1] != NULL && str[2] != NULL) {
        client->use = CHANNEL;
        sprintf(string, "%s:%s:%s:%s\r\n",
        str[3], str[0], str[1], str[2]);
    }
    if (str[0] != NULL && str[1] != NULL && str[2] == NULL) {
        client->use = THREAD;
        sprintf(string, "%s:%s:%s\r\n",
        str[3], str[0], str[1]);
    }
    if (str[0] != NULL && str[1] == NULL && str[2] == NULL) {
        client->use = REPLY;
        sprintf(string, "%s:%s\r\n", str[3], str[0]);
    } else if (str[0] == NULL && str[1] == NULL && str[2] == NULL) {
        client->use = TEAM;
        sprintf(string, "%s\r\n", str[3]);
    }
}

void use(client_t *client, char *cmd)
{
    char *team = strtok(NULL, " \r\n");
    char *channel = strtok(NULL, " \r\n");
    char *thread = strtok(NULL, " \r\n");
    int i;
    char *string = malloc(sizeof(char) * (strlen(cmd) + strlen(team) + 2));
    char **args;

    client->use = i - 1;
    args = malloc(sizeof(char *) * 4);
    args[0] = team;
    args[1] = channel;
    args[2] = thread;
    args[3] = cmd;
    get_string(string, args, client);
    write(client->server_socket, string, strlen(string));
    if (check_error(string, client) == 1)
        return;
}

void set_command(fd_set readfds, client_t *client, char *message)
{
    size_t len = 0;

    if (FD_ISSET(STDIN_FILENO, &readfds)) {
        getline(&message, &len, stdin);
        check_command(message, client);
    }
    if (FD_ISSET(client->server_socket, &readfds)) {
        if (getline(&message, &len, client->stream) == -1) {
            exit(0);
        }
        if (strncmp(message, "200", 3) != 0)
        exit(0);
    }
}
