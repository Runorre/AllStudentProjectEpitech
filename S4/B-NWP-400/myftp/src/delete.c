/*
** EPITECH PROJECT, 2024
** MyFTP
** File description:
** delete
*/

#include "myftp.h"

void delete_action(char *path, int fd)
{
    struct stat path_stat;

    stat(path, &path_stat);
    if (S_ISDIR(path_stat.st_mode)) {
        write(fd, "550 Requested action not taken.\r\n", 33);
    } else {
        if (remove(path) == 0)
            write(fd, "250 Requested file action okay, completed.\r\n", 44);
        else
            write(fd, "550 Requested action not taken.\r\n", 33);
    }
}

void dele_cs(char **parse, sm_t *ms, int i, int fd)
{
    char *path = malloc(sizeof(char) * 50);

    strcat_r(&path, ms->client_socket[i]->current_path);
    if (strlen(ms->client_socket[i]->current_path) != 1)
        strcat_r(&path, "/");
    strcat_r(&path, parse[1]);
    if (access(path, R_OK) == 0) {
        delete_action(path, fd);
    } else
        write(fd, "550 Requested action not taken.\r\n", 33);
    free(path);
}

void dele_com(sm_t *ms, int i, char *com)
{
    char **parse = my_str_to_word_array(com);
    int fd = ms->client_socket[i]->socketfd;

    if (parse[1] == NULL) {
        write(fd, "501 Syntax error in parameters or arguments.\r\n", 46);
        return;
    }
    if (parse[1][0] == '/') {
        if (access(parse[1], R_OK) == 0)
            delete_action(parse[1], fd);
        else
            write(fd, "550 Requested action not taken.\r\n", 33);
    } else {
        dele_cs(parse, ms, i, fd);
    }
}
