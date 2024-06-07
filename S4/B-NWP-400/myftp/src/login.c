/*
** EPITECH PROJECT, 2024
** MyFTP
** File description:
** login
*/

#include "myftp.h"

void user_com(sm_t *ms, int i, char *buf)
{
    char **parse = my_str_to_word_array(buf);
    int fd = ms->client_socket[i]->socketfd;

    if (parse[1] != NULL && (strcmp(parse[1], "Anonymous") == 0 ||
    strcmp(parse[1], "anonymous") == 0)) {
        ms->client_socket[i]->authy = 1;
    } else {
        ms->client_socket[i]->authy = 3;
    }
    write(fd, "331 User name okay, need password.\r\n", 36);
}

void pass_com(sm_t *ms, int i, char *buf)
{
    char **parse = my_str_to_word_array(buf);
    int fd = ms->client_socket[i]->socketfd;

    if (ms->client_socket[i]->authy == 1) {
        ms->client_socket[i]->authy = 2;
        write(fd, "230 User logged in, proceed.\r\n", 30);
    } else if (ms->client_socket[i]->authy == 2) {
        ms->client_socket[i]->authy = 0;
        write(fd, "530 Login incorrect.\r\n", 22);
    } else {
        ms->client_socket[i]->authy = 0;
        write(fd, "332 Need account for login.\r\n", 29);
    }
}
