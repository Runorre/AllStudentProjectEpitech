/*
** EPITECH PROJECT, 2024
** MyFTP
** File description:
** commands
*/

#include "myftp.h"

void help_com(sm_t *ms, int i, char *com)
{
    int fd = ms->client_socket[i]->socketfd;

    write(fd, "214 its dangerous, take this!\r\n", 31);
}

void pwd_com(sm_t *ms, int i, char *com)
{
    int fd = ms->client_socket[i]->socketfd;
    char *path = ms->client_socket[i]->current_path;

    write(fd, "257 ", 4);
    write(fd, path, strlen(path));
    write(fd, "\r\n", 2);
}
