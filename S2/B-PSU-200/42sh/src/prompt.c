/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-42sh-theo.berget
** File description:
** prompt
*/

#include "sh.h"

void checkrepomodify(void)
{
    char *buffer = NULL;
    int modify = 0, unkown = 0;
    size_t size = 0;
    FILE *git = popen("git status --porcelain 2>/dev/null", "r");
    if (!git)
        return;
    int end = getline(&buffer, &size, git);
    if (end == -1)
        return;
    while (end != -1) {
        if (buffer[1] == 'M')
            modify = 1;
        if (buffer[1] == '?')
            unkown = 1;
        end = getline(&buffer, &size, git);
    }
    if (modify) printf("\033[1;31m*");
    if (unkown) printf("\033[1;31m?");
    pclose(git);
    free(buffer);
}

void checkgitrepo(void)
{
    char *buffer = NULL;
    size_t size = 0;
    FILE *git = popen("git rev-parse --is-inside-work-tree 2>/dev/null", "r");
    if (!git)
        return;
    int end = getline(&buffer, &size, git);
    if (end != -1) {
        pclose(git);
        git = popen("git rev-parse --abbrev-ref HEAD", "r");
        getline(&buffer, &size, git);
        buffer[my_strlen(buffer) - 1] = '\0';
        printf(" \033[1;35m(\033[1;32m%s", buffer);
        checkrepomodify();
        printf("\033[1;35m)");
        printf("\033[1;34m");
    }
    free(buffer);
    pclose(git);
}

void prompt(void)
{
    struct passwd *pw = getpwuid(getuid());
    char hostname[HOST_NAME_MAX + 1];
    gethostname(hostname, HOST_NAME_MAX + 1);
    printf("\033[1;32m");
    printf("%s@%s ", getlogin(), hostname);
    printf("\033[1;34m");
    if (my_strcmp(pw->pw_dir, getcwd(NULL, 0))) {
        printf("~ $ ");
        printf("\033[0m");
        return;
    }
    if (my_strstartwith(pw->pw_dir, getcwd(NULL, 0))) {
        char *path = getcwd(NULL, 0);
        printf("~/%s", &path[my_strlen(pw->pw_dir) + 1]);
    } else
        printf("%s", getcwd(NULL, 0));
    checkgitrepo();
    printf(" $ ");
    printf("\033[0m");
}
