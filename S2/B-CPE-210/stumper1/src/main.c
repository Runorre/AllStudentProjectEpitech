/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "my.h"

int headmain(int fd)
{
    char *str = malloc(sizeof(char) * 3000000);
    int i = 0, j = 0;
    read(fd, str, 3000000);
    while (i != 10 && str[j] != '\0') {
        if (str[j] == '\n')
            i++;
        my_putchar(str[j]);
        j++;
    }
    free(str);
    close(fd);
    return 0;
}

int infiniteloop(void)
{
    char *str = malloc(sizeof(char) * 3000000);
    while (1) {
        write(1, str, read(0, str, 3000000));
    }
    free(str);
    return 0;
}

int checkiffileexiste(char *ar, int multi)
{
    int fd = open(ar, O_RDONLY);
    if (fd == -1)
        return print_error_nofile(ar);
    else {
        if (multi)
            printnamefile(ar);
        return headmain(fd);
    }
}

int main(int ac, char **ar)
{
    if (ac == 1)
        return infiniteloop();
    if (ac == 2)
        return checkiffileexiste(ar[1], 0);
    if (checkoptioncorrect(ac, ar))
        return 1;
    int i = 1;
    while (i != ac) {
        if (ar[i][0] == '-')
            i = i;
        else
            checkiffileexiste(ar[i], checker(ac, ar));
        i++;
    }
    return 0;
}
