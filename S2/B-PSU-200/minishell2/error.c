/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-angelo.anselmet
** File description:
** error
*/

#include "my.h"

int printerror(char *word)
{
    write(2, word, my_strlen(word));
    write(2, ": ", 2);
    write(2, strerror(errno), my_strlen(strerror(errno)));
    if (errno == ENOEXEC)
        write(2, ". Wrong Architecture", 20);
    write(2, ".\n", 2);
    return 1;
}

int checkingexcute(char **word, char **env)
{
    if (access(word[0], F_OK) == -1) {
        my_putstrerr(word[0]);
        my_putstrerr(": Command not found.\n");
        return 1;
    }
    if (access(word[0], X_OK) == -1) {
        printerror(word[0]);
        return 1;
    } else {
        return execute_process(word, env, "");
    }
}

int conditioncsm(char **word)
{
    if (my_strstrlen(word) == 2 && checkalpha(word[1])) {
        return 1;
    }
    if (my_strstrlen(word) == 3) {
        if ((checkalpha(word[1])))
            return 1;
    }
    return 0;
}

int checkalpha(char *word)
{
    for (int i = 0; word[i] != '\0'; i++) {
        if (!((word[i] >= 'A' && word[i] <= 'Z') ||
        (word[i] >= 'a' && word[i] <= 'z') ||
        (word[i] >= '0' && word[i] <= '9'))) {
            return 1;
        }
    }
    return 0;
}
