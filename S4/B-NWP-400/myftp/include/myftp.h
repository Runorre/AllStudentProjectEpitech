/*
** EPITECH PROJECT, 2024
** MyFTP
** File description:
** myftp
*/

#ifndef MYFTP_H_
    #define MYFTP_H_
    #include <stdio.h>
    #include <string.h>
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
    #include "socket_master_s.h"

int is_all_digits(char *str);
int select_for_first(sm_t *main_socket, int ac_max_sd);
void new_connection(sm_t *main_socket);
void action_client(sm_t *ms, int i);
void action_clients(sm_t *main_socket);
char **my_str_to_word_array(char *str);
void user_com(sm_t *ms, int i, char *buf);
void pass_com(sm_t *ms, int i, char *buf);
void help_com(sm_t *ms, int i, char *com);
void pwd_com(sm_t *ms, int i, char *com);
void cwd_com(sm_t *ms, int i, char *com);
char *strcat_r(char **dest, const char *src);
void cdup_com(sm_t *ms, int i, char *com);
int count_char(const char *str, char ch);
int last_char(const char *str, char ch);
char *my_strcut(const char *str, int pos);
void dele_com(sm_t *ms, int i, char *com);

    #define TRUE   1
    #define FALSE  0
    #define MAXCLIENT 20
#endif /* !MYFTP_H_ */
