/*
** EPITECH PROJECT, 2024
** MyFTP
** File description:
** socket_master_s
*/

#ifndef SOCKET_MASTER_S_H_
    #define SOCKET_MASTER_S_H_
    #include "myftp.h"

typedef struct client_socket_s {
    int socketfd;
    int authy;
    char *current_path;
    char *cp_ab;
    char *home_path;

} client_socket_t;

typedef struct socket_master_s {
    struct sockaddr_in addr;
    int addrlen;
    int socketmaster;
    int port;
    char *anonymous_path;
    client_socket_t **client_socket;
    fd_set readfds;
} sm_t;

#endif /* !SOCKET_MASTER_S_H_ */
