/*
** EPITECH PROJECT, 2024
** MyTeams
** File description:
** putstr_s
*/

#include "../include/server.h"

void my_putsocket(char *str, int fd_s)
{
    write(fd_s, str, strlen(str));
    write(fd_s, "\r\n", 2);
}
