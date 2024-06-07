/*
** EPITECH PROJECT, 2024
** MyTeams
** File description:
** server
*/



#ifndef SERVER_H_
    #define SERVER_H_
    #include "../../libs/myteams/logging_server.h"
    #include <stdio.h>
    #include <string.h>
    #include <uuid/uuid.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <unistd.h>
    #include <arpa/inet.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <sys/time.h>
    #include <ctype.h>
    #include <stdbool.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include "user.h"
    #include "socket_master.h"


void my_putsocket(char *str, int fd_s);
char **my_str_to_word_array(char *str);
int select_for_first(sm_t *main_socket, int ac_max_sd);
void new_connection(sm_t *main_socket);
void action_client(sm_t *ms, int i);
void action_clients(sm_t *main_socket);
int loop_select(sm_t *main_socket);
int init_users(sm_t *main_socket);
void appendtofile(const char *filename, const char *line);
void new_user(sm_t *sm, int i, char **parms);
void login_com(sm_t *sm, int i, char **parms);
int is_all_digits(char *str);
void reset_user(sm_t *ms, int i);
void users_com(sm_t *sm, int i, char **argv);
void user_com(sm_t *sm, int i, char **argv);


    #define TRUE   1
    #define FALSE  0
    #define MAXCLIENT 20
#endif /* !SERVER_H_ */
