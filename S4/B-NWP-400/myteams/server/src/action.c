/*
** EPITECH PROJECT, 2024
** MyTeams
** File description:
** action
*/

#include "../include/server.h"

void quit_com(sm_t *ms, int i, char **com)
{
    int fd = ms->client_socket[i]->socketfd;
    char uuid_str[37];

    reset_user(ms, i);
    close(ms->client_socket[i]->socketfd);
    ms->client_socket[i] = NULL;
}

void which_command(sm_t *ms, int i, char **com)
{
    void (*commands[])(sm_t *, int, char **) = {&login_com, &quit_com,
    &users_com, &user_com, NULL};
    char *all_com[] = {"/login", "/logout", "/users", "/user", NULL};
    int fd = ms->client_socket[i]->socketfd;
    int j = 0;

    for (j = 0; all_com[j] != NULL; j++) {
        if (j > 2 && ms->client_socket[i]->authy == TRUE &&
        strncmp(all_com[j], com[0], strlen(all_com[j])) == 0)
            return commands[j](ms, i, com);
        if (j > 2 && ms->client_socket[i]->authy == FALSE) {
            my_putsocket("401", fd);
            return;
        }
        if (j <= 2 && strncmp(all_com[j], com[0], strlen(all_com[j])) == 0)
            return commands[j](ms, i, com);
    }
    my_putsocket("401", fd);
}

void security(sm_t *ms, int i, char *line)
{
    if (strlen(line) > 1)
        which_command(ms, i, my_str_to_word_array(line));
}

void action_client(sm_t *ms, int i)
{
    char *line = NULL;
    size_t size = 0;
    FILE *stream = fdopen(ms->client_socket[i]->socketfd, "r+");

    if (getline(&line, &size, stream) >= 0) {
        line[strcspn(line, "\r\n")] = 0;
        security(ms, i, line);
    } else {
        fclose(stream);
        reset_user(ms, i);
        close(ms->client_socket[i]->socketfd);
        ms->client_socket[i] = NULL;
    }
}
