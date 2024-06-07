/*
** EPITECH PROJECT, 2022
** my cat
** File description:
** my cat
*/

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

void error(void)
{
    switch (errno) {
    case 2:
        write(2, "No such file or directory\n", 26);
        break;
    case 9:
        write(2, "Bad file number\n", 16);
        break;
    case 12:
        write(2, "Out of memory\n", 14);
        break;
    case 13:
        write(2, "Permission denied\n", 18);
        break;
    }
}

void loop_empty(void)
{
    int size;
    char buf[30000];
    while (1 == 1) {
        size = read(0, buf, 20);
        if (size == 0) {
            return;
        } else {
            write(1, buf, size);
        }
    }
}

int main(int ac, char **ar)
{
    if (ac == 1) {
        loop_empty();
        return (0);
    }
    char buf[30000];
    for (int i = 1; i != ac; i++) {
        int fd;
        errno = 0;
        fd = open(ar[i], O_RDONLY);
        if (errno > 0) {
            error();
        } else {
        write(1, buf, read(fd, buf, 30000));
        close(fd);
        }
    }
}
