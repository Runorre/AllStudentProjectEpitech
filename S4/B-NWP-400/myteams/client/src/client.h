/*
** EPITECH PROJECT, 2024
** B-NWP-400-MAR-4-1-myteams-angelo.anselmet
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512
    #define _XOPEN_SOURCE
    #define _GNU_SOURCE
    #include <time.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <dirent.h>
    #include <errno.h>
    #include <stdbool.h>
    #include "../../libs/myteams/logging_client.h"


enum use_enum {
    NO_USE,
    TEAM,
    CHANNEL,
    THREAD,
    REPLY
};

typedef struct {
    int server_socket;
    char *ip;
    int port;
    char *uid;
    char *name;
    FILE *stream;
    enum use_enum use;
    int status;
}client_t;

void read_command(client_t *client);
void sends(client_t *client, char *cmd);
void messages(char *cmd, client_t *client);
void user(char *cmd, client_t *client);
void print_h(void);
void login(char *cmd, client_t *client);
void logout(client_t *client, char *cmd);
void subscribe(client_t *client, char *cmd);
void subscribed(client_t *client, char *cmd);
void unsubscribe(client_t *client, char *cmd);
void use(client_t *client, char *cmd);
void create(client_t *client, char *cmd);
void list(client_t *client, char *cmd);
int check_error(char *str, client_t *client);
void check_command(char *message, client_t *client);
void remove_quotes(char *str);
void users(client_t *client, char *cmd);
void set_command(fd_set readfds, client_t *client, char *message);


#endif /* !CLIENT_H_ */
