/*
** EPITECH PROJECT, 2024
** B-NWP-400-MAR-4-1-myteams-angelo.anselmet
** File description:
** sends
*/

#include "client.h"

char *get_token(void)
{
    char *token = strtok(NULL, " \r\n");

    if (token != NULL) {
        remove_quotes(token);
    }
    return token;
}

char *format_message(char *cmd, char *uid, char *time_str, char *message)
{
    char *string = malloc(sizeof(char) *
    (strlen(cmd) + strlen(time_str) + strlen(uid) + strlen(message) + 2));

    sprintf(string, "%s:%s:%s:%s\r\n",
    cmd, uid, time_str, message);
    return string;
}

void sends(client_t *client, char *cmd)
{
    time_t t = time(NULL);
    char *time_str = ctime(&t);
    char *uid = get_token();
    char *message;
    char *string;

    if (uid == NULL)
        return;
    message = get_token();
    if (message == NULL)
        return;
    if (strlen(message) > MAX_BODY_LENGTH)
        return;
    string = format_message(cmd, uid, time_str, message);
    write(client->server_socket, string, strlen(string));
    client_event_private_message_received(client->uid, message);
}
