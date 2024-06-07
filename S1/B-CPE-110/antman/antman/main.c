/*
** EPITECH PROJECT, 2023
** B-CPE-110-MAR-1-1-antman-angelo.anselmetq
** File description:
** main
*/

#include "my.h"

int checkerformat(char *file, char *format)
{
    int len = my_strlen(format) - 1, len2 = my_strlen(file) - 1;
    if (len2 < len)
        return 1;
    for (int i = 0; i != len + 1; i++) {
        if (file[len2 - i] != format[len - i])
            return 1;
    }
    return 0;
}

int whatformat(char *file, int format)
{
    if (format == 1)
        return checkerformat(file, ".lyr");
    if (format == 2)
        return checkerformat(file, ".html");
    if (format == 3)
        return checkerformat(file, ".ppm");
    return 1;
}

int main(int ac, char **ar)
{
    int fd = open(ar[1], O_RDONLY);
    int tf = my_getnbr(ar[2]);
    if (ac != 3)
        return 84;
    if (tf == -1)
        return 84;
    if (whatformat(ar[1], tf) == 1)
        return 84;
    if (fd == -1 || read(fd, "", 0) == -1)
        return 84;
    struct stat s;
    stat(ar[1], &s);
    char *file = malloc(sizeof(char) * s.st_size);
    read(fd, file, s.st_size);
    return 0;
}
