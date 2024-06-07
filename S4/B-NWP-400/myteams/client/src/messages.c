/*
** EPITECH PROJECT, 2024
** B-NWP-400-MAR-4-1-myteams-angelo.anselmet
** File description:
** messages
*/

#include "client.h"

char *write_to_server(char *cmd, char *uid, client_t *client)
{
    char *string = malloc(sizeof(char) * (strlen(cmd) + strlen(uid) + 2));

    sprintf(string, "%s:%s\r\n", cmd, uid);
    write(client->server_socket, string, strlen(string));
    free(string);
}

void process_messages(client_t *client)
{
    char *messages = NULL;
    char *uid;
    struct tm tm;
    time_t t;
    size_t size = 0;

    while (getline(&messages, &size, client->stream) != -1) {
        uid = strtok(messages, ":");
        strptime(strtok(NULL, ":"), "%Y-%m-%d %H:%M:%S", &tm);
        t = mktime(&tm);
        messages = strtok(NULL, ":");
        client_private_message_print_messages(uid, t, messages);
    }
}

void messages(char *cmd, client_t *client)
{
    char *uid = strtok(NULL, " \r\n");
    char *str;
    size_t size = 0;

    if (uid == NULL)
        return;
    remove_quotes(uid);
    str = write_to_server(cmd, uid, client);
    getline(&str, &size, client->stream);
    if (check_error(str, client) == 1)
        return;
    process_messages(client);
}
