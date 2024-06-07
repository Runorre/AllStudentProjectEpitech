/*
** EPITECH PROJECT, 2024
** MyFTP
** File description:
** path
*/

#include "myftp.h"

void cdup_com(sm_t *ms, int i, char *com)
{
    int fd = ms->client_socket[i]->socketfd;
    char *newpath = NULL;
    char *path = ms->client_socket[i]->current_path;
    int last = last_char(path, '/');

    if (count_char(path, '/') > 1) {
        newpath = my_strcut(path, last);
        ms->client_socket[i]->current_path = strdup(newpath);
    } else {
        ms->client_socket[i]->current_path = strdup("/");
    }
    write(fd, "200 Command okay.\r\n", 19);
}

void cwd_cs2(char **parse, sm_t *ms, int i, int fd)
{
    char *path = malloc(sizeof(char) * 50);

    strcat_r(&path, ms->client_socket[i]->current_path);
    if (strlen(ms->client_socket[i]->current_path) != 1)
        strcat_r(&path, "/");
    strcat_r(&path, parse[1]);
    if (access(path, R_OK) == 0) {
        if (strlen(ms->client_socket[i]->current_path) == 1)
            strcat_r(&ms->client_socket[i]->current_path, parse[1]);
        else {
            strcat_r(&ms->client_socket[i]->current_path, "/");
            strcat_r(&ms->client_socket[i]->current_path, parse[1]);
        }
        write(fd, "250 Requested file action okay, completed.\r\n", 44);
    } else
        write(fd, "550 Requested action not taken.\r\n", 33);
    free(path);
}

void cwd_cs(char **parse, sm_t *ms, int i, int fd)
{
    char *path = malloc(sizeof(char) * 50);

    if (parse[1][0] == '/') {
        if (access(parse[1], R_OK) == 0) {
            ms->client_socket[i]->current_path = strdup(parse[1]);
            write(fd, "250 Requested file action okay, completed.\r\n", 44);
        } else
            write(fd, "550 Requested action not taken.\r\n", 33);
    } else {
        cwd_cs2(parse, ms, i, fd);
    }
    free(path);
}

void cwd_com(sm_t *ms, int i, char *com)
{
    char **parse = my_str_to_word_array(com);
    int fd = ms->client_socket[i]->socketfd;

    if (parse[1] == NULL) {
        write(fd, "501 Syntax error in parameters or arguments.\r\n", 46);
        return;
    }
    cwd_cs(parse, ms, i, fd);
}
