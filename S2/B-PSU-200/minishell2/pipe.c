/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell2-angelo.anselmet
** File description:
** pipe
*/

#include "my.h"

int *fonct_pipe(int fd_in, char **env, char **pipe_s, int i)
{
    int p[2], status = 0, end = 0;
    pipe(p);
    pid_t pid = fork();
    if (pid == 0) {
        dup2(fd_in, 0);
        if (pipe_s[i + 1] != NULL)
            dup2(p[1], 1);
        end = terminal_main(my_str_to_word_array(pipe_s[i]), env);
        close(p[0]);
        exit(end);
    } else {
        close(p[1]);
        int *tmp = malloc(sizeof(int) * 2);
        waitpid(pid, &status, WUNTRACED | WCONTINUED);
        tmp[0] = p[0];
        tmp[1] = WEXITSTATUS(status);
        return tmp;
    }
}

int next_pipe(int fd_in, char **env, char **pipe_s)
{
    int i = 1;
    int *tmp = NULL;
    int end = 0;
    while (pipe_s[i] != NULL) {
        tmp = fonct_pipe(fd_in, env, pipe_s, i);
        fd_in = tmp[0];
        end = tmp[1];
        i++;
    }
    free(tmp);
    return end;
}

int init_pipe(char **pipe_s, char **env)
{
    int pipefd[2], status = 0, end = 0;
    pipe(pipefd);
    pid_t pid = fork();
    if (pid == 0) {
        close(pipefd[0]);
        char **parsing = my_str_to_word_array(pipe_s[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        end = terminal_main(parsing, env);
        order66(parsing);
        close(pipefd[1]);
        exit(end);
    } else {
        close(pipefd[1]);
        end = next_pipe(pipefd[0], env, pipe_s);
        close(pipefd[0]);
        waitpid(pid, &status, WUNTRACED | WCONTINUED);
        return end;
    }
}

int checkpipe(char *command, char **env)
{
    int end = 0;
    char **multipipe = my_str_to_word_array2(command, '|');
    if (my_strstrlen(multipipe) == 1) {
        order66(multipipe);
        char **parsing = my_str_to_word_array(command);
        end = terminal_main(parsing, env);
        order66(parsing);
        return end;
    } else {
        end = init_pipe(multipipe, env);
    }
    return end;
}
