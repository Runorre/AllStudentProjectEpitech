/*
** EPITECH PROJECT, 2023
** cesar
** File description:
** check arg
*/

#include "my.h"

int init_cesar(int ac, char **ar)
{
    if (my_strcmp(ar[1], "-f")) {
        FILE *fd = fopen(ar[2], "r");
        if (fd == NULL)
            return 84;
        remove("crypt");
        int cryptfd = open("crypt", O_WRONLY | O_CREAT | O_TRUNC, 0444);
        file_cesar(my_getnbr(ar[3]), fd, cryptfd);
        close(cryptfd);
        fclose(fd);
        return 0;
    } else {
        remove("crypt");
        int cryptfd = open("crypt", O_WRONLY | O_CREAT | O_TRUNC, 0444);
        str_line_cesar(my_getnbr(ar[3]), ar[2], cryptfd);
        close(cryptfd);
        return 0;
    }
}
