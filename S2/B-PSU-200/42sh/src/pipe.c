/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell2-angelo.anselmet
** File description:
** pipe
*/

#include "sh.h"

int *fonct_pipe(int fd_in, char **pipe_s, int i, systeme **sys)
{
    int p[2], status = 0, end = 0;
    pipe(p);
    pid_t pid = fork();
    if (pid == 0) {
        dup2(fd_in, 0);
        if (pipe_s[i + 1] != NULL)
            dup2(p[1], 1);
        (*sys)->end = terminal_main(my_str_to_word_array(pipe_s[i]), sys);
        close(p[0]);
        exit((*sys)->end);
    } else {
        close(p[1]);
        int *tmp = malloc(sizeof(int) * 2);
        waitpid(pid, &status, WUNTRACED | WCONTINUED);
        tmp[0] = p[0];
        tmp[1] = WEXITSTATUS(status);
        return tmp;
    }
}

int next_pipe(int fd_in, char **pipe_s, systeme **sys)
{
    int i = 1;
    int *tmp = NULL;
    int end = 0;
    while (pipe_s[i] != NULL) {
        tmp = fonct_pipe(fd_in, pipe_s, i, sys);
        fd_in = tmp[0];
        (*sys)->end = tmp[1];
        i++;
    }
    free(tmp);
    return (*sys)->end;
}

int init_pipe(char **pipe_s, systeme **sys)
{
    int pipefd[2], status = 0, end = 0;
    pipe(pipefd);
    pid_t pid = fork();
    if (pid == 0) {
        close(pipefd[0]);
        char **parsing = my_str_to_word_array(pipe_s[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        end = terminal_main(parsing, sys);
        order66(parsing);
        close(pipefd[1]);
        exit(end);
    } else {
        close(pipefd[1]);
        end = next_pipe(pipefd[0], pipe_s, sys);
        close(pipefd[0]);
        waitpid(pid, &status, WUNTRACED | WCONTINUED);
        return end;
    }
}

int checkpipe(char *command, systeme **sys)
{
    char **multipipe = my_str_to_word_array2(command, '|');
    if (my_strstrlen(multipipe) == 1) {
        order66(multipipe);
        char **parsing = my_str_to_word_array(command);
        (*sys)->end = terminal_main(parsing, sys);
        return (*sys)->end;
    } else {
        (*sys)->end = init_pipe(multipipe, sys);
    }
    return (*sys)->end;
}
