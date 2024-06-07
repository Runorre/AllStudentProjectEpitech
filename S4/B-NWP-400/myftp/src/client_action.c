/*
** EPITECH PROJECT, 2024
** MyFTP
** File description:
** client_action
*/

#include "myftp.h"

void quit_com(sm_t *ms, int i, char *com)
{
    int fd = ms->client_socket[i]->socketfd;

    printf("User disconet %i\n", ms->client_socket[i]->socketfd);
    write(fd, "221 Goodbye !\r\n", 15);
    close(ms->client_socket[i]->socketfd);
    ms->client_socket[i] = NULL;
}

void noop_com(sm_t *ms, int i, char *com)
{
    int fd = ms->client_socket[i]->socketfd;

    write(fd, "200 Yes\r\n", 9);
}

void which_command(sm_t *ms, int i, char *com)
{
    void (*commands[])(sm_t *, int, char *) = {&user_com, &pass_com,
    &quit_com, &noop_com, &help_com, &pwd_com, &cwd_com, &cdup_com, &dele_com};
    char *all_com[] = {"USER ", "PASS ", "QUIT", "NOOP", "HELP", "PWD",
    "CWD ", "CDUP", "DELE ", NULL};
    int fd = ms->client_socket[i]->socketfd;
    int j = 0;

    for (j = 0; all_com[j] != NULL; j++) {
        if (j > 4 && ms->client_socket[i]->authy == 2 &&
        strncmp(all_com[j], com, strlen(all_com[j])) == 0)
            return commands[j](ms, i, com);
        if (j > 4 && ms->client_socket[i]->authy != 2) {
            write(fd, "530 not logging\r\n", 17);
            return;
        }
        if (j <= 4 && strncmp(all_com[j], com, strlen(all_com[j])) == 0)
            return commands[j](ms, i, com);
    }
    write(fd, "500 Command not found.\r\n", 24);
}

void action_client(sm_t *ms, int i)
{
    char *line = NULL;
    size_t n = 0;
    FILE *stream = fdopen(ms->client_socket[i]->socketfd, "r+");

    if (getline(&line, &n, stream) >= 0) {
        line[strcspn(line, "\r\n")] = 0;
        which_command(ms, i, line);
    } else {
        fclose(stream);
        close(ms->client_socket[i]->socketfd);
        ms->client_socket[i] = NULL;
    }
}
