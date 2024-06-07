/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-angelo.anselmet
** File description:
** main
*/

#include "sh.h"

int checksigmessage(int status)
{
    if (WTERMSIG(status) == SIGFPE)
        my_putstrerr("Floating exception");
    else
        my_putstrerr(strsignal(WTERMSIG(status)));
    if (WCOREDUMP(status))
        my_putstrerr(" (core dumped)");
    my_putstrerr("\n");
    return status;
}

int execute_process(char **command, char **env, char *path)
{
    int status = 0, end = 0, fd = 0;
    pid_t pid = fork();
    if (pid == 0) {
        if ((fd = checkredirection(command)) != -1)
            end = execve(my_strcat(path, command[0]), command, env);
        else
            exit(1);
        close(fd);
        if (end == -1) {
            printerror(command[0]);
            exit(1);
        }
    } else {
        waitpid(pid, &status, WUNTRACED | WCONTINUED);
        if (WIFSIGNALED(status))
            return checksigmessage(status);
        if (WIFEXITED(status))
            return WEXITSTATUS(status);
        }
}

int command_existe(char **env, char **arg)
{
    int path = findinstrstr("PATH=", env);
    if (path == -1) {
        my_putstrerr(arg[0]);
        my_putstrerr(": Command not found.\n");
        return 0;
    }
    char **allpath = my_str_to_word_array2(getinfopwd(env, path), ':');
    for (int i = 0; allpath[i]; i++) {
        if (access(my_strcat(allpath[i], my_strcat("/", arg[0])), X_OK) == 0) {
            arg[0] = my_strcat("/", arg[0]);
            return execute_process(arg, env, allpath[i]);
        }
    }
    if (access(my_strcat("/", arg[0]), F_OK))
        return checkingexcute(arg, env);
    my_putstrerr(arg[0]);
    my_putstrerr(": Command not found.\n");
    return 1;
}

int terminal_main(char **word, systeme **sys)
{
    word = check_alias(word, sys);
    if (my_strcmp("exit", word[0])) {
        my_putstr("exit\n");
        order66(word);
        exit(0);
    }
    if (my_strcmp("setenv", word[0]))
        return setenv_b((*sys)->env, word);
    if (my_strcmp("unsetenv", word[0]))
        return unsetenv_b((*sys)->env, word);
    if (my_strcmp("env", word[0]))
        return my_putstrstr((*sys)->env);
    if (my_strcmp("cd", word[0]))
        return changedir(word, (*sys)->env);
    return terminal_main2(word, sys);
}

int main(int ac, char **av, char **env)
{
    systeme *sys = init_sys(env);
    if (isatty(0))
        sys->end = ttymode(&sys);
    else {
        while (getline(&sys->buffer, &sys->size, stdin) != -1) {
            sys->id = addhistory(&sys->his, sys->buffer, sys->id);
            sys->end = errorhandelingpipe(&sys);
        }
    }
    return sys->end;
}
