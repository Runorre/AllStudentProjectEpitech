/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-angelo.anselmet
** File description:
** main
*/

#include "my.h"

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

int terminal_main(char **word, char **env)
{
    if (my_strcmp("exit", word[0])) {
        my_putstr("exit\n");
        order66(word);
        exit(0);
    }
    if (my_strcmp("setenv", word[0]))
        return setenv_b(env, word);
    if (my_strcmp("unsetenv", word[0]))
        return unsetenv_b(env, word);
    if (my_strcmp("env", word[0]))
        return my_putstrstr(env);
    if (my_strcmp("cd", word[0]))
        return changedir(word, env);
    if (my_strstartwith("./", word[0]) || my_strstartwith("/", word[0]))
        return checkingexcute(word, env);
    else if (!(my_strcmp("", word[0])))
        return command_existe(env, word);
    return 0;
}

int main(int ac, char **av, char **env)
{
    int end = 0;
    char *buffer = NULL;
    size_t size = 0;
    if (isatty(0)) {
        my_putstr("$>");
        signal(SIGINT, handler);
        while (getline(&buffer, &size, stdin) != -1) {
            end = errorhandelingpipe(buffer, env);
            my_putstr("$>");
        }
        my_putstr("exit\n");
    } else {
        while (getline(&buffer, &size, stdin) != -1)
            end = errorhandelingpipe(buffer, env);
    }
    free(buffer);
    return end;
}
