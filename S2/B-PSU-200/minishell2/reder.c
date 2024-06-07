/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell2-angelo.anselmet
** File description:
** reder
*/

#include "my.h"

void reducstrstr(char **str, int stop)
{
    str[stop] = NULL;
    for (int i = stop + 1; str[i]; i++)
        free(str[i]);
}

char *goodpath(char *path)
{
    if (my_strstartwith("./", path) || my_strstartwith("/", path))
        return path;
    else if (!(my_strcmp("", path)))
        return my_strcat("./", path);
}

int opingfile(char *file, int append)
{
    int fd = 0;
    if (append) {
        fd = open(goodpath(file), O_WRONLY | O_APPEND | O_CREAT, 0666);
    } else {
        fd = open(goodpath(file), O_WRONLY | O_TRUNC | O_CREAT, 0666);
    }
    if (fd == -1) {
        printerror(file);
        return -1;
    }
    dup2(fd, 1);
    return fd;
}

int checkredirection(char **parsing)
{
    int fd = 0;
    for (int i = 0; parsing[i]; i++) {
        if ((my_strcmp(">", parsing[i]) || (my_strcmp(">>", parsing[i])))
        && parsing[i + 1] == NULL) {
            my_putstrerr("Missing name for redirect.\n");
            return -1;
        }
        if (my_strcmp(">", parsing[i]) && parsing[i + 1] != NULL) {
            fd = opingfile(parsing[i + 1], 0);
            reducstrstr(parsing, i);
            return fd;
        }
        if (my_strcmp(">>", parsing[i]) && parsing[i + 1] != NULL) {
            fd = opingfile(parsing[i + 1], 1);
            reducstrstr(parsing, i);
            return fd;
        }
    }
    return 0;
}

int checkmultycommand(char *buffer, char **env)
{
    int end = 0;
    char **multicommand = my_str_to_word_array2(buffer, ';');
    for (int i = 0; multicommand[i]; i++) {
        end = checkpipe(multicommand[i], env);
    }
    order66(multicommand);
    return end;
}
